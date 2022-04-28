/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : CLCD                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"

void CLCD_voidSendCommand(u8 Copy_u8Command){
    
    #if CLCD_MODE == 8
        // set RS pin to low for command
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);

        //set RW pin to low for write
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

        // set command to data pins
        DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Command);

        // sent enable pulse
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
        _delay_us(1);
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);

    #elif CLCD_MODE == 4
        // set RS pin to low for command
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);

        //set RW pin to low for write
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

        // set command Higher Order to data pins
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_7, GET_BIT(Copy_u8Command,7));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_6, GET_BIT(Copy_u8Command,6));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_5, GET_BIT(Copy_u8Command,5));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_4, GET_BIT(Copy_u8Command,4));
        // sent enable pulse
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
        _delay_us(2);
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
        _delay_us(200);

        // set command Lower Order to data pins
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_7, GET_BIT(Copy_u8Command,3));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_6, GET_BIT(Copy_u8Command,2));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_5, GET_BIT(Copy_u8Command,1));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_4, GET_BIT(Copy_u8Command,0));
        // sent enable pulse
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
        _delay_us(2);
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
        _delay_ms(2);
    #endif
}

void CLCD_voidSendData(u8 Copy_u8Data){
    
    #if CLCD_MODE == 8
        // set RS pin to High for data
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);

        //set RW pin to low for write
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

        // set data to data pins
        DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data);

        // sent enable pulse
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
        _delay_us(1);
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);

    #elif CLCD_MODE == 4
        // set RS pin to High for data
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);

        //set RW pin to low for write
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

        // set data Higher Order to data pins
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_7, GET_BIT(Copy_u8Data,7));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_6, GET_BIT(Copy_u8Data,6));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_5, GET_BIT(Copy_u8Data,5));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_4, GET_BIT(Copy_u8Data,4));

        // sent enable pulse
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
        _delay_us(2);
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
        _delay_us(200);

        // set command Lower Order to data pins
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_7, GET_BIT(Copy_u8Data,3));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_6, GET_BIT(Copy_u8Data,2));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_5, GET_BIT(Copy_u8Data,1));
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_4, GET_BIT(Copy_u8Data,0));
        // sent enable pulse
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
        _delay_us(2);
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
        _delay_ms(2);
	#endif

}

void CLCD_voidInit(void){
    #if CLCD_MODE == 8
        // wait for more than 30ms
        _delay_ms(40);

        // display characters configurations {lines: 2, font size: 5*8}
        CLCD_voidSendCommand(0x38);
        _delay_us(100);

        // display on off and cursor configurations : {displayEnable: 1, cursor: 0, cursorBlink: 0}
        CLCD_voidSendCommand(0x0C);
        _delay_us(100);

        // clear display
        CLCD_voidSendCommand(0x01);
        _delay_ms(2);

        // entry mode
        CLCD_voidSendCommand(0x06);
        _delay_ms(2);

	#elif CLCD_MODE == 4
        // wait for more than 30ms
        _delay_ms(40);

        // set RS pin to low for command
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);
        //set RW pin to low for write
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_7, 0);
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_6, 0);
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_5, 1);
        DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_DATA_PIN_4, 0);


        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
        _delay_us(2);
        DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
        _delay_us(200);

        // display characters configurations {lines: 2, font size: 5*8}
        CLCD_voidSendCommand(0x28);
        _delay_us(100);

        // display on off and cursor configurations : {displayEnable: 1, cursor: 0, cursorBlink: 0}
        CLCD_voidSendCommand(0x0C);
        _delay_us(100);

        // clear display
        CLCD_voidSendCommand(0x01);
        _delay_ms(2);

        // entry mode
        CLCD_voidSendCommand(0x06);
        _delay_ms(2);

	#endif
}


void CLCD_voidSendString(const char * Copy_pcString){
    u8 Local_u8StringCounter = 0;
    while(Copy_pcString[Local_u8StringCounter] != '\0'){
        CLCD_voidSendData(Copy_pcString[Local_u8StringCounter]);
        Local_u8StringCounter ++;
    }
}

void CLCD_voidGoToXY(u8 Copy_u8XPosition, u8 Copy_u8YPosition){
    u8 Local_u8Address = 0x00;
    switch (Copy_u8XPosition)
    {
    // if x = 0 go to address y on the ddram
    case 0:
        Local_u8Address = 0x00 + Copy_u8YPosition;
        break;
    case 1:
    // if x = 1 go to address 0x40 + y on the ddram
        Local_u8Address = 0x40 + Copy_u8YPosition;
        break;
    }
    CLCD_voidSendCommand(Local_u8Address+ 128);
}

void CLCD_voidWriteSpecialCharacter(u8 * Copy_pu8SpecialCharacterArray, u8 Copy_u8BlockNumber,
                                    u8 Copy_u8XPosition, u8 Copy_u8YPosition){
    
    // calculate CG address
    u8 Local_u8CGRamAddress = 8* Copy_u8BlockNumber;

    // send CG ram command to lcd with setting bit[6]  =1 and bit[7,8] = 0
    CLCD_voidSendCommand(Local_u8CGRamAddress+ 64);

    // write the pattern into CG ram
    for(u8 Local_u8Iterator = 0; Local_u8Iterator <8; Local_u8Iterator++){
        CLCD_voidSendData(Copy_pu8SpecialCharacterArray[Local_u8Iterator]);
    }

    // go to DDRAM position x,y to display the pattern 
    CLCD_voidGoToXY(Copy_u8XPosition,Copy_u8YPosition);

    // display the pattern
    CLCD_voidSendData(Copy_u8BlockNumber);
}

void CLCD_voidWriteNumber(u32 Copy_u32Number){
    u8 numberOfDigits = CLCD_private_u8GetnumberOfDigits(Copy_u32Number);
    char numberArray[numberOfDigits];
    CLCD_private_voidNumberToDigits(Copy_u32Number, numberArray);

    for (u8 local_loopCounter = numberOfDigits; local_loopCounter > 0; local_loopCounter--){
        CLCD_voidSendData(numberArray[local_loopCounter -1]);
    }
}
