/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : MCAL                **********************/
/**********************    SWD    : DIO                 **********************/
/**********************    Version: 2.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

// values
#define DIO_u8PIN_HIGH          1
#define DIO_u8PIN_LOW           0
#define DIO_u8PORT_HIGH         0xFF
#define DIO_u8PORT_LOW          0x00

// ports
#define DIO_u8PORTA             0
#define DIO_u8PORTB             1
#define DIO_u8PORTC             2
#define DIO_u8PORTD             3

// pins
#define DIO_u8PIN0              0
#define DIO_u8PIN1              1
#define DIO_u8PIN2              2
#define DIO_u8PIN3              3
#define DIO_u8PIN4              4
#define DIO_u8PIN5              5
#define DIO_u8PIN6              6
#define DIO_u8PIN7              7

/**
  * @brief  : set pin value in a specific port 

  * @param  : Port name:                0 = DIO_u8PORTA
                                        1 = DIO_u8PORTB
                                        2 = DIO_u8PORTC
                                        3 = DIO_u8PORTD

  * @param  : pin name:                 0 = DIO_u8PIN0
                                        1 = DIO_u8PIN1
                                        2 = DIO_u8PIN2
                                        3 = DIO_u8PIN3
                                        4 = DIO_u8PIN4
                                        5 = DIO_u8PIN5
                                        6 = DIO_u8PIN6
                                        7 = DIO_u8PIN7

  * @param  : pin value:                0 = DIO_u8PIN_LOW
                                        1 = DIO_u8PIN_HIGH

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8Value);

/**
  * @brief  : set full port value 

  * @param  : Port name:                0 = DIO_u8PORTA
                                        1 = DIO_u8PORTB
                                        2 = DIO_u8PORTC
                                        3 = DIO_u8PORTD

  * @param  : port value:               0x00 = DIO_u8PORT_LOW
                                        0xFF = DIO_u8PORT_HIGH
                                        0xXX = for a specific port value 

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

/**
  * @brief  : get pin value 

  * @param  : Port name:                0 = DIO_u8PORTA
                                        1 = DIO_u8PORTB
                                        2 = DIO_u8PORTC
                                        3 = DIO_u8PORTD

  * @param  : pin name:                 0 = DIO_u8PIN0
                                        1 = DIO_u8PIN1
                                        2 = DIO_u8PIN2
                                        3 = DIO_u8PIN3
                                        4 = DIO_u8PIN4
                                        5 = DIO_u8PIN5
                                        6 = DIO_u8PIN6
                                        7 = DIO_u8PIN7

  * @param  : memmory address to the pin value in 

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 * Copy_pu8Value);

#endif