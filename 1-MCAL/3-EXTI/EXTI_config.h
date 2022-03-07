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

// sense control states
#define LOW_LEVEL 0
#define LOGICAL_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

// for INT0 choose from (LOW_LEVEL, LOGICAL_CHANGE, FALLING_EDGE, RISING_EDGE)
#define EXTI_INT0_SENSE_CONTROL        FALLING_EDGE

// for INT1 choose from (LOW_LEVEL, LOGICAL_CHANGE, FALLING_EDGE, RISING_EDGE)
#define EXTI_INT1_SENSE_CONTROL        FALLING_EDGE

// for INT2 choose from (FALLING_EDGE, RISING_EDGE)
#define EXTI_INT2_SENSE_CONTROL        FALLING_EDGE

#endif
