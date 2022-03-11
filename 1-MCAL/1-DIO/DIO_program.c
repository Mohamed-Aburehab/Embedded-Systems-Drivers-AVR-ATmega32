/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : DIO                 **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

/**
  * @brief  : set pin value in a specific port 

  * @param  : Port name:                0 = DIO_u8PORTA
                                        1 = DIO_u8PORTB
                                        2 = DIO_u8PORTC
                                        3 = DIO_u8PORTD

  * @param  : pin name:                 0 = DIO_u8PIN0
                                        1 = DIO_u8PIN1
                                        2 = DIO_u8PIN2
                                        3 = DIO_u8PIN3
                                        4 = DIO_u8PIN4
                                        5 = DIO_u8PIN5
                                        6 = DIO_u8PIN6
                                        7 = DIO_u8PIN7

  * @param  : pin value:                0 = DIO_u8PIN_LOW
                                        1 = DIO_u8PIN_HIGH

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8Value){
    u8 Local_u8ErrorState = NO_ERROR; 
    
    // valid pin number
    if (Copy_u8PinNumber <= DIO_u8PIN7){
        // pin value low
        if (Copy_u8Value == DIO_u8PIN_LOW){
            switch (Copy_u8Port)
            {

            case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8PinNumber) ; break;
            case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8PinNumber) ; break;
            case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8PinNumber) ; break;
            case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8PinNumber) ; break;

            default: Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;        break;
            }
        }
        // pin value high
        else if (Copy_u8Value == DIO_u8PIN_HIGH){

            switch (Copy_u8Port)
            {

            case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8PinNumber) ; break;
            case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8PinNumber) ; break;
            case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8PinNumber) ; break;
            case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8PinNumber) ; break;

            default: Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;        break;
            }        
        }
    }
    
    // not a valid pin number
    else {
        Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
    }
    return Local_u8ErrorState;
}

/**
  * @brief  : set full port value 

  * @param  : Port name:                0 = DIO_u8PORTA
                                        1 = DIO_u8PORTB
                                        2 = DIO_u8PORTC
                                        3 = DIO_u8PORTD

  * @param  : port value:               0x00 = DIO_u8PORT_LOW
                                        0xFF = DIO_u8PORT_HIGH
                                        0xXX = for a specific port value 

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value){
    u8 Local_u8ErrorState = NO_ERROR; 

    switch (Copy_u8Port)
    {

    case DIO_u8PORTA : PORTA = Copy_u8Value ; break;
    case DIO_u8PORTB : PORTB = Copy_u8Value ; break;
    case DIO_u8PORTC : PORTC = Copy_u8Value ; break;
    case DIO_u8PORTD : PORTD = Copy_u8Value ; break;

    default: Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;        break;
    }  

    // HIGH value
    return Local_u8ErrorState;
}

/**
  * @brief  : get pin value 

  * @param  : Port name:                0 = DIO_u8PORTA
                                        1 = DIO_u8PORTB
                                        2 = DIO_u8PORTC
                                        3 = DIO_u8PORTD

  * @param  : pin name:                 0 = DIO_u8PIN0
                                        1 = DIO_u8PIN1
                                        2 = DIO_u8PIN2
                                        3 = DIO_u8PIN3
                                        4 = DIO_u8PIN4
                                        5 = DIO_u8PIN5
                                        6 = DIO_u8PIN6
                                        7 = DIO_u8PIN7

  * @param  : memmory address to the pin value in 

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 * Copy_pu8Value){
    u8 Local_u8ErrorState = NO_ERROR; 


	if (Copy_u8PinNumber <= DIO_u8PIN7){
		switch (Copy_u8Port){

		case DIO_u8PORTA : *Copy_pu8Value = GET_BIT(PINA,Copy_u8PinNumber) ; break;
		case DIO_u8PORTB : *Copy_pu8Value = GET_BIT(PINB,Copy_u8PinNumber) ; break;
		case DIO_u8PORTC : *Copy_pu8Value = GET_BIT(PINC,Copy_u8PinNumber) ; break;
		case DIO_u8PORTD : *Copy_pu8Value = GET_BIT(PIND,Copy_u8PinNumber) ; break;

		default: Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;        break;
		}
	}

	else {
		Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
	}

    return Local_u8ErrorState;
}