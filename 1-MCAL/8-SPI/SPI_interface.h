/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : SPI (Serial Peripheral Interface)       **********************/
/**********************    Version: 1.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
/**
* @brief Initializing the SPI  as a master. 
**/
void SPI_voidInitMaste(void);

/**
 * @brief It initializes the SPI in slave mode.
 */
void SPI_voidInitSlave(void);

/**
 * @brief It sends a byte and waits for the SPI to finish sending it, then it returns the received byte
 * 
 * @param Copy_u8Data The data to be sent.
 * 
 * @return The received data.
 */
u8 SPI_u8Transceive(u8 Copy_u8Data);

#endif