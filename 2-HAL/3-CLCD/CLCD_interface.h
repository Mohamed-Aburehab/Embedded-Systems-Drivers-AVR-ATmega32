/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : CLCD                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendString(const char * Copy_pcString);


void CLCD_voidGoToXY(u8 Copy_u8XPosition, u8 Copy_u8YPosition);

void CLCD_voidWriteSpecialCharacter(u8 * Copy_pu8SpecialCharacterArray, u8 Copy_u8BlockNumber,
                                    u8 Copy_u8XPosition, u8 Copy_u8YPosition);

void CLCD_voidWriteNumber(u32 Copy_u32Number);

#define CLCD_CLR_DISPLAY CLCD_voidSendCommand(1)
#endif
