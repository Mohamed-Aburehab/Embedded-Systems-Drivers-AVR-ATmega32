/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : TWI (Two Wire Serial Interface)       **********************/
/**********************    Version: 1.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_register.h"
#include "TWI_config.h"
#include "TWI_private.h"
#include "TWI_interface.h"

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress){
    /* Set clock frequency to 400Kbps */ 
    /* Set TWBR to 2 */
    TWBR = 2;
    /* clear 2 bits of TWPS */
    CLR_BIT(TWSR, TWSR_TWPS0);
    CLR_BIT(TWSR, TWSR_TWPS1);

    /* Initialize node address */
    if (Copy_u8SlaveAddress != 0){
        TWAR = Copy_u8SlaveAddress << 1;
    }

    /* Enable TWI */
    SET_BIT(TWCR, TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress){
    /* Initialize node address */
    TWAR = Copy_u8SlaveAddress << 1;

    /* Enable TWI */
    SET_BIT(TWCR, TWCR_TWEN);
}

TWI_ErrStatus TWI_SendStartCondition(void){
    TWI_ErrStatus Local_ErrStatus = NoError;

    /* Send start condition on the bus*/
    SET_BIT(TWCR, TWCR_TWSTA);

    /* Clear interrupt flag to start previous operation */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again (previous operation is complete) */
    while (GET_BIT(TWCR, TWCR_TWINT) == 0);

    /* Check the operation status in the status register */
    if((TWSR & 0xF8) != START_ACK){
        Local_ErrStatus = StartConditionErr;
    }

    return Local_ErrStatus;
}

TWI_ErrStatus TWI_sendRepeatedStart(void){
    TWI_ErrStatus Local_ErrStatus = NoError;

    /* Send start condition on the bus*/
    SET_BIT(TWCR, TWCR_TWSTA);

    /* Clear interrupt flag to start previous operation */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again (previous operation is complete) */
    while (GET_BIT(TWCR, TWCR_TWINT) == 0);

    /* Check the operation status in the status register */
    if((TWSR & 0xF8) != REP_START_ACK){
        Local_ErrStatus = RepeatedStartErr;
    }

    return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress){
    TWI_ErrStatus Local_ErrStatus = NoError;

    /* Clear start conditon bit */
    CLR(TWCR, TWCR_TWSTA);

    /* Set slave address in the 7 MSB in the data register */
    TWDR = Copy_u8SlaveAddress << 1;
    CLR_BIT(TWDR, 0);           /* for write request */
    
    /* Clear interrupt flag to start previous operation */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again (previous operation is complete) */
    while (GET_BIT(TWCR, TWCR_TWINT) == 0);

    /* Check the operation status in the status register */
    if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK){
        Local_ErrStatus = SlaveAddressWithWriteErr;
    }

    return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress){
    TWI_ErrStatus Local_ErrStatus = NoError;

    /* Clear start conditon bit */
    CLR(TWCR, TWCR_TWSTA);

    /* Set slave address in the 7 MSB in the data register */
    TWDR = Copy_u8SlaveAddress << 1;
    SET_BIT(TWDR, 0);           /* for read request */
    
    /* Clear interrupt flag to start previous operation */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again (previous operation is complete) */
    while (GET_BIT(TWCR, TWCR_TWINT) == 0);

    /* Check the operation status in the status register */
    if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK){
        Local_ErrStatus = SlaveAddressWithReadErr;
    }

    return Local_ErrStatus;
}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte){
    TWI_ErrStatus Local_ErrStatus = NoError;

    /* Set slave address in the 7 MSB in the data register */
    TWDR = Copy_u8DataByte ;

    /* Clear interrupt flag to start previous operation */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again (previous operation is complete) */
    while (GET_BIT(TWCR, TWCR_TWINT) == 0);

    /* Check the operation status in the status register */
    if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK){
        Local_ErrStatus = MasterWriteByteErr;
    }

    return Local_ErrStatus;
}

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte){
    TWI_ErrStatus Local_ErrStatus = NoError;

    /* Enable master to generate acknowledge bitafter receiving */
    SET_BIT(TWCR, TWCR_TWEA);

    /* Clear interrupt flag to allow slave to send data */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again (previous operation is complete) */
    while (GET_BIT(TWCR, TWCR_TWINT) == 0);

    /* Check the operation status in the status register */
    if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK){
        Local_ErrStatus = MasterWriteByteErr;
    }else {
        /* Read recived data */
        *Copy_pu8DataByte = TWDR;
    }

    return Local_ErrStatus;
}

void TWI_SendStopCondition(void){
    /* Generate stop condition on the bus */
    SET_BIT(TWCR, TWCR_TWSTO);  

    /* Clear interrupt flag to allow slave to send data */
    SET_BIT(TWCR, TWCR_TWINT);

}
