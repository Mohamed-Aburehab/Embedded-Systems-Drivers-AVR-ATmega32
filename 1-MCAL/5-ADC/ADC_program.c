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
#include "ADC_config.h"
#include "ADC_private.h"

static u16 *ADC_pu16Reading = NULL;

static void (*ADC_pvCallBackNotificationFunc)(void) = NULL;

// global variables for the chain type to be used in ISR
static u8 * ADC_pu8ChainChannelArray = NULL;    // Global var to carry chain array
static u8 ADC_u8ChainSize;                      // Global var to carry number of channels
static u16 * ADC_pu16ChainResultArray = NULL;   // Global var to carry conversion result array
static u8 ADC_u8ChainConversionIndex = 0;       // Global var to carry conversion index


static u8 ADC_u8ISRsource;

u8 ADC_u8BusyState = IDLE;
/**
  * @brief  : // initialize ADC 
  * @param  : void
  * @return : void
*/
void ADC_voidInit(void){

	#if REFERENCE == 1
    // AREF, Internal Vref turned off
    CLR_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);

    #elif REFERENCE == 2
    // AVCC with external capacitor at AREF pin
    SET_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);

    #elif REFERENCE == 3
    // Internal 2.56V Voltage Reference with external capacitor at AREF pin
    SET_BIT(ADMUX, ADMUX_REFS0);
    SET_BIT(ADMUX, ADMUX_REFS1);
    #endif
    
     #if ADC_RETURN_TYPE == ADC_10BIT
     /*Activate Right adjust result*/
     CLR_BIT(ADMUX, ADMUX_ADLAR);
     #elif ADC_RETURN_TYPE == ADC_8BIT
     /*Activate Left adjust result*/
     SET_BIT(ADMUX, ADMUX_ADLAR);
     #endif

    // setting preselector
    ADCSRA &= 0b11111000;
    ADCSRA |= PRESCALER_SELECTION;

    /*Enable preipheral*/
    SET_BIT(ADCSRA, ADCSRA_ADEN);
}

/**
  * @brief  : // Get ADC channel Reading
  * @param  : Channel number
  * @param  : pointer to a u16 to store the adc value in it
  * @return : error state
*/

u8 ADC_u8GetChannelReadingSynch(u8 Copy_u8ChannelNumber, u16 *Copy_pu16DigitalValue){
    u8 Local_u8ErrorState = NO_ERROR; 
    u32 Local_u32Counter = 0;
    if (ADC_u8BusyState == IDLE){
        if (Copy_pu16DigitalValue == NULL){
            Local_u8ErrorState = ERROR_NULL_POINTER;
        }
        else if (Copy_u8ChannelNumber > 31){
            Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
        }
        else {
            // set ADC as busy 
            ADC_u8BusyState = BUSY;

            /*Clear the mux bits in ADMUX register*/
            ADMUX &= 0b11100000;

            /*Set the required channel into the MUX bits*/
            ADMUX |= Copy_u8ChannelNumber;

            /*Start Conversion*/
            SET_BIT(ADCSRA, ADCSRA_ADSC);

            // pooling (busy waiting) until the conversion complete flag is set or counter timeout
            while(((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0) && (Local_u32Counter != ADC_TIMEOUT)){
                Local_u32Counter ++;
            }
            if (Local_u32Counter == ADC_TIMEOUT){
                Local_u8ErrorState = ERROR_TIMEOUT;
            }else {
            // clear the conversion complete flag
            SET_BIT(ADCSRA, ADCSRA_ADIF);

            // saving the reading
            #if   ADC_RETURN_TYPE == ADC_8BIT
                *Copy_pu16DigitalValue = ADCH;
            #elif ADC_RETURN_TYPE == ADC_10BIT
                *Copy_pu16DigitalValue = ADCL;
                *Copy_pu16DigitalValue |= ADCH << 8;
            #endif
            }
            // set ADC as idle 
            ADC_u8BusyState = IDLE;
        }
    }else {
            Local_u8ErrorState = BUSY_FUNCTION;
        }
    // returning the error state
    return Local_u8ErrorState;
}

/**
  * @brief   Get ADC channel Reading Asynchronous
  * @param  :channel number
  * @param  :pointer to a u16 to store the adc value in it
  * @param  :pointer to the notification function
  * @return :error state
  * ! using this function will require you to enable the global interrupt
*/
u8 ADC_u8GetChannelReadingAsynch(u8 Copy_u8ChannelNumber, u16 *Copy_pu16DigitalValue, void(*Copy_PvNotificationFunc)(void)){
    u8 Local_u8ErrorState = NO_ERROR;
    if (ADC_u8BusyState == IDLE){
        // check for null pointer
        if ((Copy_pu16DigitalValue == NULL) || (Copy_PvNotificationFunc == NULL)){
            Local_u8ErrorState = ERROR_NULL_POINTER;
        }
        else if (Copy_u8ChannelNumber > 31){
            Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
        }else {
            // set ADC as busy 
            ADC_u8BusyState = BUSY;
            // set ISR source Singel Asynch
            ADC_u8ISRsource = SINGLE_CHANNEL_ASYNC;
            // initialize reading variable globally
            ADC_pu16Reading = Copy_pu16DigitalValue;
            // initialize the callback function globally
            ADC_pvCallBackNotificationFunc = Copy_PvNotificationFunc;
            /*Clear the mux bits in ADMUX register*/
            ADMUX &= 0b11100000;

            /*Set the required channel into the MUX bits*/
            ADMUX |= Copy_u8ChannelNumber;

            /*Start Conversion*/
            SET_BIT(ADCSRA, ADCSRA_ADSC);

            // Enable ADC Interrupt for Asynchronous
            SET_BIT(ADCSRA,ADCSRA_ADIE);
        }
    }else {
            Local_u8ErrorState = BUSY_FUNCTION;
        }
    return Local_u8ErrorState;
}

/**
  * @brief  :do a chain conversion
  * @param  :pointer to chain type
  * @return :error state
  * ! using this function will require you to enable the global interrupt
*/
u8 ADC_u8StartChainAsynch(Chain_t * Copy_Chain){
    u8 Local_u8ErrorState = NO_ERROR; 
    // check for NULL pointer
    if (Copy_Chain == NULL){
        u8 Local_u8ErrorState = ERROR_NULL_POINTER;
        return Local_u8ErrorState;
    }
    // check for ADC busy state
    if (ADC_u8BusyState == IDLE){
        // make ADC busy so no other function overwright the chain conversion
        ADC_u8BusyState = BUSY;
        
        // set ISR source to chain
        ADC_u8ISRsource = CHAIN_CONVERSION;

        // initialize chain channel array
        ADC_pu8ChainChannelArray = Copy_Chain->Channel;
        
        // initialize result array
        ADC_pu16ChainResultArray = Copy_Chain->Result;

        // initialize chain size
        ADC_u8ChainSize = Copy_Chain->Size;

        // initialize notification function
        ADC_pvCallBackNotificationFunc = Copy_Chain->NotificationFunc;

        // initialize current conversion index to 0
        ADC_u8ChainConversionIndex = 0;
        
        // set required channel (first channel)
        ADMUX &= 0b11100000;
        ADMUX |= ADC_pu8ChainChannelArray[ADC_u8ChainConversionIndex];

        // start conversion
        SET_BIT(ADCSRA, ADCSRA_ADSC);

        // enable conversion complete interrupt
        SET_BIT(ADCSRA, ADCSRA_ADIE);
    }
    // ADC is busy 
    else {
        Local_u8ErrorState = BUSY_FUNCTION;
    }
    return Local_u8ErrorState;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void){
    // single channel async ISR
    if (ADC_u8ISRsource == SINGLE_CHANNEL_ASYNC){
        // read ADC result
        #if   ADC_RETURN_TYPE == ADC_8BIT
            *ADC_pu16Reading = ADCH;
        #elif ADC_RETURN_TYPE == ADC_10BIT
            *ADC_pu16Reading = ADCL;
            *ADC_pu16Reading |= ADCH << 8;
        #endif

        // set ADC as idle
        ADC_u8BusyState = IDLE;
        // invoke the callback notification function
        ADC_pvCallBackNotificationFunc();
        // disable ADC conversion complete interrupt
        CLR_BIT(ADCSRA, ADCSRA_ADIE);
    }
    // single chain conversion ISR
    else if (ADC_u8ISRsource == CHAIN_CONVERSION){
        // read the current conversion 
        #if   ADC_RETURN_TYPE == ADC_8BIT
            ADC_pu16ChainResultArray[ADC_u8ChainConversionIndex] = ADCH;
        #elif ADC_RETURN_TYPE == ADC_10BIT
            ADC_pu16ChainResultArray[ADC_u8ChainConversionIndex] = ADCL;
            ADC_pu16ChainResultArray[ADC_u8ChainConversionIndex] |= ADCH << 8;
        #endif

        // increament channel index
        ADC_u8ChainConversionIndex ++;

        // check chain is finished or not
        if(ADC_u8ChainConversionIndex == ADC_u8ChainSize){  // chain is finished
            // set ADC as idle
            ADC_u8BusyState = IDLE;
            // invoke the callback notification function
            ADC_pvCallBackNotificationFunc();
            // disable ADC conversion complete interrupt
            CLR_BIT(ADCSRA, ADCSRA_ADIE);
        }
        else {  // chain is not finished
            // set next required channel 
            ADMUX &= 0b11100000;
            ADMUX |= ADC_pu8ChainChannelArray[ADC_u8ChainConversionIndex];

            // start conversion
            SET_BIT(ADCSRA, ADCSRA_ADSC);

            // enable conversion complete interrupt
            SET_BIT(ADCSRA, ADCSRA_ADIE);
        }
    }
}