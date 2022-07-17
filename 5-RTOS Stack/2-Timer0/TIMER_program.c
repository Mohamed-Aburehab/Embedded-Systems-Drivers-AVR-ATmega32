/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : RTOS Stack                      **********************/
/**********************    SWD    : Timer0                          **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

/*********************/
//? TIMER0 Functions 
/*********************/
static void (*TIMER0_pvCallBackFuncOnCTC)(void) = NULL;
static void (*TIMER0_pvCallBackFuncOnOverFlow)(void) = NULL;
/**
 * @brief   It takes a pointer to a structure of type TIMER0_CONFIG and sets the timer registers 
 *          according to the values in the structure.
 * 
 * @param   Copy_Timer0Config pointer to a structure of type TIMER0_CONFIG
 * 
 * @return  the error state of the function.
 */
u8 TIMER0_voidInit(){
    u8 Local_u8ErrorState = NO_ERROR;

    // setting timer mode
    TCCR0 &= TIMER0_MODE_MASK;
    TCCR0 |= TIMER0_MODE;

    // setting compare match value
    OCR0= TIMER0_CTC_VALUE;
    // setting interrupt for compare match
    SET_BIT(TIMSK,TIMSK_OCIE0);

    // setting OC0 pin mode
    TCCR0 &= TIMER0_OC0_MASK;
    TCCR0 |= TIMER0_PIN_MODE;

    // setting clock sorce
    TCCR0 &= TIMER_CLOCK_MASK;
    TCCR0 |= TIMER0_CLOCK;
    
    return Local_u8ErrorState;
}

u8 TIMER0_u8SetCallBackFuncOnCTC(void (*Copy_pvCallBackFunk)(void)){
    /* A local variable that is used to return the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* Checking if the pointer is pointing to a valid address or not. */
    if (Copy_pvCallBackFunk != NULL){
        TIMER0_pvCallBackFuncOnCTC = Copy_pvCallBackFunk;
    }
    else{
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    /* Returning the error state of the function. */
    return Local_u8ErrorState;
}


void __vector_10 (void) __attribute__((signal));
void __vector_10 (void){
    if(TIMER0_pvCallBackFuncOnCTC != NULL){
        TIMER0_pvCallBackFuncOnCTC();
    }
}


