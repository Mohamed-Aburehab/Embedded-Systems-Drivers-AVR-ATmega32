/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : MCAL                            **********************/
/**********************    SWD    : Timer                           **********************/
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
#define TIMSK_OCIE0                 1                  // Timer0 output compare match interrupt enable
#define TIMSK_TOIE0                 0                  // Timer0 Overflow Interrupt Enable
// Timer 1
#define TIMSK_TICIE1                1                  // Timer1 input capture interrupt enable
#define TIMSK_OCIE1A                1                  // Timer1 output compare A match interrupt enable
#define TIMSK_OCIE1B                1                  // Timer1 output compare B match interrupt enable
#define TIMSK_TOIE1                 1                  // Timer1 overflow interrupt enable
// Timer 2
#define TIMSK_OCIE2                 7                  // Timer2 output compare match interrupt enable
#define TIMSK_TOIE2                 6                  // Timer2 Overflow Interrupt Enable


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

/*********************/
//? TIMER1 Registers 
/*********************/
/******************************************
TCCR1A Control Rigester A
-------------------------------------------
|COM1A1|COM1A0|COM1B1|COM1B0|   |   |WGM11|WGM10|
-------------------------------------------
******************************************/
#define TCCR1A                       *((volatile u8*)0x4F)
#define TCCR1A_COM1A1                 7                  // Compare Output Mode for Compare unit A
#define TCCR1A_COM1A0                 6                  // Compare Output Mode for Compare unit A
#define TCCR1A_COM1B1                 5                  // Compare Output Mode for Compare unit B
#define TCCR1A_COM1B0                 4                  // Compare Output Mode for Compare unit B
#define TCCR1A_WGM11                  1                  // Waveform Generation Mode
#define TCCR1A_WGM10                  0                  // Waveform Generation Mode



#define TCCR1B                       *((volatile u8*)0x4E)
/******************************************
TCCR1B Control Rigester B
-------------------------------------------
|   |   |   |WGM13|WGM12|CS12|CS11|CS10|
-------------------------------------------
******************************************/
#define TCCR1B_WGM13                  4                  // Waveform Generation Mode
#define TCCR1B_WGM12                  3                  // Waveform Generation Mode
#define TCCR1B_CS12                   2                  // Timer1 Prescaller bit2
#define TCCR1B_CS11                   1                  // Timer1 Prescaller bit1
#define TCCR1B_CS10                   0                  // Timer1 Prescaller bit0

#define TCCR1                         *((volatile u16*)0x4E)

/******************************************
--------------------------------------------
|  Timer/Counter2 Register  |
--------------------------------------------
******************************************/
#define TCNT1                         *((volatile u16*)0x4C)



#define ICR1                          *((volatile u16*)0x46)

#define OCR1A                         *((volatile u16*)0x4A)

#define OCR1B                         *((volatile u16*)0x48)

/*********************/
//? TIMER2 Registers 
/*********************/
/******************************************
Timer2 Control Rigester 
-------------------------------------------
|    |WGM20|COM21|COM20|WGM21|CS22|CS21|CS20|
-------------------------------------------
******************************************/
#define TCCR2                       *((volatile u8*)0x45)
#define TCCR2_WGM20                 6                  // Timer2 Waveform generation mode bit0
#define TCCR2_WGM21                 3                  // Timer2 Waveform generation mode bit1

#define TCCR2_COM21                 5                  // Compare Match Output Mode
#define TCCR2_COM20                 4                  // Compare Match Output Mode

#define TCCR2_CS22                  2                  // Timer2 Prescaller bit2
#define TCCR2_CS21                  1                  // Timer2 Prescaller bit1
#define TCCR2_CS20                  0                  // Timer2 Prescaller bit0

/******************************************
--------------------------------------------
|  Timer/Counter2 Register  |
--------------------------------------------
******************************************/
#define TCNT2                       *((volatile u8*)0x44)

/******************************************
Output compare register 2 
--------------------------------------------
|  Timer/Counter2 Output Compare Register  |
--------------------------------------------
******************************************/
#define OCR2                        *((volatile u8*)0x43)


#endif
