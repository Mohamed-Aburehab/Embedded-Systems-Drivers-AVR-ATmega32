/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : USART (Universal serial communication)  **********************/
/**********************    Version: 2.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/**
 * @brief initializes the USART peripheral.
 */
void USART_voidInit(void);

/**
 * @brief It sends a character synchronously
 * 
 * @param Copy_u8Data The data to be sent.
 * 
 * @return the error state of the function.
 */
u8 USART_u8SendCharSynch(u8 Copy_u8Data);

/**
 * @brief It receives a character from the UART.
 * 
 * @param Copy_pu8ReceivedChar pointer to the variable that will store the received character.
 * 
 * @return the error state of the function.
 */
u8 USART_u8ReceiveCharSynch(u8 * Copy_pu8ReceivedChar);

/**
 * @brief It sends a string of characters to the USART peripheral
 * 
 * @param Copy_pcString A pointer to the string to be sent.
 * 
 * @return The error state of the function.
 */
u8 USART_u8SendStringSynch(char * Copy_pcString);

/**
 * @brief It receives a buffer of characters from the UART and stores them in the passed buffer
 * 
 * @param Buffer Pointer to the buffer that will store the received data.
 * @param Copy_u8BufferSize The size of the buffer that you want to receive.
 * 
 * @return the error state of the function.
 */
u8 USART_u8ReceiveBufferSynch(u8 * Buffer, u8 Copy_u8BufferSize);

/**
 * @brief It takes a character and a pointer to a function as arguments, and sends the character
 * asynchronously.
 * 
 * @param Copy_u8Data The data to be sent
 * @param Copy_PvNotificationFunc pointer to function that will be called when the interrupt is fired.
 * 
 * @return the error state of the function.
 */
u8 USART_u8SendCharAsynch(u8 Copy_u8Data, void(*Copy_PvNotificationFunc)(void));

/**
 * It takes a string and a pointer to a function and sends the string asynchronously
 * 
 * @param Copy_pcString pointer to the string to be sent
 * @param Copy_PvNotificationFunc is a pointer to a function that will be called when the string is
 * sent.
 * 
 * @return the error state of the function.
 */
u8 USART_u8SendStringAsynch(char * Copy_pcString, void(*Copy_PvNotificationFunc)(void));

/**
 * @brief It takes a pointer to a function and a pointer to a variable, and then it sets the global variable
 * to the value of the pointer to the variable, and then it calls the function that the pointer to the
 * function points to
 * 
 * @param Copy_pu8ReceivedChar pointer to the variable that will hold the received character
 * @param Copy_PvNotificationFunc is a pointer to a function that will be called when the interrupt is
 * triggered.
 * 
 * @return the error state of the function.
 */
u8 USART_u8ReceiveCharAsynch(u8 * Copy_pu8ReceivedChar ,void(*Copy_PvNotificationFunc)(void));

/**
 * It receives a buffer of data asynchronously and calls a callback function when the buffer is full
 * 
 * @param Buffer pointer to the buffer that will hold the received data
 * @param Copy_u8BufferSize The size of the buffer that will be received.
 * @param Copy_PvNotificationFunc is a pointer to a function that will be called when the buffer is
 * full.
 * 
 * @return the error state of the function.
 */
u8 USART_u8ReceiveBufferAsynch(u8 * Buffer, u8 Copy_u8BufferSize, void(*Copy_PvNotificationFunc)(void));

#endif
