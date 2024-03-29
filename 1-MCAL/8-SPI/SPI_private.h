/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : SPI (Serial Peripheral Interface)       **********************/
/**********************    Version: 1.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/* Clock Prescaler settings */
#define SPI_CLOCK_PRESCALER_DIV_BY_4            1
#define SPI_CLOCK_PRESCALER_DIV_BY_16           2
#define SPI_CLOCK_PRESCALER_DIV_BY_64           3
#define SPI_CLOCK_PRESCALER_DIV_BY_128          4
#define SPI_CLOCK_PRESCALER_DIV_BY_2            5
#define SPI_CLOCK_PRESCALER_DIV_BY_8            6
#define SPI_CLOCK_PRESCALER_DIV_BY_32           7
#define SPI_CLOCK_PRESCALER_DIV_BY_64           8

/*Clock Polarity Setting*/
#define SPI_CLOCK_POLARITY_IDLE_LOW             1
#define SPI_CLOCK_POLARITY_IDLE_HIGH            2

/*Clock Phase Setting*/
#define SPI_CLOCK_PHASE_SAMPLE_SETUP            1
#define SPI_CLOCK_PHASE_SETUP_SAMPLE            2

#endif