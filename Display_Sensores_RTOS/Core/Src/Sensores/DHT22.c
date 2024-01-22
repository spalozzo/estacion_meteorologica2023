//----------------------------------------------------------------------//
//---------- Includes --------------------------------------------------//
//----------------------------------------------------------------------//

#include "DHT22.h"

//----------------------------------------------------------------------//
//---------- Variables -------------------------------------------------//
//----------------------------------------------------------------------//

// -- TIM_IC --

uint8_t iindex;
uint8_t capture;
uint8_t firstCapture;
uint8_t secondCapture;
uint8_t pulseTime;
uint8_t enableCapture;

uint8_t timeArray[100];

// -- TIM --

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

// -- TIM_MEDICION --

uint32_t start = 0;

// -- Resultado --

uint8_t Rh_byte1, Rh_byte2;
uint16_t RH;

//----------------------------------------------------------------------//
//---------- Funciones -------------------------------------------------//
//----------------------------------------------------------------------//

void Set_Pin_Output (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void Set_Pin_Input (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void delay (uint16_t time)
{
	/* change your code here for the delay in microseconds */

	__HAL_TIM_SET_COUNTER(&htim2, 0);
	while ((__HAL_TIM_GET_COUNTER(&htim2))<time);
}


void DHT22_Start_V2 (void)
{
	Set_Pin_Output(DHT22_GPIO_Port, DHT22_Pin); // set the pin as output
	HAL_GPIO_WritePin (DHT22_GPIO_Port, DHT22_Pin, 0);   // pull the pin low
	vTaskDelay(pdMS_TO_TICKS(2));

	HAL_GPIO_WritePin (DHT22_GPIO_Port, DHT22_Pin, 1);   // pull the pin high

	HAL_TIM_Base_Start(&htim2);
	delay (1);   // wait for 30us
	HAL_TIM_Base_Stop(&htim2);

	//Set_Pin_Input(DHT22_GPIO_Port, DHT22_Pin);

	enableCapture = 1;

	HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
}

//-------------------------------------------//
// Intento de implementacion no bloqueante
//-------------------------------------------//

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	//Sensor de viento
	CNY70_FlancosUp();

	//DHT22
	if (enableCapture && iindex <= 82)
	{
		capture = __HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_1); // canal y handler de timer.

		if (firstCapture == 0)
			firstCapture = capture;
		else
		{
			secondCapture = capture;

			if(secondCapture > firstCapture)
				pulseTime = secondCapture - firstCapture;
			else
				pulseTime = __HAL_TIM_GET_AUTORELOAD(&htim3) + secondCapture - firstCapture;

			firstCapture = secondCapture;
			timeArray[iindex] = pulseTime;
			if(timeArray[0] > 70 && timeArray[0] < 90)
				iindex++;
			else
				iindex = 0;
		}
	}
}

void DHT22_Recieve(float *Humidity)
{
	static uint8_t j = 0;

	if(timeArray[0] > 70 && timeArray[0] < 90)
	{
		if(timeArray[1] > 70 && timeArray[1] < 90)
		{
			for(uint8_t i = 2; i <= 17; i += 2)
			{
				if(timeArray[i] > 40 && timeArray[i] < 60)
				{
					if(timeArray[i + 1] > 25 && timeArray[i + 1] < 29)
					{
						Rh_byte1 &= ~(1<<(7 - j));   // write 0
					}
					else if(timeArray[i + 1] > 60 && timeArray[i + 1] < 80)
					{
						Rh_byte1 |= (1<<(7 - j));
					}
				}

				j++;
			}

			j = 0;

			for(uint8_t i = 18; i <= 33; i += 2)
			{
				if(timeArray[i] > 40 && timeArray[i] < 60)
				{
					if(timeArray[i + 1] > 25 && timeArray[i + 1] < 29)
					{
						Rh_byte2 &= ~(1<<(7 - j));   // write 0
					}
					else if(timeArray[i + 1] > 60 && timeArray[i + 1] < 80)
					{
						Rh_byte2 |= (1<<(7 - j));
					}
				}

				j++;
			}

			j = 0;

		}
	}

	if((timeArray[0] > 70 && timeArray[0] < 90) || (timeArray[1] < 70 && timeArray[1] > 90))
	{
		for(uint8_t i = 1; i <= 16; i += 2)
		{
			if(timeArray[i] > 40 && timeArray[i] < 60)
			{
				if(timeArray[i + 1] > 25 && timeArray[i + 1] < 29)
				{
					Rh_byte1 &= ~(1<<(7 - j));   // write 0
				}
				else if(timeArray[i + 1] > 60 && timeArray[i + 1] < 80)
				{
					Rh_byte1 |= (1<<(7 - j));
				}
			}

			j++;
		}

		j = 0;

		for(uint8_t i = 17; i <= 32; i += 2)
		{
			if(timeArray[i] > 40 && timeArray[i] < 60)
			{
				if(timeArray[i + 1] > 25 && timeArray[i + 1] < 29)
				{
					Rh_byte2 &= ~(1<<(7 - j));   // write 0
				}
				else if(timeArray[i + 1] > 60 && timeArray[i + 1] < 80)
				{
					Rh_byte2 |= (1<<(7 - j));
				}
			}

			j++;
		}

		j = 0;
	}

	RH = ((Rh_byte1<<8)|Rh_byte2);
	*Humidity = (float) (RH/10.0);
}

void DHT22_Read_Humidity (float *Humidity)
{
	if(iindex > 80)
	{
		DHT22_Recieve(Humidity);				// Funcion para procesar los datos obtenidos provenientes de la callback

		HAL_TIM_IC_Stop_IT(&htim3, TIM_CHANNEL_1);

		enableCapture = 0;

		iindex = 0;

		memset(timeArray,0x00,100);

		start = 0;
	}

	vTaskDelay(2000);

	Set_Pin_Output(DHT22_GPIO_Port, DHT22_Pin);

	HAL_TIM_Base_Start_IT(&htim4);

}

//----------------------------------------------------------------------//
//---------- Fin -------------------------------------------------------//
//----------------------------------------------------------------------//

