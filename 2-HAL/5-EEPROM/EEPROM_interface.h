/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : EEPROM                                  **********************/
/**********************    Version: 1.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidSendDataByte(u8 Copy_u8DataBute, u16 Copy_u16Address);

void EEPROM_voidReadDataByte(u16 Copy_u16Address, u8 *DataByte);

#endif