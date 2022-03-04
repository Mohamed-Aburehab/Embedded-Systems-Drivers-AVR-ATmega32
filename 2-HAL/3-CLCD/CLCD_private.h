/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : CLCD                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

u8 private_u8GetnumberOfDigits(u32 Copy_u32Number){
    u8 local_u8Counter = 0;
    while (Copy_u32Number > 0){
        Copy_u32Number /= 10;
        local_u8Counter ++;
    }
    return local_u8Counter;
}

void private_voidNumberToDigits(u32 Copy_u32Number, char * array){
    u8 local_u8Counter = 0;
    while(Copy_u32Number > 0) {
        array[local_u8Counter] = 48 + (Copy_u32Number% 10);
        Copy_u32Number /= 10;
        local_u8Counter ++;
    }
}
