/*
 * CNY70.h
 *
 *  Created on: Dec 19, 2023
 *      Author: Alumno
 */

#ifndef SRC_SENSORES_CNY70_H_
#define SRC_SENSORES_CNY70_H_

#include "main.h"

#define DIAMETRO_EJE 0.1 // En metros
#define PI 3.14

void CNY70_TIM_Callback(void);
void CNY70_FlancosUp(void);
float CNY70_MedicionVelocidad(uint32_t rpm);

#endif /* SRC_SENSORES_CNY70_H_ */
