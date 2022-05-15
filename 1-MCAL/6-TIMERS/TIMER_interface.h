/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : MCAL                            **********************/
/**********************    SWD    : Timer                           **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define DISABLE                             0
#define ENABLE                              1

/*********************/
//? TIMER0 Interface 
/*********************/
// TIMER0 MODES: 
#define TIMER0_MODE_NORMAL                      0b00000000
#define TIMER0_MODE_PHASE_CORRECT_PWM           0b00001000
#define TIMER0_MODE_CTC                         0b01000000
#define TIMER0_MODE_FAST_PWM                    0b01001000

// TIMER0 CLOCKS: 
#define T0_NO_CLOCK_SOURCE                      0b00000000
#define T0_NO_PRESCALING                        0b00000001
#define T0_PRESCALING_BY_8                      0b00000010
#define T0_PRESCALING_BY_64                     0b00000011
#define T0_PRESCALING_BY_256                    0b00000100
#define T0_PRESCALING_BY_1024                   0b00000101
#define T0_EXTERNAL_CLOCK_SOURCE_FALLING        0b00000110
#define T0_EXTERNAL_CLOCK_SOURCE_RISING         0b00000111

// OC0 PIN MODES:
#define OC0_NORMAL_OPERATION                    0b00000000
// OC0 NON PWM MODES
#define OC0_TOGGLE_ON_COMPARE_MATCH             0b00010000
#define OC0_CLEAR_ON_COMPARE_MATCH              0b00100000
#define OC0_SET_ON_COMPARE_MATCH                0b00110000
// OC0 FAST PWM MODES
#define OC0_PWM_NON_INVERTING_MODE              0b00100000
#define OC0_PWM_INVERTING_MODE                  0b00110000
// OC0 PHASE CORRECT PWM MODES
#define OC0_PWM_CLEAR_ON_CTC_UP_COUNTING        0b00100000
#define OC0_PWM_SET_ON_CTC_UP_COUNTING          0b00110000

typedef struct 
{
    u8 MODE;
    u8 CLOCK;
    u8 OC0_MODE;
    u8 COMPARE_MATCH_INTERRUPT_ENABLE;
    u8 OVERFLOW_INTERRUPT_ENABLE;
} TIMER0_CONFIG;

/**
 * @brief   It takes a pointer to a structure of type TIMER0_CONFIG and sets the timer registers 
 *          according to the values in the structure.
 * 
 * @param   Copy_Timer0Config pointer to a structure of type TIMER0_CONFIG
 * 
 * @return  the error state of the function.
 */
u8 TIMER0_voidInit(TIMER0_CONFIG *Copy_Timer0Config);
void TIMER0_voidSetTimerValue(u8 Copy_u8Value);
void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);
u8 TIMER0_u8SetCallBackFuncOnCTC(void (*Copy_pvCallBackFunkCTC)(void));
u8 TIMER0_u8SetCallBackFuncOnOverFlow(void (*Copy_pvCallBackFunkOverFlow)(void));

/*********************/
//? TIMER1 Interface 
/*********************/
// TIMER1 MODES: 
#define TIMER1_MODE_NORMAL                                      0x00
#define TIMER1_MODE_PHASE_CORRECT_PWM_8BIT                      0x01
#define TIMER1_MODE_PHASE_CORRECT_PWM_9BIT                      0x02
#define TIMER1_MODE_PHASE_CORRECT_PWM_10BIT                     0x03

#define TIMER1_MODE_CTC                                         0x04
#define TIMER1_MODE_FAST_PWM_8BIT                               0x05
#define TIMER1_MODE_FAST_PWM_9BIT                               0x06
#define TIMER1_MODE_FAST_PWM_10BIT                              0x07

#define TIMER1_MODE_PHASE_FREQUENCY_CORRECT_PWM_ICR1            0x08
#define TIMER1_MODE_PHASE_FREQUENCY_CORRECT_PWM_OCR1A           0x09
#define TIMER1_MODE_PHASE_CORRECT_PWM_ICR1                      0x0A
#define TIMER1_MODE_PHASE_CORRECT_PWM_OCR1A                     0x0B

#define TIMER1_MODE_CTC_ICR1                                    0x0C

#define TIMER1_MODE_FAST_PWM_ICR1                               0x0E
#define TIMER1_MODE_FAST_PWM_OCR1A                              0x0F

// TIMER1 CLOCKS:
#define T1_NO_CLOCK_SOURCE                      0b00000000
#define T1_NO_PRESCALING                        0b00000001
#define T1_PRESCALING_BY_8                      0b00000010
#define T1_PRESCALING_BY_64                     0b00000011
#define T1_PRESCALING_BY_256                    0b00000100
#define T1_PRESCALING_BY_1024                   0b00000101
#define T1_EXTERNAL_CLOCK_SOURCE_FALLING        0b00000110
#define T1_EXTERNAL_CLOCK_SOURCE_RISING         0b00000111

// OC1A PIN MODES:
#define OC1A_NORMAL_OPERATION                    0b00000000
// OC1A NON PWM MODES
#define OC1A_TOGGLE_ON_COMPARE_MATCH             0b01000000
#define OC1A_CLEAR_ON_COMPARE_MATCH              0b10000000
#define OC1A_SET_ON_COMPARE_MATCH                0b11000000
// OC1A FAST PWM MODES
#define OC1A_PWM_NON_INVERTING_MODE              0b10000000
#define OC1A_PWM_INVERTING_MODE                  0b11000000
// OC1A PHASE CORRECT PWM MODES
#define OC1A_PWM_CLEAR_ON_CTC_UP_COUNTING        0b10000000
#define OC1A_PWM_SET_ON_CTC_UP_COUNTING          0b11000000


// OC1B PIN MODES:
#define OC1B_NORMAL_OPERATION                    0b00000000
// OC1B NON PWM MODES
#define OC1B_TOGGLE_ON_COMPARE_MATCH             0b00010000
#define OC1B_CLEAR_ON_COMPARE_MATCH              0b00100000
#define OC1B_SET_ON_COMPARE_MATCH                0b00110000
// OC1B FAST PWM MODES
#define OC1B_PWM_NON_INVERTING_MODE              0b00100000
#define OC1B_PWM_INVERTING_MODE                  0b00110000
// OC1B PHASE CORRECT PWM MODES
#define OC1B_PWM_CLEAR_ON_CTC_UP_COUNTING        0b00100000
#define OC1B_PWM_SET_ON_CTC_UP_COUNTING          0b00110000


typedef struct 
{
    u8 MODE;
    u8 CLOCK;
    u8 OC1A_MODE;
    u8 OC1B_MODE;
    u8 INPUT_CAPTURE_INTERRUPT_ENABLE;
    u8 COMPARE_MATCH_A_INTERRUPT_ENABLE;
    u8 COMPARE_MATCH_B_INTERRUPT_ENABLE;
    u8 OVERFLOW_INTERRUPT_ENABLE;
} TIMER1_CONFIG;

u8 TIMER1_voidInit(TIMER1_CONFIG *Copy_Timer1Config);
void TIMER1_voidSetTimerValue(u16 Copy_u8Value);
void TIMER1_voidSetTimerTopValue(u16 Copy_u16TopValue);
void TIMER1_voidSetChannelACompMatchValue(u16 Copy_u16CompareMatchValue);
void TIMER1_voidSetChannelBCompMatchValue(u16 Copy_u16CompareMatchValue);

u8 TIMER1_u8SetCallBackFuncOnCTC_A(void (*Copy_pvCallBackFunk)(void));
u8 TIMER1_u8SetCallBackFuncOnCTC_B(void (*Copy_pvCallBackFunk)(void));
u8 TIMER1_u8SetCallBackFuncOnOverFlow(void (*Copy_pvCallBackFunkOverFlow)(void));
u8 TIMER1_u8SetCallBackFuncInputCapture(void (*Copy_pvCallBackFunk)(void));

/*********************/
//? TIMER2 Interface 
/*********************/
// TIMER2 MODES: 
#define TIMER2_MODE_NORMAL                      0b00000000
#define TIMER2_MODE_PHASE_CORRECT_PWM           0b00001000
#define TIMER2_MODE_CTC                         0b01000000
#define TIMER2_MODE_FAST_PWM                    0b01001000

// TIMER2 CLOCKS: 
#define T2_NO_CLOCK_SOURCE                      0b00000000
#define T2_NO_PRESCALING                        0b00000001
#define T2_PRESCALING_BY_8                      0b00000010
#define T2_PRESCALING_BY_32                     0b00000011
#define T2_PRESCALING_BY_64                     0b00000100
#define T2_PRESCALING_BY_128                    0b00000101
#define T2_PRESCALING_BY_256                    0b00000110
#define T2_PRESCALING_BY_1024                   0b00000111

// OC2 PIN MODES:
#define OC2_NORMAL_OPERATION                    0b00000000
// OC2 NON PWM MODES
#define OC2_TOGGLE_ON_COMPARE_MATCH             0b00010000
#define OC2_CLEAR_ON_COMPARE_MATCH              0b00100000
#define OC2_SET_ON_COMPARE_MATCH                0b00110000
// OC2 FAST PWM MODES
#define OC2_PWM_NON_INVERTING_MODE              0b00100000
#define OC2_PWM_INVERTING_MODE                  0b00110000
// OC2 PHASE CORRECT PWM MODES
#define OC2_PWM_CLEAR_ON_CTC_UP_COUNTING        0b00100000
#define OC2_PWM_SET_ON_CTC_UP_COUNTING          0b00110000

typedef struct 
{
    u8 MODE;
    u8 CLOCK;
    u8 OC2_MODE;
    u8 COMPARE_MATCH_INTERRUPT_ENABLE;
    u8 OVERFLOW_INTERRUPT_ENABLE;
} TIMER2_CONFIG;

u8      TIMER2_voidInit(TIMER2_CONFIG *Copy_Timer2Config);
void    TIMER2_voidSetTimerValue(u8 Copy_u8Value);
void    TIMER2_voidSetCompMatchValue(u8 Copy_u8Value);
u8      TIMER2_u8SetCallBackFuncOnCTC(void (*Copy_pvCallBackFunkCTC)(void));
u8      TIMER2_u8SetCallBackFuncOnOverFlow(void (*Copy_pvCallBackFunkOverFlow)(void));

#endif
