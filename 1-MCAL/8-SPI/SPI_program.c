/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : SPI (Serial Peripheral Interface)       **********************/
/**********************    Version: 1.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_register.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"

void SPI_voidInitMaste(void){
    /* Master initialization */
    SET_BIT(SPCR, SPCR_MSTR);

    /* Clock Prescaler settings */
    #if   SPI_CLOCK_PRESCALER_VALUE == SPI_CLOCK_PRESCALER_DIV_BY_4
        CLR_BIT(SPCR, SPCR_SPR0);
        CLR_BIT(SPCR, SPCR_SPR1);
        CLR_BIT(SPSR, SPSR_SPI2X);
    #elif SPI_CLOCK_PRESCALER_VALUE == SPI_CLOCK_PRESCALER_DIV_BY_16
        SET_BIT(SPCR, SPCR_SPR0);
        CLR_BIT(SPCR, SPCR_SPR1);
        CLR_BIT(SPSR, SPSR_SPI2X); 
    #elif SPI_CLOCK_PRESCALER_VALUE == SPI_CLOCK_PRESCALER_DIV_BY_64 
        CLR_BIT(SPCR, SPCR_SPR0);
        SET_BIT(SPCR, SPCR_SPR1);
        CLR_BIT(SPSR, SPSR_SPI2X);
    #elif SPI_CLOCK_PRESCALER_VALUE == SPI_CLOCK_PRESCALER_DIV_BY_128
        SET_BIT(SPCR, SPCR_SPR0);
        SET_BIT(SPCR, SPCR_SPR1);
        CLR_BIT(SPSR, SPSR_SPI2X);
    #elif SPI_CLOCK_PRESCALER_VALUE == SPI_CLOCK_PRESCALER_DIV_BY_2  
        CLR_BIT(SPCR, SPCR_SPR0);
        CLR_BIT(SPCR, SPCR_SPR1);
        SET_BIT(SPSR, SPSR_SPI2X);
    #elif SPI_CLOCK_PRESCALER_VALUE == SPI_CLOCK_PRESCALER_DIV_BY_8  
        SET_BIT(SPCR, SPCR_SPR0);
        CLR_BIT(SPCR, SPCR_SPR1);
        SET_BIT(SPSR, SPSR_SPI2X);
    #elif SPI_CLOCK_PRESCALER_VALUE == SPI_CLOCK_PRESCALER_DIV_BY_32 
        CLR_BIT(SPCR, SPCR_SPR0);
        SET_BIT(SPCR, SPCR_SPR1);
        SET_BIT(SPSR, SPSR_SPI2X);
    #elif SPI_CLOCK_PRESCALER_VALUE == SPI_CLOCK_PRESCALER_DIV_BY_64 
        SET_BIT(SPCR, SPCR_SPR0);
        SET_BIT(SPCR, SPCR_SPR1);
        SET_BIT(SPSR, SPSR_SPI2X);
    #endif


    /* Enable SPI */
    SET_BIT(SPCR, SPCR_SPE);
}

void SPI_voidInitSlave(void){
    /* Slave initialization */
    CLR_BIT(SPCR, SPCR_MSTR);

    /* Enable SPI */
    SET_BIT(SPCR, SPCR_SPE);
}

u8 SPI_u8Transceive(u8 Copy_u8Data){

    /* Send Data */
    SPDR = Copy_u8Data;
    /* Wait (busy waiting) until transceive complete */
    while (GET_BIT(SPSR, SPSR_SPIF) == 0);

    /* Return received data */
    return SPDR;
}
