/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : MCAL                            **********************/
/**********************    SWD    : EXTI (external interrupts)      **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"

// GLOBAL pointer to function to hold INT0 ISR address
void (* EXTI_pvInt0Func)(void) = NULL;

// GLOBAL pointer to function to hold INT1 ISR address
void (* EXTI_pvInt1Func)(void) = NULL;

// GLOBAL pointer to function to hold INT2 ISR address
void (* EXTI_pvInt2Func)(void) = NULL;

/**
  * @brief  : PreBuild initialize for INT0 
  * @param  : void
  * @return : void
*/
void EXTI_voidInt0Init(void){
    #if     EXTI_INT0_SENSE_CONTROL == LOW_LEVEL
        // set sense control for INT0 on low level
        CLR_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);

    #elif   EXTI_INT0_SENSE_CONTROL == LOGICAL_CHANGE
        // set sense control for INT0 on a logical change
        SET_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);

    #elif   EXTI_INT0_SENSE_CONTROL == FALLING_EDGE
        // set sense control for INT0 on a falling edge
        CLR_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);

    #elif   EXTI_INT0_SENSE_CONTROL == RISING_EDGE
        // set sense control for INT0 on a rising edge
        SET_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);

    #else 
        #error "Wrong INT0_SENSE configuration option"
    #endif

    // Peripheral Interrupt State for INT0
    #if EXTI_INT0_INITIAL_STATE == ENABLED
        SET_BIT(GICR,GICR_INT0);
    
    #elif EXTI_INT0_INITIAL_STATE == DISABLED
        CLR_BIT(GICR,GICR_INT0);
    #else 
        #error "Wrong INT0_INITIAL STATE configuration option"
    #endif
}

/**
  * @brief  : PreBuild initialize for INT1
  * @param  : void
  * @return : void
*/
void EXTI_voidInt1Init(void){
    #if     EXTI_INT1_SENSE_CONTROL == LOW_LEVEL
        // set sense control for INT1 on low level
        CLR_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);

    #elif   EXTI_INT1_SENSE_CONTROL == LOGICAL_CHANGE
        // set sense control for INT1 on a logical change
        SET_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);

    #elif   EXTI_INT1_SENSE_CONTROL == FALLING_EDGE
        // set sense control for INT1 on a falling edge
        CLR_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);

    #elif   EXTI_INT1_SENSE_CONTROL == RISING_EDGE
        // set sense control for INT1 on a rising edge
        SET_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);

    #else 
        #error "Wrong INT1_SENSE configuration option"
    #endif

    // Peripheral Interrupt State for INT0
    #if EXTI_INT1_INITIAL_STATE == ENABLED
        SET_BIT(GICR,GICR_INT1);
    
    #elif EXTI_INT1_INITIAL_STATE == DISABLED
        CLR_BIT(GICR,GICR_INT1);
    #else 
        #error "Wrong INT1_INITIAL STATE configuration option"

    #endif
}

/**
  * @brief  : PreBuild initialize for INT2
  * @param  : void
  * @return : void
*/
void EXTI_voidInt2Init(void){
    #if     EXTI_INT2_SENSE_CONTROL == FALLING_EDGE
        // set sense control for INT2 on a falling edge
        CLR_BIT(MCUCSR, MCUCSR_ISC2);

    #elif   EXTI_INT2_SENSE_CONTROL == RISING_EDGE
        // set sense control for INT2 on a rising edge
        SET_BIT(MCUCSR, MCUCSR_ISC2);

    #else 
        #error "Wrong INT2_SENSE configuration option"
    #endif

    // Peripheral Interrupt State for INT0
    #if EXTI_INT2_INITIAL_STATE == ENABLED
        SET_BIT(GICR,GICR_INT2);
    
    #elif EXTI_INT2_INITIAL_STATE == DISABLED
        CLR_BIT(GICR,GICR_INT2);
    #else 
        #error "Wrong INT2_INITIAL STATE configuration option"

    #endif
}



/**
  * @brief  : post build initialize for INT0 sense controll 

  * @param  : sense controll option:    1 = LOW_LEVEL
                                        2 = LOGICAL_CHANGE
                                        3 = FALLING_EDGE
                                        4 = RISING_EDGE

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense){
    u8 Local_u8ErrorState = NO_ERROR;
    switch (Copy_u8Sense)
    {
    case LOW_LEVEL:
        CLR_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);
        break;
    case LOGICAL_CHANGE:
        SET_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);
        break;
    case FALLING_EDGE:
        CLR_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);
        break;
    case RISING_EDGE:
        SET_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);
        break;
    default:
        Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
        break;
    }
    return Local_u8ErrorState;
}

/**
  * @brief  : post build initialize for INT1 sense controll 

  * @param  : sense controll option:    1 = LOW_LEVEL
                                        2 = LOGICAL_CHANGE
                                        3 = FALLING_EDGE
                                        4 = RISING_EDGE

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense){
    u8 Local_u8ErrorState = NO_ERROR;
    switch (Copy_u8Sense)
    {
    case LOW_LEVEL:
        CLR_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);
        break;
    case LOGICAL_CHANGE:
        SET_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);
        break;
    case FALLING_EDGE:
        CLR_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);
        break;
    case RISING_EDGE:
        SET_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);
        break;
    default:
        Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
        break;
    }
    return Local_u8ErrorState;
}

/**
  * @brief  : post build initialize for INT2 sense controll 

  * @param  : sense controll option:    3 = FALLING_EDGE
                                        4 = RISING_EDGE

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense){
    u8 Local_u8ErrorState = NO_ERROR;
    switch (Copy_u8Sense)
    {
    case FALLING_EDGE:
        CLR_BIT(MCUCSR, MCUCSR_ISC2);
        break;
    case RISING_EDGE:
        SET_BIT(MCUCSR, MCUCSR_ISC2);
        break;
    default:
        Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
        break;
    }
    return Local_u8ErrorState;
}

/**
  * @brief  : make a Call Back for INT0 ISR 

  * @param  : Pointer to the INT0 ISR function

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void)){
    u8 Local_u8ErrorState = NO_ERROR;
    if(Copy_pvInt0Func != NULL){
        EXTI_pvInt0Func = Copy_pvInt0Func;
    }
    else {
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    return Local_u8ErrorState;

}
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
    if (EXTI_pvInt0Func != NULL){
        EXTI_pvInt0Func();
    }
}


/**
  * @brief  : make a Call Back for INT1 ISR 

  * @param  : Pointer to the INT0 ISR function

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void)){
    u8 Local_u8ErrorState = NO_ERROR;
    if(Copy_pvInt1Func != NULL){
        EXTI_pvInt1Func = Copy_pvInt1Func;
    }
    else {
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    return Local_u8ErrorState;

}
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
    if (EXTI_pvInt1Func != NULL){
        EXTI_pvInt1Func();
    }
}

/**
  * @brief  : make a Call Back for INT2 ISR 

  * @param  : Pointer to the INT0 ISR function

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void)){
    u8 Local_u8ErrorState = NO_ERROR;
    if(Copy_pvInt2Func != NULL){
        EXTI_pvInt2Func = Copy_pvInt2Func;
    }
    else {
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    return Local_u8ErrorState;

}
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
    if (EXTI_pvInt2Func != NULL){
        EXTI_pvInt2Func();
    }
}


u8 EXTI_u8DisableInterrupt(u8 Copy_INTERRUPT_ID){
    u8 Local_u8ErrorState = NO_ERROR;
    if (Copy_INTERRUPT_ID == INT0 || Copy_INTERRUPT_ID == INT1 || Copy_INTERRUPT_ID == INT2){
        CLR_BIT(GICR, Copy_INTERRUPT_ID);
    }
    else {
        Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
    }
    
    return Local_u8ErrorState;
}