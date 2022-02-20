/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : CLCD                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"


#define NO_ERROR 0
#define ERROR_WRONG_FUNCTION_ARGUMENTS 1
#define ERROR_NULL_POINTER 2


void CLCD_voidSendCommand(u8 Copy_u8Command){
    // set RS pin to low for command
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);
    
}

void CLCD_voidSendData(u8 Copy_u8Data){

}

void CLCD_voidInit(void){
    
}
