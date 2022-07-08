/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : EEPROM                                  **********************/
/**********************    Version: 1.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"

void EEPROM_voidSendDataByte(u8 Copy_u8DataBute, u16 Copy_u16Address){
    u8 Local_u8Address = 0b1010000 | (EEPROM_A2_VALUE << 2) | (Copy_u16Address >> 8);
    
    TWI_SendStartCondition();

    TWI_SendSlaveAddressWithWrite(Local_u8Address);

    TWI_MasterWriteDataByte((u8) Copy_u16Address);

    TWI_MasterWriteDataByte(Copy_u8DataBute);

    TWI_SendStopCondition();
}

void EEPROM_voidReadDataByte(u16 Copy_u16Address, u8 *DataByte){
    u8 Local_u8Address = 0b1010000 | (EEPROM_A2_VALUE << 2) | (Copy_u16Address >> 8);
    
    TWI_SendStartCondition();

    TWI_SendSlaveAddressWithWrite(Local_u8Address);

    TWI_MasterWriteDataByte((u8) Copy_u16Address);

    TWI_sendRepeatedStart();

    TWI_SendSlaveAddressWithRead(Local_u8Address);

    TWI_MasterReadDataByte(DataByte);

    TWI_SendStopCondition();
}
