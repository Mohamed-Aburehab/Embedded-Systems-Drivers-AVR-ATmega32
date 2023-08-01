/*********************************************************************************/
/*********************************************************************************/
/**********************    Author : Mohamed Aburehab        **********************/
/**********************    Layer  : APP                     **********************/
/**********************    SWD    : Traffic Light System    **********************/
/**********************    Version: 1.0                     **********************/
/*********************************************************************************/
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>

/*
 * This program blinks three LEDs in a sequence of red, yellow, and green.
 * The LEDs are connected to pins A0, A1, and A2 on the microcontroller.
 */

int main(void)
{
	/* Initialize pins A0, A1, and A2 as output. */
	PORT_voidInit();

	while (1)
	{
		/* Turn on the red LED for 10 seconds. */
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
		_delay_ms(10000);

		/* Turn off the red LED. */
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);

		/* Turn on the yellow LED for 3 seconds. */
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_HIGH);
		_delay_ms(3000);

		/* Turn off the yellow LED. */
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_LOW);

		/* Turn on the green LED for 10 seconds. */
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_HIGH);
		_delay_ms(10000);

		/* Turn off the green LED. */
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN2, DIO_u8PIN_LOW);
	}

	return 0;
}
