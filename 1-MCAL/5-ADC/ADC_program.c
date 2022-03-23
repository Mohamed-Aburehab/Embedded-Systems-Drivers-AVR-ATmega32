/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : MCAL                            **********************/
/**********************    SWD    : ADC (Analog Digital Converter)  **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_private.h"

/**
  * @brief  : // initialize ADC 
  * @param  : void
  * @return : void
*/
void ADC_voidInit(void){
    /*AVCC as refrence voltage*/
    SET_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);
    
    /*Activate Left adjust result*/
    SET_BIT(ADMUX, ADMUX_ADLAR);

    /*Set Prescaler to divide by 128*/
    SET_BIT(ADCSRA,ADCSRA_ADPS2);
    SET_BIT(ADCSRA,ADCSRA_ADPS1);
    SET_BIT(ADCSRA,ADCSRA_ADPS0);

    /*Enable preipheral*/
    SET_BIT(ADCSRA, ADCSRA_ADEN);
}

/**
  * @brief  : // Get ADC channel Reading
  * @param  : void
  * @return : void
*/
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel){
    /*Clear the mux bits in ADMUX register*/
    ADMUX &= 0b11100000;

    /*Set the required channel into the MUX bits*/
    ADMUX |= Copy_u8Channel;

    /*Start Conversion*/
    SET_BIT(ADCSRA, ADCSRA_ADSC);

    // ! pooling (busy waiting) until the conversion complete flag is set
    while((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0);
    // clear the conversion complete flag
    SET_BIT(ADCSRA, ADCSRA_ADIF);

    // returning the reading
    return ADCH;
}
