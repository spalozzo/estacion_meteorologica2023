/*
 * MQ135.h
 *
 *  Created on: Sep 18, 2023
 *      Author: santi
 */

#ifndef INC_MQ135_H_
#define INC_MQ135_H_

#include "main.h"

#define MQ135_RL 1000
#define MQ135_R0 73
#define SCA_CO2 116.6020682
#define EXP_CO2 -2.769034857

void MQ135_ConversionPPM(uint32_t cuentas, float* GasesDetectados);
uint32_t MQ135_NivelContaminacion(uint32_t cuentas);

#endif /* INC_MQ135_H_ */
