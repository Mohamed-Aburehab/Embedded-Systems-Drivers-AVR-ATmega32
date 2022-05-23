/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : USART (Universal serial communication)  **********************/
/**********************    Version: 1.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define USART_ENABLE          1
#define USART_DISABLE         0

// data size modes :
#define USART_DATA_8BIT       1
#define USART_DATA_5BIT       2
#define USART_DATA_6BIT       3
#define USART_DATA_7BIT       4
#define USART_DATA_9BIT       5

#define UART_ASYNC            1  
#define USART_SYNC            2 

#define USART_PARITY_DISABLED           0
#define USART_PARITY_ENABLED_EVEN       1
#define USART_PARITY_ENABLED_ODD        2

#define  USART_1_STOP_BIT       1
#define  USART_2_STOP_BIT       2
#endif