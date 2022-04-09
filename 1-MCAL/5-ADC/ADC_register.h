/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : MCAL                            **********************/
/**********************    SWD    : ADC (Analog Digital Converter)  **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

// ADC Multiplexer selection Rigester
#define ADMUX               *((volatile  u8*)0x27)
#define ADMUX_REFS1   7         // reference selection bit1
#define ADMUX_REFS0   6         // reference selection bit0
#define ADMUX_ADLAR   5         // ADC left adjust result

// ADC Control and status Register A
#define ADCSRA              *((volatile  u8*)0x26) 
#define ADCSRA_ADEN   7         // ADC enable
#define ADCSRA_ADSC   6         // ADC start conversion 
#define ADCSRA_ADATE  5         // ADC auto trigger enable
#define ADCSRA_ADIF   4         // ADC interrupt flag
#define ADCSRA_ADIE   3         // ADC interrupt enable 
#define ADCSRA_ADPS2  2         // ADC Prescaler bit2
#define ADCSRA_ADPS1  1         // ADC Prescaler bit1
#define ADCSRA_ADPS0  0         // ADC Prescaler bit0

// ADC high register
#define ADCH                *((volatile  u8*)0x25)

// ADC low register
#define ADCL                *((volatile  u8*)0x24)

#define ADC_HIGH_AND_LOW    *((volatile  u16*)0x24)

#define SFIOR               *((volatile  u8*)0x50)
#define SFIOR_ADTS2   7         // ADC Auto Trigger Source 2
#define SFIOR_ADTS1   6         // ADC Auto Trigger Source 1 
#define SFIOR_ADTS0   5         // ADC Auto Trigger Source 0

#endif