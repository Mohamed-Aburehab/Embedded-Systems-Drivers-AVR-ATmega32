/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : CLCD                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/


void CLCD_private_voidSetDataPortForHigherOrder(u8 Copy_u8Command,u8 Copy_CLCD_DATA_PORT, u8 Copy_CLCD_DATA_PORT_PART){
    switch (Copy_CLCD_DATA_PORT_PART)
    {
    case 1:
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN0, GET_BIT(Copy_u8Command,7));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN1, GET_BIT(Copy_u8Command,6));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN2, GET_BIT(Copy_u8Command,5));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN3, GET_BIT(Copy_u8Command,4));
        break;
    case 2:
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN7, GET_BIT(Copy_u8Command,7));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN6, GET_BIT(Copy_u8Command,6));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN5, GET_BIT(Copy_u8Command,5));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN4, GET_BIT(Copy_u8Command,4));
        break;
    
    default:
        break;
    }
}

void CLCD_private_voidSetDataPortForLowerOrder(u8 Copy_u8Command, u8 Copy_CLCD_DATA_PORT, u8 Copy_CLCD_DATA_PORT_PART){
    switch (Copy_CLCD_DATA_PORT_PART)
    {
    case 1:
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN0, GET_BIT(Copy_u8Command,3));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN1, GET_BIT(Copy_u8Command,2));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN2, GET_BIT(Copy_u8Command,1));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN3, GET_BIT(Copy_u8Command,0));
        break;
    case 2:
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN7, GET_BIT(Copy_u8Command,3));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN6, GET_BIT(Copy_u8Command,2));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN5, GET_BIT(Copy_u8Command,1));
        DIO_u8SetPinValue(Copy_CLCD_DATA_PORT, DIO_u8PIN4, GET_BIT(Copy_u8Command,0));
        break;
    
    default:
        break;
    }
}

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
