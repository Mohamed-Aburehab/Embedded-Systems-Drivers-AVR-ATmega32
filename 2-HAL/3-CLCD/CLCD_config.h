/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : CLCD                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_
// choose between 4 and 8
#define CLCD_MODE                   8

#define CLCD_DATA_PORT              DIO_u8PORTA
// for 4 bit mode choose the data pins:
#define CLCD_DATA_PIN_7             DIO_u8PIN1
#define CLCD_DATA_PIN_6             DIO_u8PIN2
#define CLCD_DATA_PIN_5             DIO_u8PIN3
#define CLCD_DATA_PIN_4             DIO_u8PIN4

/* for 4 bit mode choose between: 
            1 for first  half of the port (Pins : 0, 1, 2, 3)
            2 for second half of the port (Pins : 4, 5, 6, 7)
*/

#define CLCD_DATA_PORT_PART         2

#define CLCD_CTRL_PORT              DIO_u8PORTC
#define CLCD_RS_PIN                 DIO_u8PIN0
#define CLCD_RW_PIN                 DIO_u8PIN1
#define CLCD_E_PIN                  DIO_u8PIN2

#endif
