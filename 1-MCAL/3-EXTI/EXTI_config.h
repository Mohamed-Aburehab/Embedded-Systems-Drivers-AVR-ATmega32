/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : MCAL                            **********************/
/**********************    SWD    : EXTI (external interrupts)      **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*
For INT0:
        SENSE CONTROL options :
                                1 - LOW_LEVEL
                                2 - LOGICAL_CHANGE
                                3 - FALLING_EDGE
                                4 - RISING_EDGE
        INITIAL STATE options :
                                1 - ENABLED
                                2 - DISABLED
*/
#define EXTI_INT0_SENSE_CONTROL        FALLING_EDGE
#define EXTI_INT0_INITIAL_STATE        ENABLED
/********************************************************/


/*
For INT1:
        SENSE CONTROL options :
                                1 - LOW_LEVEL
                                2 - LOGICAL_CHANGE
                                3 - FALLING_EDGE
                                4 - RISING_EDGE
        INITIAL STATE options :
                                1 - ENABLED
                                2 - DISABLED
*/
#define EXTI_INT1_SENSE_CONTROL        FALLING_EDGE
#define EXTI_INT1_INITIAL_STATE        ENABLED
/********************************************************/

/*
For INT2:
        SENSE CONTROL options :
                                3 - FALLING_EDGE
                                4 - RISING_EDGE
        INITIAL STATE options :
                                1 - ENABLED
                                2 - DISABLED
*/
#define EXTI_INT2_SENSE_CONTROL        FALLING_EDGE
#define EXTI_INT2_INITIAL_STATE        ENABLED

#endif
