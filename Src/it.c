/*
 * it.c
 *
 *  Created on: Apr 2, 2020
 *      Author: alexisaglar
 */
#include "main.h"

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
