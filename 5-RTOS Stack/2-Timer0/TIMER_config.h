/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : RTOS Stack                      **********************/
/**********************    SWD    : Timer0                          **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/* 
                    TIMER0 MODES:  
TIMER0_MODE_NORMAL                      0b00000000
TIMER0_MODE_PHASE_CORRECT_PWM           0b00001000
TIMER0_MODE_CTC                         0b01000000
TIMER0_MODE_FAST_PWM                    0b01001000
*/
#define TIMER0_MODE                     0b01000000



/* 
                    TIMER0 CLOCKS:  
T0_NO_CLOCK_SOURCE                      0b00000000
T0_NO_PRESCALING                        0b00000001
T0_PRESCALING_BY_8                      0b00000010
T0_PRESCALING_BY_64                     0b00000011
T0_PRESCALING_BY_256                    0b00000100
T0_PRESCALING_BY_1024                   0b00000101
T0_EXTERNAL_CLOCK_SOURCE_FALLING        0b00000110
T0_EXTERNAL_CLOCK_SOURCE_RISING         0b00000111
*/
#define TIMER0_CLOCK                       0b00000011

/* 
                    OC0 PIN MODES: 
OC0_NORMAL_OPERATION                    0b00000000
OC0 NON PWM MODES :
OC0_TOGGLE_ON_COMPARE_MATCH             0b00010000
OC0_CLEAR_ON_COMPARE_MATCH              0b00100000
OC0_SET_ON_COMPARE_MATCH                0b00110000
OC0 FAST PWM MODES :
OC0_PWM_NON_INVERTING_MODE              0b00100000
OC0_PWM_INVERTING_MODE                  0b00110000
OC0 PHASE CORRECT PWM MODES :
OC0_PWM_CLEAR_ON_CTC_UP_COUNTING        0b00100000
OC0_PWM_SET_ON_CTC_UP_COUNTING          0b00110000
*/
#define TIMER0_PIN_MODE                    0b00000000


#define TIMER0_CTC_VALUE                125
#endif