/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : SPI (Serial Peripheral Interface)       **********************/
/**********************    Version: 1.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_
/*Select SPI Clock Prescaler 
options:    1- SPI_CLOCK_PRESCALER_DIV_BY_4    -> To Divide Fosc by 4
            2- SPI_CLOCK_PRESCALER_DIV_BY_16   -> To Divide Fosc by 16  
            3- SPI_CLOCK_PRESCALER_DIV_BY_64   -> To Divide Fosc by 64 
            4- SPI_CLOCK_PRESCALER_DIV_BY_128  -> To Divide Fosc by 128 
            5- SPI_CLOCK_PRESCALER_DIV_BY_2    -> To Divide Fosc by 2
            6- SPI_CLOCK_PRESCALER_DIV_BY_8    -> To Divide Fosc by 8
            7- SPI_CLOCK_PRESCALER_DIV_BY_32   -> To Divide Fosc by 32  
            8- SPI_CLOCK_PRESCALER_DIV_BY_64   -> To Divide Fosc by 64 
*/
#define SPI_CLOCK_PRESCALER_VALUE       SPI_CLOCK_PRESCALER_DIV_BY_16


#endif