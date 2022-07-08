/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : TWI (Two Wire Serial Interface)       **********************/
/**********************    Version: 1.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_
/******************************************
TWI Bit Rate Register
-------------------------------------------------
|TWBR7|TWBR6|TWBR5|TWBR4|TWBR3|TWBR2|TWBR1|TWBR0|
-------------------------------------------------
******************************************/
#define     TWBR           *((volatile u8*) 0x20)   /* TWI Bit Rate Register */


/******************************************
TWI Control Register
----------------------------------------------
|TWINT|TWEA|TWSTA|TWSTO|TWWC|TWEN|  –   |TWIE|
----------------------------------------------
******************************************/
#define     TWCR           *((volatile u8*) 0x56)   /* TWI Control Register */
#define     TWCR_TWINT              7                /* TWI Interrupt Flag */
#define     TWCR_TWEA               6                /* TWI Enable Acknowledge Bit */
#define     TWCR_TWSTA              5                /* TWI START Condition Bit */
#define     TWCR_TWSTO              4                /* TWI STOP Condition Bit */
#define     TWCR_TWWC               3                /* TWI Write Collision Flag */
#define     TWCR_TWEN               2                /* TWI Enable Bit */
#define     TWCR_TWIE               0                /* TWI Interrupt Enable */

/******************************************
TWI Status Register
---------------------------------------------------
|TWS7|TWS6| TWS5| TWS4| TWS3 |  –   | TWPS1| TWPS0|
---------------------------------------------------
******************************************/
#define     TWSR           *((volatile u8*) 0x56)   /* TWI Control Register */
#define     TWSR_TWPS0      0
#define     TWSR_TWPS1      1
/******************************************
Two-wire Serial Interface Data Register
---------------------------------------------------
******************************************/
#define     TWDR           *((volatile u8*) 0x23)   /* TWI Control Register */

/******************************************
Slave Address Register
------------------------------------------
|TWA6|TWA5|TWA4|TWA3|TWA2|TWA1|TWA0|TWGCE|
------------------------------------------
******************************************/
#define     TWAR           *((volatile u8*) 0x22)   /* TWI Slave Address Register */
#define     TWAR_TWGCE              0                /* TWI General Call Recognition Enable Bit */

#endif



