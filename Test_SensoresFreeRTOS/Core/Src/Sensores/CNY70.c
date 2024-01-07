/*
 * CNY70.c
 *
 *  Created on: Dec 19, 2023
 *      Author: Alumno
 */
#include "CNY70.h"

uint32_t lecturaCNY70=0;
uint32_t flancosLeidosCNY70;
uint32_t rpmCNY70;
float windSpeed;

void CNY70_TIM_Callback(void)
{
	rpmCNY70= flancosLeidosCNY70; //Guardo el valor de las rpm en el ultimo minuto
	flancosLeidosCNY70= 0; //Reinicio el contador de flancos
}

void CNY70_FlancosUp(void)
{
	flancosLeidosCNY70++; //Cuento cada revolucion del sensor
}

float CNY70_MedicionVelocidad(uint32_t rpm)
{
	return ( PI * DIAMETRO_EJE * rpm ) * 3.6/60; //Velocidad en m/s
}
