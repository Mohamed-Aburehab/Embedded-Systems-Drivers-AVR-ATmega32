/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : MCAL                            **********************/
/**********************    SWD    : Timer                           **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*TIMER0_pvCallBackFunc)(void) = NULL;

void TIMER0_voidInit(void){
    // choose CTC mode 
    CLR_BIT(TCCR0, TCCR0_WGM00);
    SET_BIT(TCCR0, TCCR0_WGM00);
    
    // output compare match interrupt enable
    SET_BIT(TIMSK, TIMSK_OCIE0);

    // set compare match value to 250
    OCR0 = 250;

    // prescaller div by 8
    CLR_BIT(TCCR0, TCCR0_CS00);
    SET_BIT(TCCR0, TCCR0_CS01);
    CLR_BIT(TCCR0, TCCR0_CS02);
}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void)){
    u8 Local_u8ErrorState = NO_ERROR;
    if (Copy_pvCallBackFunc != NULL){
        TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
    }
    else{
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    return Local_u8ErrorState;
}


void __vector_10 (void) __attribute__((signal));
void __vector_10 (void){
    if(TIMER0_pvCallBackFunc != NULL){
        TIMER0_pvCallBackFunc();
    }
}