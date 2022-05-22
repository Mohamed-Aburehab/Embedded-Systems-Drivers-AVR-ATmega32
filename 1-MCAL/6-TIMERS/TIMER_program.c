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
u8 TIMER0_voidInit(TIMER0_CONFIG *Copy_Timer0Config){
    u8 Local_u8ErrorState = NO_ERROR;
    /* Checking if the pointer is pointing to a valid address or not. */
    if (Copy_Timer0Config != NULL){
        // setting timer mode
        TCCR0 &= TIMER0_MODE_MASK;
        TCCR0 |= Copy_Timer0Config->MODE;

        // setting interrupt for compare match
        if (Copy_Timer0Config->COMPARE_MATCH_INTERRUPT_ENABLE == ENABLE){SET_BIT(TIMSK,TIMSK_OCIE0);}
        else{CLR_BIT(TIMSK,TIMSK_OCIE0);}

        // setting interrupt for overflow
        if (Copy_Timer0Config->OVERFLOW_INTERRUPT_ENABLE == ENABLE){SET_BIT(TIMSK,TIMSK_TOIE0);}
        else{CLR_BIT(TIMSK,TIMSK_TOIE0);}
        
        // setting OC0 pin mode
        TCCR0 &= TIMER0_OC0_MASK;
        TCCR0 |= Copy_Timer0Config->OC0_MODE;

        // setting clock sorce
        TCCR0 &= TIMER_CLOCK_MASK;
        TCCR0 |= Copy_Timer0Config->CLOCK;
    }
    else {
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    return Local_u8ErrorState;
}

void TIMER0_voidSetTimerValue(u8 Copy_u8Value){
    TCNT0= Copy_u8Value;
}

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value){
	OCR0= Copy_u8Value;
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

u8 TIMER0_u8SetCallBackFuncOnOverFlow(void (*Copy_pvCallBackFunk)(void)){
    /* A local variable that is used to return the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* Checking if the pointer is pointing to a valid address or not. */
    if (Copy_pvCallBackFunk != NULL){
        TIMER0_pvCallBackFuncOnOverFlow = Copy_pvCallBackFunk;
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

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
    if(TIMER0_pvCallBackFuncOnOverFlow != NULL){
        TIMER0_pvCallBackFuncOnOverFlow();
    }
}


/*********************/
//? TIMER1 Functions 
/*********************/
static void (*TIMER1_pvCallBackFuncOnCTC_A)(void) = NULL;
static void (*TIMER1_pvCallBackFuncOnCTC_B)(void) = NULL;
static void (*TIMER1_pvCallBackFuncOnOverFlow)(void) = NULL;
static void (*TIMER1_pvCallBackFuncOnInputCapture)(void) = NULL;

u8 TIMER1_voidInit(TIMER1_CONFIG *Copy_Timer1Config){   
    u8 Local_u8ErrorState = NO_ERROR;
    /* Checking if the pointer is pointing to a valid address or not. */
    if (Copy_Timer1Config != NULL){
        // setting timer mode
    	  u8 Local_u8First2BitsInMode = Copy_Timer1Config->MODE << 6;
    	  u8 Local_u8Second2BitsInMode = Copy_Timer1Config->MODE >> 2;
    	  TCCR1A &= 0b11111100;
		  TCCR1A |= (Local_u8First2BitsInMode >> 6);
		  TCCR1B &= 0b11100111;
		  TCCR1B |= (Local_u8Second2BitsInMode << 3);


        // setting interrupt for input capture 
        if (Copy_Timer1Config->INPUT_CAPTURE_INTERRUPT_ENABLE == ENABLE){SET_BIT(TIMSK,TIMSK_TICIE1);}
        else{CLR_BIT(TIMSK,TIMSK_TICIE1);}
        // setting interrupt for compare match A
        if (Copy_Timer1Config->COMPARE_MATCH_A_INTERRUPT_ENABLE == ENABLE){SET_BIT(TIMSK,TIMSK_OCIE1A);}
        else{CLR_BIT(TIMSK,TIMSK_OCIE1A);}
        // setting interrupt for compare match B
        if (Copy_Timer1Config->COMPARE_MATCH_B_INTERRUPT_ENABLE == ENABLE){SET_BIT(TIMSK,TIMSK_OCIE1B);}
        else{CLR_BIT(TIMSK,TIMSK_OCIE1B);}
        // setting interrupt for Timer Overflow
        if (Copy_Timer1Config->OVERFLOW_INTERRUPT_ENABLE == ENABLE){SET_BIT(TIMSK,TIMSK_TOIE1);}
        else{CLR_BIT(TIMSK,TIMSK_TOIE1);}
        // setting OC1A pin mode
        TCCR1A &= TIMER1_OC1A_MASK;
        TCCR1A |= Copy_Timer1Config->OC1A_MODE;
        // setting OC1B pin mode
        TCCR1A &= TIMER1_OC1B_MASK;
        TCCR1A |= Copy_Timer1Config->OC1B_MODE;
        // setting clock sorce
        TCCR1B &= TIMER_CLOCK_MASK;
        TCCR1B |= Copy_Timer1Config->CLOCK;
    }else {
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    return Local_u8ErrorState;
}

void TIMER1_voidSetTimerValue(u16 Copy_u8Value){
    TCNT1 = Copy_u8Value;
}
void TIMER1_voidSetTimerTopValue(u16 Copy_u16TopValue){
    ICR1 = Copy_u16TopValue;
}
void TIMER1_voidSetChannelACompMatchValue(u16 Copy_u16CompareMatchValue){
    OCR1A = Copy_u16CompareMatchValue;
}
void TIMER1_voidSetChannelBCompMatchValue(u16 Copy_u16CompareMatchValue){
    OCR1B = Copy_u16CompareMatchValue;
}

u8 TIMER1_u8SetCallBackFuncOnCTC_A(void (*Copy_pvCallBackFunk)(void)){
    /* A local variable that is used to return the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* Checking if the pointer is pointing to a valid address or not. */
    if (Copy_pvCallBackFunk != NULL){
        TIMER1_pvCallBackFuncOnCTC_A = Copy_pvCallBackFunk;
    }
    else{
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    /* Returning the error state of the function. */
    return Local_u8ErrorState;
}
u8 TIMER1_u8SetCallBackFuncOnCTC_B(void (*Copy_pvCallBackFunk)(void)){
    /* A local variable that is used to return the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* Checking if the pointer is pointing to a valid address or not. */
    if (Copy_pvCallBackFunk != NULL){
        TIMER1_pvCallBackFuncOnCTC_B = Copy_pvCallBackFunk;
    }
    else{
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    /* Returning the error state of the function. */
    return Local_u8ErrorState;

}
u8 TIMER1_u8SetCallBackFuncOnOverFlow(void (*Copy_pvCallBackFunk)(void)){
    /* A local variable that is used to return the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* Checking if the pointer is pointing to a valid address or not. */
    if (Copy_pvCallBackFunk != NULL){
        TIMER1_pvCallBackFuncOnOverFlow = Copy_pvCallBackFunk;
    }
    else{
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    /* Returning the error state of the function. */
    return Local_u8ErrorState;

}
u8 TIMER1_u8SetCallBackFuncInputCapture(void (*Copy_pvCallBackFunk)(void)){
    /* A local variable that is used to return the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* Checking if the pointer is pointing to a valid address or not. */
    if (Copy_pvCallBackFunk != NULL){
        TIMER1_pvCallBackFuncOnInputCapture = Copy_pvCallBackFunk;
    }
    else{
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    /* Returning the error state of the function. */
    return Local_u8ErrorState;

}

void __vector_7 (void) __attribute__((signal));
void __vector_7 (void){
    if(TIMER1_pvCallBackFuncOnCTC_A != NULL){
        TIMER1_pvCallBackFuncOnCTC_A();
    }
}

void __vector_8 (void) __attribute__((signal));
void __vector_8 (void){
    if(TIMER1_pvCallBackFuncOnCTC_B != NULL){
        TIMER1_pvCallBackFuncOnCTC_B();
    }
}
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void){
    if(TIMER1_pvCallBackFuncOnOverFlow != NULL){
        TIMER1_pvCallBackFuncOnOverFlow();
    }
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void){
    if(TIMER1_pvCallBackFuncOnInputCapture != NULL){
        TIMER1_pvCallBackFuncOnInputCapture();
    }
}
/*********************/
//? TIMER2 Functions 
/*********************/
static void (*TIMER2_pvCallBackFuncOnCTC)(void) = NULL;
static void (*TIMER2_pvCallBackFuncOnOverFlow)(void) = NULL;

u8 TIMER2_voidInit(TIMER2_CONFIG *Copy_Timer2Config){
    u8 Local_u8ErrorState = NO_ERROR;
    /* Checking if the pointer is pointing to a valid address or not. */
    if (Copy_Timer2Config != NULL){
        // setting timer mode
        TCCR2 &= TIMER2_MODE_MASK;
        TCCR2 |= Copy_Timer2Config->MODE;

        // setting interrupt for compare match
        if (Copy_Timer2Config->COMPARE_MATCH_INTERRUPT_ENABLE == ENABLE){SET_BIT(TIMSK,TIMSK_OCIE2);}
        else{CLR_BIT(TIMSK,TIMSK_OCIE2);}

        // setting interrupt for overflow
        if (Copy_Timer2Config->OVERFLOW_INTERRUPT_ENABLE == ENABLE){SET_BIT(TIMSK,TIMSK_TOIE2);}
        else{CLR_BIT(TIMSK,TIMSK_TOIE2);}
        
        // setting OC2 pin mode
        TCCR2 &= TIMER2_OC2_MASK;
        TCCR2 |= Copy_Timer2Config->OC2_MODE;

        // setting clock sorce
        TCCR2 &= TIMER_CLOCK_MASK;
        TCCR2 |= Copy_Timer2Config->CLOCK;
    }
    else {
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    return Local_u8ErrorState;

}

void TIMER2_voidSetTimerValue(u8 Copy_u8Value){
    TCNT2= Copy_u8Value;
}

void TIMER2_voidSetCompMatchValue(u8 Copy_u8Value){
    OCR2= Copy_u8Value;
}

u8 TIMER2_u8SetCallBackFuncOnCTC(void (*Copy_pvCallBackFunk)(void)){
    /* A local variable that is used to return the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* Checking if the pointer is pointing to a valid address or not. */
    if (Copy_pvCallBackFunk != NULL){
        TIMER2_pvCallBackFuncOnCTC = Copy_pvCallBackFunk;
    }
    else{
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    /* Returning the error state of the function. */
    return Local_u8ErrorState;

}

u8 TIMER2_u8SetCallBackFuncOnOverFlow(void (*Copy_pvCallBackFunk)(void)){
    /* A local variable that is used to return the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* Checking if the pointer is pointing to a valid address or not. */
    if (Copy_pvCallBackFunk != NULL){
        TIMER2_pvCallBackFuncOnOverFlow = Copy_pvCallBackFunk;
    }
    else{
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    /* Returning the error state of the function. */
    return Local_u8ErrorState;

}

void __vector_4 (void) __attribute__((signal));
void __vector_4 (void){
    if(TIMER2_pvCallBackFuncOnCTC != NULL){
        TIMER2_pvCallBackFuncOnCTC();
    }
}

void __vector_5 (void) __attribute__((signal));
void __vector_5 (void){
    if(TIMER2_pvCallBackFuncOnOverFlow != NULL){
        TIMER2_pvCallBackFuncOnOverFlow();
    }
}
void TIMER0_delay_us(u16 Copy_u8DelayTime){
	TIMER0_CONFIG CONFIG_STRUCT= {TIMER0_MODE_NORMAL, T0_PRESCALING_BY_8, OC0_NORMAL_OPERATION, DISABLE, DISABLE};
	TIMER0_voidInit(&CONFIG_STRUCT);
	TCNT0 = 0;
    OCR0 = 250;
	u16 Local_u8NumberOfReps = Copy_u8DelayTime/ 250;
    u16 Local_u8NumberOfOV = 0;
    while (Local_u8NumberOfOV < Local_u8NumberOfReps){
        if (GET_BIT(TIFR, TIMSK_OCF0) == 1){
            SET_BIT(TIFR, TIMSK_OCF0);
            TCNT0 = 0;
            Local_u8NumberOfOV ++;
        }
    }
	while (TCNT0 < (Copy_u8DelayTime - (Local_u8NumberOfReps * 250)) ){
	}
	CONFIG_STRUCT.CLOCK = T0_NO_CLOCK_SOURCE;
	TIMER0_voidInit(&CONFIG_STRUCT);
}
void TIMER0_delay_ms(u16 Copy_u8DelayTime){
	TIMER0_CONFIG CONFIG_STRUCT= {TIMER0_MODE_NORMAL, T0_PRESCALING_BY_256, OC0_NORMAL_OPERATION, DISABLE, DISABLE};
	TIMER0_voidInit(&CONFIG_STRUCT);
	TCNT0 = 0;
    OCR0 = 31;
	u16 Local_u8NumberOfReps = Copy_u8DelayTime ;
    u16 Local_u8NumberOfOV = 0;
    while (Local_u8NumberOfOV < Local_u8NumberOfReps){
        if (GET_BIT(TIFR, TIMSK_OCF0) == 1){
            SET_BIT(TIFR, TIMSK_OCF0);
            TCNT0 = 0;
            Local_u8NumberOfOV ++;
        }
    }

	CONFIG_STRUCT.CLOCK = T0_NO_CLOCK_SOURCE;
	TIMER0_voidInit(&CONFIG_STRUCT);
}
