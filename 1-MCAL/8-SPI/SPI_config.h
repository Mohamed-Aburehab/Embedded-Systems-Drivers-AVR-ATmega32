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

/*Select SPI Clock Polarity 
options:    1- SPI_CLOCK_POLARITY_IDLE_LOW      -> Clock is LOW when idle  (Leading Edge = Rising )
            2- SPI_CLOCK_POLARITY_IDLE_HIGH     -> Clock is HIGH when idle (Leading Edge = Falling)
*/
#define SPI_CLOCK_POLARITY              SPI_CLOCK_POLARITY_IDLE_LOW

/*Select SPI Clock Phase 
options:    1- SPI_CLOCK_PHASE_SAMPLE_SETUP     -> receive on leading edge then send
            2- SPI_CLOCK_PHASE_SETUP_SAMPLE     -> send on leading edge then receive 
*/
#define SPI_CLOCK_PHASE                 SPI_CLOCK_PHASE_SAMPLE_SETUP
#endif