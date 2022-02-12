/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : SSD                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"
#include "DIO_interface.h"

u8 SSD_u8MapSSD (u8 Copy_u8Number, u8 Copy_u8CommonType, u8 * Copy_pu8SSDValue){
    u8 Local_u8ErrorState = NO_ERROR; 
    if (Copy_pu8SSDValue != NULL){
        if(Copy_u8Number <= 9){
            u8 sevenSegmentMap [10] = {
                0b00111111, 	// value of 0 on seven segment 
                0b00000110, 	// value of 1 on seven segment 
                0b01011011, 	// value of 2 on seven segment 
                0b01001111,		// value of 3 on seven segment 
                0b01100110,		// value of 4 on seven segment 
                0b01101101,		// value of 5 on seven segment 
                0b01111101,		// value of 6 on seven segment 
                0b00000111,		// value of 7 on seven segment 
                0b01111111,		// value of 8 on seven segment 
                0b01100111}; 	// value of 9 on seven segment 
            u8 Local_mappedValue = sevenSegmentMap[Copy_u8Number];
            *Copy_pu8SSDValue = (Copy_u8CommonType == SSD_COMMON_CATHODE) ? Local_mappedValue : ~Local_mappedValue;
        }
        else{
            Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
        }
    }

    else{
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    return Local_u8ErrorState;
}


u8 SSD_u8SetNumber(u8 Copy_u8Number,SSD_T * Copy_pSSD_T){
    u8 Local_u8ErrorState = NO_ERROR; 
    if (Copy_pSSD_T != NULL){
        u8 SSD_mappedValue;
        Local_u8ErrorState = DIO_u8SetPortDirection(Copy_pSSD_T->port, DIO_u8PORT_OUTPUT);
        Local_u8ErrorState = DIO_u8SetPinDirection(Copy_pSSD_T->enablePort,Copy_pSSD_T->enablePin,DIO_u8PIN_OUTPUT); //for enable pin
        
        if(Copy_pSSD_T->commonType == SSD_COMMON_CATHODE){
            Local_u8ErrorState = DIO_u8SetPinValue(Copy_pSSD_T->enablePort,Copy_pSSD_T->enablePin,DIO_u8PIN_LOW);
        }

        else if(Copy_pSSD_T->commonType == SSD_COMMON_ANODE){
            Local_u8ErrorState = DIO_u8SetPinValue(Copy_pSSD_T->enablePort, Copy_pSSD_T->enablePin, DIO_u8PIN_HIGH);
        }
        else{
            Local_u8ErrorState = ERROR_WRONG_FUNCTION_ARGUMENTS;
        }
        
        Local_u8ErrorState = SSD_u8MapSSD(Copy_u8Number, Copy_pSSD_T->commonType, &SSD_mappedValue);
        Local_u8ErrorState = DIO_u8SetPortValue(Copy_pSSD_T->port, SSD_mappedValue);
    }
    
    else{
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }
    

    return Local_u8ErrorState;
}
