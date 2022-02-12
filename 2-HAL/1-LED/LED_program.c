/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : LED                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"
#include "DIO_interface.h"

u8 LED_u8TurnOn(u8 Copy_u8Port, u8 Copy_u8PinNumber,u8 Copy_Connection_Type){
    u8 Local_u8ErrorState = NO_ERROR;
    Local_u8ErrorState = DIO_u8SetPinDirection(Copy_u8Port, Copy_u8PinNumber, DIO_u8PIN_OUTPUT) ;
    switch (Copy_Connection_Type)
    {
        case LED_CONNECTION_SOURCE:
            Local_u8ErrorState = DIO_u8SetPinValue(Copy_u8Port, Copy_u8PinNumber, DIO_u8PIN_HIGH);
            break;
        case LED_CONNECTION_SINK:
            Local_u8ErrorState = DIO_u8SetPinValue(Copy_u8Port, Copy_u8PinNumber, DIO_u8PIN_LOW);
            break;
        default: Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;   break;
    }
    return Local_u8ErrorState;
}

u8 LED_u8TurnOFF(u8 Copy_u8Port, u8 Copy_u8PinNumber,u8 Copy_Connection_Type){
    u8 Local_u8ErrorState = NO_ERROR;
    Local_u8ErrorState = DIO_u8SetPinDirection(Copy_u8Port, Copy_u8PinNumber, DIO_u8PIN_OUTPUT) ;
    switch (Copy_Connection_Type)
    {
        case LED_CONNECTION_SOURCE:
            Local_u8ErrorState = DIO_u8SetPinValue(Copy_u8Port, Copy_u8PinNumber, DIO_u8PIN_LOW);
            break;
        case LED_CONNECTION_SINK:
            Local_u8ErrorState = DIO_u8SetPinValue(Copy_u8Port, Copy_u8PinNumber, DIO_u8PIN_HIGH);
            break;
        default: Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;   break;
    }
    return Local_u8ErrorState;
}
