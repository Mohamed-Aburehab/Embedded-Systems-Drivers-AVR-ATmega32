/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : MCAL                            **********************/
/**********************    SWD    : ADC (Analog Digital Converter)  **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


typedef struct
{
  u8* Channel;
  u16* Result;
  u8 Size;
  void (*NotificationFunc)(void);

}Chain_t;


/* Channels names */
#define ADC_SINGLE_ENDED_ADC0                               0
#define ADC_SINGLE_ENDED_ADC1                               1
#define ADC_SINGLE_ENDED_ADC2                               2
#define ADC_SINGLE_ENDED_ADC3                               3
#define ADC_SINGLE_ENDED_ADC4                               4
#define ADC_SINGLE_ENDED_ADC5                               5
#define ADC_SINGLE_ENDED_ADC6                               6
#define ADC_SINGLE_ENDED_ADC7                               7

#define ADC_DIF_POS_ADC0_NEG_ADC0_10X                       8
#define ADC_DIF_POS_ADC1_NEG_ADC0_10X                       9

#define ADC_DIF_POS_ADC0_NEG_ADC0_200X                      10
#define ADC_DIF_POS_ADC1_NEG_ADC0_200X                      11

#define ADC_DIF_POS_ADC2_NEG_ADC2_10X                       12
#define ADC_DIF_POS_ADC3_NEG_ADC2_10X                       13

#define ADC_DIF_POS_ADC2_NEG_ADC2_200X                      14
#define ADC_DIF_POS_ADC3_NEG_ADC2_200X                      15

#define ADC_DIF_POS_ADC0_NEG_ADC1_1X                        16
#define ADC_DIF_POS_ADC1_NEG_ADC1_1X                        17
#define ADC_DIF_POS_ADC2_NEG_ADC1_1X                        18
#define ADC_DIF_POS_ADC3_NEG_ADC1_1X                        19
#define ADC_DIF_POS_ADC4_NEG_ADC1_1X                        20
#define ADC_DIF_POS_ADC5_NEG_ADC1_1X                        21
#define ADC_DIF_POS_ADC6_NEG_ADC1_1X                        22
#define ADC_DIF_POS_ADC7_NEG_ADC1_1X                        23

#define ADC_DIF_POS_ADC0_NEG_ADC2_1X                        24
#define ADC_DIF_POS_ADC1_NEG_ADC2_1X                        25
#define ADC_DIF_POS_ADC2_NEG_ADC2_1X                        26
#define ADC_DIF_POS_ADC3_NEG_ADC2_1X                        27
#define ADC_DIF_POS_ADC4_NEG_ADC2_1X                        28
#define ADC_DIF_POS_ADC5_NEG_ADC2_1X                        29

#define ADC_SINGLE_ENDED_1_22v                              30
#define ADC_SINGLE_ENDED_0V_GND                             31

/**
  * @brief  : // initialize ADC 
  * @param  : void
  * @return : void
*/
void ADC_voidInit(void);

/**
  * @brief  :Get ADC channel Reading synchronous
  * @param  :channel number
  * @param  :pointer to a u16 to store the adc value in it
  * @return :error state
*/
u8 ADC_u8GetChannelReadingSynch(u8 Copy_u8ChannelNumber, u16 *Copy_pu16DigitalValue);

/**
  * @brief  :Get ADC channel Reading Asynchronous
  * @param  :channel number
  * @param  :pointer to a u16 to store the adc value in it
  * @param  :pointer to the notification function
  * @return :error state
  * ! using this function will require you to enable the global interrupt
*/
u8 ADC_u8GetChannelReadingAsynch(u8 Copy_u8ChannelNumber, u16 *Copy_pu16DigitalValue, void(*Copy_PvNotificationFunc)(void));

/**
  * @brief  :do a chain conversion
  * @param  :pointer to chain type
  * @return :error state
  * ! using this function will require you to enable the global interrupt
*/
u8 ADC_u8StartChainAsynch(Chain_t * Copy_Chain);

#endif