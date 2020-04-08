/*
 * main.c
 *
 *  Created on: Apr 2, 2020
 *      Author: alexisaglar
 */

#include <string.h>
#include "main.h"
#include "stm32f4xx_hal.h"

#define TRUE 1
#define FALSE 0

void UART2_Init(void);
void Error_handler(void);
UART_HandleTypeDef huart2;


char msg[100];

int main(void)
{
	//USE HSE AS SYSTEMCLOCK ****BY DEFAULT HSI IS USED, SO HAS TO BE CONFIGURED
	RCC_OscInitTypeDef osc_init;
	RCC_ClkInitTypeDef clk_init;

	HAL_Init();

	UART2_Init();

	while(1);

	return 0;
}


void UART2_Init(void){
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE ;
	huart2.Init.Mode = UART_MODE_TX_RX;
	if(HAL_UART_Init(&huart2) != HAL_OK){
		//there is a problem
		Error_handler();
	}

}


void Error_handler(void){
	while(1);
}
