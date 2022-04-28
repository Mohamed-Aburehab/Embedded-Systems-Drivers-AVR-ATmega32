/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : CLCD                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

//void CLCD_private_voidSetDataPortForHigherOrder(u8 Copy_u8Command,u8 Copy_CLCD_DATA_PORT, u8 Copy_CLCD_DATA_PORT_PART){
//    DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, CLCD_DATA_PIN_7, GET_BIT(Copy_u8Command,7));
//    DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, CLCD_DATA_PIN_6, GET_BIT(Copy_u8Command,6));
//    DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, CLCD_DATA_PIN_5, GET_BIT(Copy_u8Command,5));
//    DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, CLCD_DATA_PIN_4, GET_BIT(Copy_u8Command,4));
//}
//
//void CLCD_private_voidSetDataPortForLowerOrder(u8 Copy_u8Command, u8 Copy_CLCD_DATA_PORT, u8 Copy_CLCD_DATA_PORT_PART){
//    DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, CLCD_DATA_PIN_7, GET_BIT(Copy_u8Command,3));
//    DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, CLCD_DATA_PIN_6, GET_BIT(Copy_u8Command,2));
//    DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, CLCD_DATA_PIN_5, GET_BIT(Copy_u8Command,1));
//    DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, CLCD_DATA_PIN_4, GET_BIT(Copy_u8Command,0));
//
//}

u8 CLCD_private_u8GetnumberOfDigits(u32 Copy_u32Number){
    u8 local_u8Counter = 0;
    while (Copy_u32Number > 0){
        Copy_u32Number /= 10;
        local_u8Counter ++;
    }
    return local_u8Counter;
}

void CLCD_private_voidNumberToDigits(u32 Copy_u32Number, char * array){
    u8 local_u8Counter = 0;
    while(Copy_u32Number > 0) {
        array[local_u8Counter] = 48 + (Copy_u32Number% 10);
        Copy_u32Number /= 10;
        local_u8Counter ++;
    }
}
