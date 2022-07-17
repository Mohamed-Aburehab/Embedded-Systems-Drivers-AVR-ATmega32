/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : RTOS Stack                      **********************/
/**********************    SWD    : Timer0                          **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


/**
 * @brief   It sets the timer registers according to the values in the config file.
 * 
 * @return  the error state of the function.
 */
u8 TIMER0_voidInit();

u8 TIMER0_u8SetCallBackFuncOnCTC(void (*Copy_pvCallBackFunkCTC)(void));

#endif
