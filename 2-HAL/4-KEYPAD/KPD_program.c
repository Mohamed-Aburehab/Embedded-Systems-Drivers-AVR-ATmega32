/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : KEYPAD              **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"
#include "KPD_interface.h"


u8 KPD_u8GetPressedKey(void){
    u8 Local_u8PressedKey, Local_u8ColumnIdx, Local_u8RowIdx, Local_u8PinState;
    Local_u8PressedKey = KPD_NO_PRESSED_KEY;

    static u8 Local_u8KPDArray[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = KPD_ARR_VAR;

    static u8 Local_u8KPDColumnArray [NUMBER_OF_COLUMNS] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
    static u8 Local_u8KPDRowArray [NUMBER_OF_COLUMNS] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};

    for(Local_u8ColumnIdx = 0; Local_u8ColumnIdx < NUMBER_OF_COLUMNS; Local_u8ColumnIdx++){
        // activate current column (set current column to low)
        DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColumnArray[Local_u8ColumnIdx], DIO_u8PIN_LOW);

        for(Local_u8RowIdx = 0; Local_u8RowIdx < NUMBER_OF_ROWS; Local_u8RowIdx++){
            // read the current row
            DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArray[Local_u8RowIdx], &Local_u8PinState);

            // check if key is pressed
            if(DIO_u8PIN_LOW == Local_u8PinState){
                Local_u8PressedKey = Local_u8KPDArray[Local_u8RowIdx][Local_u8ColumnIdx];
                // Polling until the key is released 
                while (DIO_u8PIN_LOW == Local_u8PinState){
                    DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArray[Local_u8RowIdx], &Local_u8PinState);
                }
                return Local_u8PressedKey;
            }
        }

        // deactivate the current column
        DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColumnArray[Local_u8ColumnIdx], DIO_u8PIN_HIGH);
    }

    return Local_u8PressedKey;
}
