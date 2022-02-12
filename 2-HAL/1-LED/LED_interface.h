/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : LED                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

// error state
#define NO_ERROR 0
#define ERROR_WRONG_FUNCTION_ARGUMENTS 1
#define ERROR_NULL_POINTER 2

// connection type
#define LED_CONNECTION_SINK 0
#define LED_CONNECTION_SOURCE 1

u8 LED_u8TurnOn(u8 Copy_u8Port, u8 Copy_u8PinNumber,u8 Copy_Connection_Type);

u8 LED_u8TurnOFF(u8 Copy_u8Port, u8 Copy_u8PinNumber,u8 Copy_Connection_Type);

#endif