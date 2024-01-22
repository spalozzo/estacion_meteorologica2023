/*
 * MQ135.c
 *
 *  Created on: Sep 18, 2023
 *      Author: santi
 */

#include "MQ135.h"

void MQ135_ConversionPPM(uint32_t cuentas, float* GasesDetectados)
{
	float Vout= 0;
	float Rs_R0= 0;

	Vout= ((float)cuentas*5) /4095;

	Rs_R0= MQ135_RL * ((5/Vout) - 1)/MQ135_R0;

	GasesDetectados[0]= SCA_CO2 * pow(Rs_R0, EXP_CO2); //Concentracion CO2
}

uint32_t MQ135_NivelContaminacion(uint32_t cuentas)
{
	return cuentas * 100/4095;
}
