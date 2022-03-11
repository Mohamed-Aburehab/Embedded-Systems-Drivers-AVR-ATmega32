/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : MCAL                            **********************/
/**********************    SWD    : GIE (general interrupt enable)  **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_register.h"
#include "GIE_interface.h"

/**
  * @brief  : Enable General interrupts 
  * @param  : void
  * @return : void
*/
void GIE_voidEnable (void){
    SET_BIT(SREG, SREG_I);
}

/**
  * @brief  : Disable General interrupts 
  * @param  : void
  * @return : void
*/
void GIE_voidDisable(void){
    CLR_BIT(SREG, SREG_I);
}
