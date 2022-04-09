/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : MCAL                            **********************/
/**********************    SWD    : ADC (Analog Digital Converter)  **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*
    For reference there are 3 options:  1 - for  (AREF, Internal Vref turned off)
                                        2 - AVCC with external capacitor at AREF pin
                                        3 - Internal 2.56V Voltage Reference with external capacitor at AREF pin    
*/
#define REFERENCE                           2


/*
    For ADC Prescaler Selections there are 8 options:   0 - Division_Factor = 2
                                                        1 - Division_Factor = 2
                                                        2 - Division_Factor = 4
                                                        3 - Division_Factor = 8
                                                        4 - Division_Factor = 16
                                                        5 - Division_Factor = 32
                                                        6 - Division_Factor = 64
                                                        7 - Division_Factor = 128
*/

#define PRESCALER_SELECTION                     7

/*
    For ADC Return value there are 2 options:   1 - 8 bit ADC  (ADC_8BIT)
                                                2 - 10 bit ADC (ADC_10BIT)

*/
#define ADC_RETURN_TYPE                     ADC_8BIT


// define ADC waiting time 
#define ADC_TIMEOUT 50000
#endif