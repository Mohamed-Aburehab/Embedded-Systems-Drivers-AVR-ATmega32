/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : KEYPAD              **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

// port configuration
#define KPD_PORT                    DIO_u8PORTA

// connection configuration
#define KPD_COLUMN0_PIN             DIO_u8PIN0
#define KPD_COLUMN1_PIN             DIO_u8PIN1
#define KPD_COLUMN2_PIN             DIO_u8PIN2
#define KPD_COLUMN3_PIN             DIO_u8PIN3

#define KPD_ROW0_PIN                DIO_u8PIN4
#define KPD_ROW1_PIN                DIO_u8PIN5
#define KPD_ROW2_PIN                DIO_u8PIN6
#define KPD_ROW3_PIN                DIO_u8PIN7

// no pressed buttons configuration
#define KPD_NO_PRESSED_KEY          0xFF

// keypad values configuration
#define KPD_ARR_VAR                 {{1,2,3,4},\
									{5,6,7,8},\
									{9,10,11,12},\
									{13,14,15,16}}



#endif
