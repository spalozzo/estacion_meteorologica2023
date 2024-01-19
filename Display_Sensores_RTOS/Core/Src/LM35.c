/*
 * LM35.c
 *
 *  Created on: Sep 28, 2023
 *      Author: axu_n
 */

float LM35_Read_Temperature(unsigned int Temp_ADC)
{
	return ((330.0 * Temp_ADC)/4095);
}
