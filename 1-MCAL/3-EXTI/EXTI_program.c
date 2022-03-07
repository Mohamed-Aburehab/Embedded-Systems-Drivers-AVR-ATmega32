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

// INT0 Initialize
#if     EXTI_INT0_SENSE_CONTROL == LOW_LEVEL
    void EXTI_voidInt0Init(void){
        // set sense control for INT0 on low level
        CLR_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);

        // Peripheral Interrupt Enable for INT0
        SET_BIT(GICR,GICR_INT0);
    }

#elif   EXTI_INT0_SENSE_CONTROL == LOGICAL_CHANGE
    void EXTI_voidInt0Init(void){
        // set sense control for INT0 on a logical change
        SET_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);

        // Peripheral Interrupt Enable for INT0
        SET_BIT(GICR,GICR_INT0);
    }

#elif   EXTI_INT0_SENSE_CONTROL == FALLING_EDGE
    void EXTI_voidInt0Init(void){
        // set sense control for INT0 on a falling edge
        CLR_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);

        // Peripheral Interrupt Enable for INT0
        SET_BIT(GICR,GICR_INT0);
    }

#elif   EXTI_INT0_SENSE_CONTROL == RISING_EDGE
    void EXTI_voidInt0Init(void){
        // set sense control for INT0 on a rising edge
        SET_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);

        // Peripheral Interrupt Enable for INT0
        SET_BIT(GICR,GICR_INT0);
    }

#endif

// INT1 Initialize
#if     EXTI_INT1_SENSE_CONTROL == LOW_LEVEL
    void EXTI_voidInt1Init(void){
        // set sense control for INT1 on low level
        CLR_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);

        // Peripheral Interrupt Enable for INT1
        SET_BIT(GICR,GICR_INT1);
    }

#elif   EXTI_INT1_SENSE_CONTROL == LOGICAL_CHANGE
    void EXTI_voidInt1Init(void){
        // set sense control for INT1 on a logical change
        SET_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);

        // Peripheral Interrupt Enable for INT1
        SET_BIT(GICR,GICR_INT1);
    }

#elif   EXTI_INT1_SENSE_CONTROL == FALLING_EDGE
    void EXTI_voidInt1Init(void){
        // set sense control for INT1 on a falling edge
        CLR_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);

        // Peripheral Interrupt Enable for INT1
        SET_BIT(GICR,GICR_INT1);
    }

#elif   EXTI_INT1_SENSE_CONTROL == RISING_EDGE
    void EXTI_voidInt1Init(void){
        // set sense control for INT1 on a rising edge
        SET_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);

        // Peripheral Interrupt Enable for INT1
        SET_BIT(GICR,GICR_INT1);
    }

#endif

// INT2 Initialize
#if     EXTI_INT2_SENSE_CONTROL == FALLING_EDGE
    void EXTI_voidInt2Init(void){
        // set sense control for INT2 on a falling edge
        CLR_BIT(MCUCSR, MCUCSR_ISC2);

        // Peripheral Interrupt Enable for INT2
        SET_BIT(GICR,GICR_INT2);
    }

#elif   EXTI_INT2_SENSE_CONTROL == RISING_EDGE
    void EXTI_voidInt2Init(void){
        // set sense control for INT2 on a rising edge
        SET_BIT(MCUCSR, MCUCSR_ISC2);

        // Peripheral Interrupt Enable for INT2
        SET_BIT(GICR,GICR_INT2);
    }

#endif





