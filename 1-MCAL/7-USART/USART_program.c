/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : USART (Universal serial communication)  **********************/
/**********************    Version: 1.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_register.h"
#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"

#if USART_2X_MODE == USART_DISABLE
#define UBRR_VAL (FOSC/16/USART_BAUD_RATE-1)
#elif USART_2X_MODE == USART_ENABLE
#define UBRR_VAL (FOSC/8/USART_BAUD_RATE-1)
#endif


/**
 * @brief initializes the USART module.
 */
void USART_voidInit(void){

    CLR_BIT(UCSRA, UCSRA_MPCM);
    CLR_BIT(UCSRA, UCSRA_U2X);
    /*setting the 2x mode option*/
	#if USART_2X_MODE == USART_DISABLE
	CLR_BIT(UCSRA, UCSRA_U2X);
	#elif USART_2X_MODE == USART_ENABLE
	SET_BIT(UCSRA, UCSRA_U2X);
	#endif

    /* Setting the baud rate. */

	u8 UBRRL_val = 0, UBRRH_val = 0;
	UBRRL_val = (UBRR_VAL & 0b00011111111) ;
	UBRRH_val = UBRR_VAL >> 8;
	UBRRL = UBRRL_val;
	UBRRH = UBRRH_val;

    u8 UCSRC_value;
    SET_BIT(UCSRC_value, UCSRC_URSEL);
    /* Setting the data size of the USART. */
    #if USART_DATA_SIZE == USART_DATA_8BIT
		SET_BIT(UCSRC_value, UCSRC_UCSZ0);
		SET_BIT(UCSRC_value, UCSRC_UCSZ1);
		CLR_BIT(UCSRB, UCSRB_UCSZ2);
    #elif USART_DATA_SIZE == USART_DATA_5BIT
        UCSRC = (1 << UCSRC_URSEL) | (0 << UCSRC_UCSZ1) | (0 << UCSRC_UCSZ0);
        CLR_BIT(UCSRC_value, UCSRC_UCSZ0);
        CLR_BIT(UCSRC_value, UCSRC_UCSZ1);
		CLR_BIT(UCSRB, UCSRB_UCSZ2);
    #elif USART_DATA_SIZE == USART_DATA_6BIT
        SET_BIT(UCSRC_value, UCSRC_UCSZ0);
        CLR_BIT(UCSRC_value, UCSRC_UCSZ1);
        CLR_BIT(UCSRB, UCSRB_UCSZ2);
    #elif USART_DATA_SIZE == USART_DATA_7BIT
        CLR_BIT(UCSRC_value, UCSRC_UCSZ0);
        SET_BIT(UCSRC_value, UCSRC_UCSZ1);
        CLR_BIT(UCSRB, UCSRB_UCSZ2);
    #elif USART_DATA_SIZE == USART_DATA_9BIT
        SET_BIT(UCSRC_value, UCSRC_UCSZ0);
        SET_BIT(UCSRC_value, UCSRC_UCSZ1);
        SET_BIT(UCSRB, UCSRB_UCSZ2);
    #endif

    /* Checking if the mode is Async or Sync. */
    #if USART_MODE == UART_ASYNC
        CLR_BIT(UCSRC_value, UCSRC_UMSEL);
    #elif USART_MODE == USART_SYNC
    	SET_BIT(UCSRC_value, UCSRC_UMSEL);
    #endif

    /* Setting the parity mode. */
    #if USART_PARITY_MODE == USART_PARITY_DISABLED
		CLR_BIT(UCSRC_value, UCSRC_UPM0);
		CLR_BIT(UCSRC_value, UCSRC_UPM1);
    #elif USART_PARITY_MODE == USART_PARITY_ENABLED_EVEN
		CLR_BIT(UCSRC_value, UCSRC_UPM0);
		SET_BIT(UCSRC_value, UCSRC_UPM1);
    #elif USART_PARITY_MODE == USART_PARITY_ENABLED_ODD
    	SET_BIT(UCSRC_value, UCSRC_UPM0);
    	SET_BIT(UCSRC_value, UCSRC_UPM1);
    #endif

    /* Checking if the stop bit size is 1 or 2. */
    #if USART_STOP_BIT_SIZE == USART_1_STOP_BIT
    	CLR_BIT(UCSRC_value, UCSRC_USBS);
    #elif USART_STOP_BIT_SIZE == USART_2_STOP_BIT
    	SET_BIT(UCSRC_value, UCSRC_USBS);
    #endif
    UCSRC = UCSRC_value;
    /* Checking if the RX mode is enabled or disabled. */
    #if USART_RX_MODE == USART_ENABLE
    SET_BIT(UCSRB, UCSRB_RXEN);
    #elif USART_RX_MODE == USART_DISABLE
    CLR_BIT(UCSRB, UCSRB_RXEN);
    #endif

    /* Checking if the TX mode is enabled or disabled. */
    #if USART_TX_MODE == USART_ENABLE
    SET_BIT(UCSRB, UCSRB_TXEN);
    #elif USART_TX_MODE == USART_DISABLE
    CLR_BIT(UCSRB, UCSRB_TXEN);
    #endif

}

/**
 * @brief sending data using usart.
 * 
 * @param Copy_u8Data The data to be sent.
 */
void USART_voidSendData(u8 Copy_u8Data){
    /* waiting until Register Empty Flag is set*/
    while (GET_BIT(UCSRA, UCSRA_UDRE) == 0);
    UDR = Copy_u8Data;
}

/**
 * @brief Wait until the receive flag is set, then return the data register.
 * 
 * @return The value of the UDR register.
 */
u8 USART_u8ReceiveData(void){
    while (GET_BIT(UCSRA, UCSRA_RXC) == 0);
    return UDR;
}

void USART_voidSendString(const char * Copy_pcString){
	u8 Local_u8StringCounter = 0;
	while(Copy_pcString[Local_u8StringCounter] != '\0'){
		USART_voidSendData(Copy_pcString[Local_u8StringCounter]);
	        Local_u8StringCounter ++;
	    }
}
