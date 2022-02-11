/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : DIO                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

#define NO_ERROR 0
#define ERROR_WRONG_FUNCTION_ARGUMENTS 1
#define ERROR_NULL_POINTER 2


/*****************************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8Direction){
    u8 Local_u8ErrorState = NO_ERROR; 
    // valid pin number
    if (Copy_u8PinNumber <= DIO_u8PIN7){
        // input
        if(Copy_u8Direction == DIO_u8PIN_INPUT){ 

            switch (Copy_u8Port)
            {

            case DIO_u8PORTA: CLR_BIT(DDRA, Copy_u8PinNumber); break;
            case DIO_u8PORTB: CLR_BIT(DDRB, Copy_u8PinNumber); break;
            case DIO_u8PORTC: CLR_BIT(DDRC, Copy_u8PinNumber); break;
            case DIO_u8PORTD: CLR_BIT(DDRD, Copy_u8PinNumber); break;

            default: Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;        break;
            }

        }
        // output
        else if (Copy_u8Direction == DIO_u8PIN_OUTPUT){

            switch (Copy_u8Port)
            {

            case DIO_u8PORTA: SET_BIT(DDRA, Copy_u8PinNumber); break;
            case DIO_u8PORTB: SET_BIT(DDRB, Copy_u8PinNumber); break;
            case DIO_u8PORTC: SET_BIT(DDRC, Copy_u8PinNumber); break;
            case DIO_u8PORTD: SET_BIT(DDRD, Copy_u8PinNumber); break;

            default: Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;        break;
            }

        }
        // neither input nor output
        else {
            Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
        }
    }
    // not a valid pin number
    else{
        Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
    }

    return Local_u8ErrorState;
}

/*****************************************************************************/
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction){
    u8 Local_u8ErrorState = NO_ERROR; 
        switch (Copy_u8Port)
        {

        case DIO_u8PORTA : DDRA = Copy_u8Direction;     break;
        case DIO_u8PORTB : DDRB = Copy_u8Direction;     break; 
        case DIO_u8PORTC : DDRC = Copy_u8Direction;     break; 
        case DIO_u8PORTD : DDRD = Copy_u8Direction;     break; 

        default: Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;            break;
        }

    return Local_u8ErrorState;
}

/*****************************************************************************/
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

/*****************************************************************************/
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

/*****************************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 * Copy_pu8Value){
    u8 Local_u8ErrorState = NO_ERROR; 

    if (* Copy_pu8Value != NULL){

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
    }

    else{
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }

    return Local_u8ErrorState;
}