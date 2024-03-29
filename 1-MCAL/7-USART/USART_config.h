/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : USART (Universal serial communication)  **********************/
/**********************    Version: 2.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_
// setup your clock speed in FOSC
#define FOSC            8000000

#define USART_BAUD_RATE 9600

// choose RX mode (USART_ENABLE , USART_DISABLE)
#define USART_RX_MODE   USART_ENABLE     

// choose TX mode (USART_ENABLE , USART_DISABLE)
#define USART_TX_MODE   USART_ENABLE

// enable next option to double the baud rate speed
#define USART_2X_MODE		USART_DISABLE

/* choose data size between :       1- USART_DATA_8BIT
                                    2- USART_DATA_5BIT
                                    3- USART_DATA_6BIT
                                    4- USART_DATA_7BIT
                                    5- USART_DATA_9BIT

*/
#define USART_DATA_SIZE        USART_DATA_8BIT

/* choose mode between :            1- UART_ASYNC
                                    2- USART_SYNC

*/
#define USART_MODE             UART_ASYNC

/* choose Parity mode between :     1- USART_PARITY_DISABLED
                                    2- USART_PARITY_ENABLED_EVEN
                                    3- USART_PARITY_ENABLED_ODD
*/
#define USART_PARITY_MODE           USART_PARITY_DISABLED

/* choose stop bit size between :   1- USART_1_STOP_BIT
                                    2- USART_2_STOP_BIT
*/
#define USART_STOP_BIT_SIZE         USART_1_STOP_BIT

#define USART_TIMEOUT 100000
#endif
