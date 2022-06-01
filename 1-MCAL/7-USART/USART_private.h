/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : USART (Universal serial communication)  **********************/
/**********************    Version: 2.0                                     **********************/
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

/* USART busy state macros */
#define USART_BUSY_STATE_IDLE   1
#define USART_BUSY_STATE_BUSY   2

/* USART ISR source macros */
#define USART_ISR_SEND_CHAR_ASYNCH      1
#define USART_ISR_SEND_STRING_ASYNCH    2
#define USART_ISR_RECEIVE_CHAR_ASYNCH   3
#define ISART_ISR_RECEIVE_BUFFER_ASYNCH 4

#endif