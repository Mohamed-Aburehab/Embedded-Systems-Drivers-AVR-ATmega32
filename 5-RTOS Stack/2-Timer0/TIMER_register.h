/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : RTOS Stack                      **********************/
/**********************    SWD    : Timer0                          **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

/******************************************
Timer mask 
-------------------------------------------
|OCIE2|TOIE2|TICIE1|OCIE1A|OCIE1B|TOIE1|OCIE0|TOIE0|
-------------------------------------------
******************************************/
#define TIMSK                       *((volatile u8*)0x59)
// Timer 0
#define TIMSK_TOIE0                 0                  // Timer0 Overflow Interrupt Enable
#define TIMSK_OCIE0                 1                  // Timer0 output compare match interrupt enable

/******************************************
Timer/Counter Interrupt Flag Register 
-------------------------------------------
|OCF2|TOV2|ICF1|OCF1A|OCF1B|TOV1|OCF0|TOV0|
-------------------------------------------
******************************************/
#define TIFR                       *((volatile u8*)0x58)
// Timer 0
#define TIMSK_TOV0                  0                  // Timer0 Overflow Flag
#define TIMSK_OCF0                  1                  // Timer0 Output Compare Flag

/*********************/
//? TIMER0 Registers 
/*********************/
/******************************************
Timer0 Control Rigester 
-------------------------------------------
|    |WGM00|COM01|COM00|WGM01|CS02|CS01|CS00|
-------------------------------------------
******************************************/
#define TCCR0                       *((volatile u8*)0x53)
#define TCCR0_WGM00                 6                  // Timer0 Waveform generation mode bit0
#define TCCR0_WGM01                 3                  // Timer0 Waveform generation mode bit1

#define TCCR0_COM01                 5                  // Compare Match Output Mode
#define TCCR0_COM00                 4                  // Compare Match Output Mode

#define TCCR0_CS02                  2                  // Timer0 Prescaller bit2
#define TCCR0_CS01                  1                  // Timer0 Prescaller bit1
#define TCCR0_CS00                  0                  // Timer0 Prescaller bit0

/******************************************
Output compare register 0 
--------------------------------------------
|  Timer/Counter0 Output Compare Register  |
--------------------------------------------
******************************************/
#define OCR0                        *((volatile u8*)0x5c)

/******************************************
--------------------------------------------
|  Timer/Counter Register  |
--------------------------------------------
******************************************/
#define TCNT0                       *((volatile u8*)0x52)


#endif
