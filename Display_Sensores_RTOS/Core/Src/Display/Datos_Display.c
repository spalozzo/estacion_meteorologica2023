//----------------------------------------------------------------------//
//---------- Includes --------------------------------------------------//
//----------------------------------------------------------------------//

#include "Datos_Display.h"

#include "ssd1306.h"
#include "ssd1306_tests.h"

//#include "DHT22.h"

#include <string.h>
#include <stdio.h>

//----------------------------------------------------------------------//
//---------- Variables -------------------------------------------------//
//----------------------------------------------------------------------//

//extern ADC_HandleTypeDef hadc1;

extern RTC_HandleTypeDef hrtc;

extern uint8_t Flag_Scroll;

extern uint8_t Flag_Datos;

extern uint16_t Datos;

uint8_t Reinicio_Scroll;

uint8_t Cambio_Pantalla;

int16_t i = 25, j = 22;
int16_t iD = 83, jD = 79;

float Humedad = 0;

char Humedad_str[10];

typedef struct
{
	float Temperature;
	float Pressure;
	float Humidity;
	float Light;
	uint32_t AirQuality;
	float WindSpeed;
}SensedValues;

extern SensedValues MedicionesEstacion;

//----------------------------------------------------------------------//
//---------- Funciones -------------------------------------------------//
//----------------------------------------------------------------------//

void Mostrar_Temperatura()
{
	float Temperatura = MedicionesEstacion.Temperature;

	if (i <= -50 && j <= -50)
	{
		Cambio_Pantalla = 1;
	}

	if(!Cambio_Pantalla && iD <= 140 && jD <= 140)
	{
		ssd1306_SetCursor(i - 3, 20);

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString("Temp", Font_7x10, White);
		#endif

		ssd1306_SetCursor(j - 10, 35);

		sprintf(Humedad_str, "%.1f", Temperatura);

		ssd1306_WriteString(Humedad_str, Font_7x10, White);

		ssd1306_WriteChar(32, Font_7x10, White);

		Grados();

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString("C", Font_7x10, White);
		#endif
	}
}

void Mostrar_Humedad()
{
	//Humedad = 35.456;

	Humedad = MedicionesEstacion.Humidity;

	if(!Cambio_Pantalla)
	{
		ssd1306_SetCursor(iD, 20);

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString("Hum", Font_7x10, White);
		#endif

		ssd1306_SetCursor(jD - 3, 35);

		sprintf(Humedad_str, "%.1f", Humedad);

		ssd1306_WriteString(Humedad_str, Font_7x10, White);

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString(" %", Font_7x10, White);
		#endif
	}
}

uint16_t read;

void Mostrar_Presion()
{
	float Presion = 34.56;

	if (i <= -50 && j <= -50)
	{
		Cambio_Pantalla = 2;
	}

	if(Cambio_Pantalla == 1)
	{
		ssd1306_SetCursor(i + 2, 20);

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString("Pres", Font_7x10, White);
		#endif

		ssd1306_SetCursor(j - 9, 35);

		//Char_Display(Presion, 1);

		sprintf(Humedad_str, "%.1f", Presion);

		ssd1306_WriteString(Humedad_str, Font_7x10, White);

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString(" Atm", Font_7x10, White);
		#endif
	}
}

void Mostrar_Lux()
{
	float Lux = 30.34;

	if(Cambio_Pantalla == 1)
	{
		ssd1306_SetCursor(iD + 2, 20);

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString("Lux", Font_7x10, White);
		#endif

		ssd1306_SetCursor(jD - 4, 35);

		//Char_Display(Lux, 1);

		sprintf(Humedad_str, "%.1f", Lux);

		ssd1306_WriteString(Humedad_str, Font_7x10, White);

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString(" %", Font_7x10, White);
		#endif
	}
}

void Mostrar_Velocidad()
{
	float Velocidad = 30.45;

	if (i <= -50 && j <= -50)
	{
		Cambio_Pantalla = 0;
	}

	if(Cambio_Pantalla == 2)
	{
		ssd1306_SetCursor(i + 8, 20);

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString("Vel", Font_7x10, White);
		#endif

		ssd1306_SetCursor(j - 11, 35);

		sprintf(Humedad_str, "%.1f", Velocidad);

		ssd1306_WriteString(Humedad_str, Font_7x10, White);

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString(" km/h", Font_7x10, White);
		#endif
	}
}

void Mostrar_Calidad_Aire()
{
	float Calidad = 30.45;

	if(Cambio_Pantalla == 2)
	{
		ssd1306_SetCursor(iD + 3, 20);

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString("Aire", Font_7x10, White);
		#endif

		ssd1306_SetCursor(jD, 35);

		sprintf(Humedad_str, "%.1f", Calidad);

		ssd1306_WriteString(Humedad_str, Font_7x10, White);

		#ifdef SSD1306_INCLUDE_FONT_7x10
		ssd1306_WriteString(" %", Font_7x10, White);
		#endif
	}
}

void Mostrar_Tiempo(void)
{
	RTC_DateTypeDef gDate;
	RTC_TimeTypeDef gTime;

	HAL_RTC_GetTime(&hrtc, &gTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &gDate, RTC_FORMAT_BIN);

	ssd1306_SetCursor(35, 0);

	Char_Display(15 + gTime.Hours, 0);
	ssd1306_WriteString(":", Font_7x10, White);
	Char_Display(1 + gTime.Minutes, 1);
	ssd1306_WriteString(":", Font_7x10, White);
	Char_Display(gTime.Seconds, 1);

	ssd1306_SetCursor(28, 54);

	Char_Display(2023 + gDate.Year, 0);
	ssd1306_WriteString("/", Font_7x10, White);
	Char_Display(7 + gDate.Month, 1);
	ssd1306_WriteString("/", Font_7x10, White);
	Char_Display(29 + gDate.Date, 1);
}

void Char_Display(uint16_t dato, uint8_t Cero)
{
	uint8_t aux1 = 0, aux2 = 0, aux3 = 0, aux4 = 0;

	#ifdef SSD1306_INCLUDE_FONT_7x10

	if(dato >= 0 && dato < 10)
	{
		if (Cero)
			ssd1306_WriteChar(48, Font_7x10, White);
		ssd1306_WriteChar(dato + 48, Font_7x10, White);
	}
	else if(dato >= 10 && dato < 100)
	{
		aux1 = dato / 10;
		dato %= 10;

		ssd1306_WriteChar(aux1 + 48, Font_7x10, White);
		ssd1306_WriteChar(dato + 48, Font_7x10, White);
	}
	else if(dato >= 100 && dato < 1000)
	{
		aux1 = dato % 10;
		aux2 = dato / 10;
		aux3 = aux2 / 10;
		aux2 %= 10;

		ssd1306_WriteChar(aux3 + 48, Font_7x10, White);
		ssd1306_WriteChar(aux2 + 48, Font_7x10, White);
		ssd1306_WriteChar(aux1 + 48, Font_7x10, White);
	}
	else if(dato >= 1000 && dato < 10000)
	{
		aux1 = dato % 10;
		aux2 = dato / 10;
		aux3 = aux2 / 10;
		aux2 %= 10;
		aux4 = aux3 / 10;
		aux3 %= 10;

		ssd1306_WriteChar(aux4 + 48, Font_7x10, White);
		ssd1306_WriteChar(aux3 + 48, Font_7x10, White);
		ssd1306_WriteChar(aux2 + 48, Font_7x10, White);
		ssd1306_WriteChar(aux1 + 48, Font_7x10, White);
	}

	#endif
}

void Char_Display_Black(uint16_t dato, uint8_t Cero)
{
	uint8_t aux1 = 0, aux2 = 0, aux3 = 0, aux4 = 0;

	#ifdef SSD1306_INCLUDE_FONT_6x8

	if(dato >= 0 && dato < 10)
	{
		if (Cero)
			ssd1306_WriteChar(48, Font_6x8, Black);
		ssd1306_WriteChar(dato + 48, Font_6x8, Black);
	}
	else if(dato >= 10 && dato < 100)
	{
		aux1 = dato / 10;
		dato %= 10;

		ssd1306_WriteChar(aux1 + 48, Font_6x8, Black);
		ssd1306_WriteChar(dato + 48, Font_6x8, Black);
	}
	else if(dato >= 100 && dato < 1000)
	{
		aux1 = dato % 10;
		aux2 = dato / 10;
		aux3 = aux2 / 10;
		aux2 %= 10;

		ssd1306_WriteChar(aux3 + 48, Font_6x8, Black);
		ssd1306_WriteChar(aux2 + 48, Font_6x8, Black);
		ssd1306_WriteChar(aux1 + 48, Font_6x8, Black);
	}
	else if(dato >= 1000 && dato < 10000)
	{
		aux1 = dato % 10;
		aux2 = dato / 10;
		aux3 = aux2 / 10;
		aux2 %= 10;
		aux4 = aux3 / 10;
		aux3 %= 10;

		ssd1306_WriteChar(aux4 + 48, Font_6x8, Black);
		ssd1306_WriteChar(aux3 + 48, Font_6x8, Black);
		ssd1306_WriteChar(aux2 + 48, Font_6x8, Black);
		ssd1306_WriteChar(aux1 + 48, Font_6x8, Black);
	}

	#endif
}

void Scroll(uint8_t Cambio_Datos, uint8_t Posicion_X, uint8_t Posicion_Y)
{
	if (Flag_Datos && Flag_Scroll && Cambio_Pantalla == Cambio_Datos)
	{
		Flag_Scroll = 0;

			i--;
			j--;

			iD++;
			jD++;
	}

	if (Cambio_Pantalla == Cambio_Datos)
	{
		if(i < Posicion_X && j < Posicion_Y && Reinicio_Scroll == Cambio_Datos)
		{
			i++;
			j++;

			iD--;
			jD--;

			Flag_Datos = 0;
		}
		else if(Reinicio_Scroll == Cambio_Datos)
		{
			Datos = 3000;
			if(Cambio_Datos == 2)
			{
				Reinicio_Scroll = 0;
			}
			else
			{
				Reinicio_Scroll = Cambio_Datos + 1;
			}

		}
	}
}

void Scroll2(uint8_t Cambio_Datos, uint8_t Posicion_X, uint8_t Posicion_Y)
{
	if (Flag_Datos && Flag_Scroll && Cambio_Pantalla == Cambio_Datos)
	{
		Flag_Scroll = 0;

		i++;
		j++;

		iD++;
		jD++;
	}

	if (Cambio_Pantalla == Cambio_Datos)
	{
		if(i < Posicion_X && j < Posicion_Y && Reinicio_Scroll == Cambio_Datos)
		{
			i++;
			j++;

			iD++;
			jD++;

			Flag_Datos = 0;
		}
		else if(Reinicio_Scroll == Cambio_Datos)
		{
			Datos = 3000;
			if(Cambio_Datos == 2)
			{
				Reinicio_Scroll = 0;
			}
			else
			{
				Reinicio_Scroll = Cambio_Datos + 1;
			}

		}
	}
}


void Mostrar_Datos()
{
	ssd1306_Fill(Black);

	Scroll(0, 25, 17);

	Mostrar_Tiempo();
	Mostrar_Temperatura();
	Mostrar_Humedad();

	Scroll(1, 25, 17);

	Mostrar_Tiempo();
	Mostrar_Presion();
	Mostrar_Lux();

	Scroll(2, 25, 17);

	Mostrar_Tiempo();
	Mostrar_Velocidad();
	Mostrar_Calidad_Aire();

	Battery_100();
	Wifi_On();

	ssd1306_UpdateScreen();
}

//----------------------------------------------------------------------//
//---------- Fin -------------------------------------------------------//
//----------------------------------------------------------------------//
