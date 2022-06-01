/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : USART (Universal serial communication)  **********************/
/**********************    Version: 2.0                                     **********************/
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

u8 USART_u8BusyState = USART_BUSY_STATE_IDLE;
static u8 USART_u8ISRsource;

/* Send Char Asynch globals */
static void (*USART_pvCallBackNotificationFuncSendChar)(void) = NULL;
static u8 USART_Global_u8CharToBeSent;
/* Send String Asynch globals */
static void (*USART_pvCallBackNotificationFuncSendString)(void) = NULL;
static char * USART_Global_pcString = NULL;
static u8 USART_Global_stringIndex = 0;
/* Receive Char Asynch globals */
static void (*USART_pvCallBackNotificationFuncReceiveChar)(void) = NULL;
static char * Global_pcReceivedChar = NULL;
/* Receive Buffer Asynch globals */
static void (*USART_pvCallBackNotificationFuncRECEIVE_BUFFER)(void) = NULL;
static char * Global_pcReceivedBuffer = NULL;
static u8 USART_Global_u8BufferSize ;
static u8 USART_Global_BufferIndex = 0;

/**
 * @brief initializes the USART peripheral.
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
 * @brief It sends a character synchronously
 * 
 * @param Copy_u8Data The data to be sent.
 * 
 * @return the error state of the function.
 */
u8 USART_u8SendCharSynch(u8 Copy_u8Data){
    /* A local variable that is used to store the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* A variable that is used to control time waited */
    u32 Local_u32TimeOutCounter = 0;
    if(USART_u8BusyState == USART_BUSY_STATE_IDLE){
        /* waiting until Register Empty Flag is set or timeout happens*/
        while (GET_BIT(UCSRA, UCSRA_UDRE) == 0){
            Local_u32TimeOutCounter ++;
            if (Local_u32TimeOutCounter == USART_TIMEOUT){
                Local_u8ErrorState = ERROR_TIMEOUT;
                break;
            }
        }
        if (Local_u8ErrorState == NO_ERROR){
            UDR = Copy_u8Data;
            }
    }
    else if (USART_u8BusyState == USART_BUSY_STATE_BUSY){
        Local_u8ErrorState = BUSY_FUNCTION;
    }

    return Local_u8ErrorState;
}

/**
 * @brief It receives a character from the UART.
 * 
 * @param Copy_pu8ReceivedChar pointer to the variable that will store the received character.
 * 
 * @return the error state of the function.
 */
u8 USART_u8ReceiveCharSynch(u8 * Copy_pu8ReceivedChar){
    /* A local variable that is used to store the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* A variable that is used to control time waited */
    u32 Local_u32TimeOutCounter = 0;
    if (Copy_pu8ReceivedChar != NULL){
        if(USART_u8BusyState == USART_BUSY_STATE_IDLE){
            while (GET_BIT(UCSRA, UCSRA_RXC) == 0){
            /* waiting until Receive Complete Flag is set or timeout happens*/
            Local_u32TimeOutCounter ++;
            if (Local_u32TimeOutCounter == USART_TIMEOUT){
                Local_u8ErrorState = ERROR_TIMEOUT;
                break;
            }
        }
        if (Local_u8ErrorState == NO_ERROR){
            Copy_pu8ReceivedChar = UDR;
        }

        }
        else if (USART_u8BusyState == USART_BUSY_STATE_BUSY){
            Local_u8ErrorState == BUSY_FUNCTION;
        }
    }
    else if (Copy_pu8ReceivedChar == NULL){
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }

    return Local_u8ErrorState;
}

/**
 * @brief It sends a string of characters to the USART peripheral
 * 
 * @param Copy_pcString A pointer to the string to be sent.
 * 
 * @return The error state of the function.
 */
u8 USART_u8SendStringSynch(char * Copy_pcString){
    /* A local variable that is used to store the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* A local variable that is used to store current index of char to be sent. */
	u8 Local_u8StringCounter = 0;

    if (Copy_pcString != NULL){
        while(Copy_pcString[Local_u8StringCounter] != '\0'){
            Local_u8ErrorState = USART_voidSendCharSynch(Copy_pcString[Local_u8StringCounter]);
            Local_u8StringCounter ++;
            if (Local_u8ErrorState != NO_ERROR){
                break;
            }
        }
    }
    else if (Copy_pcString == NULL){
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }

    return Local_u8ErrorState;
}

/**
 * @brief It receives a buffer of characters from the UART and stores them in the passed buffer
 * 
 * @param Buffer Pointer to the buffer that will store the received data.
 * @param Copy_u8BufferSize The size of the buffer that you want to receive.
 * 
 * @return the error state of the function.
 */
u8 USART_u8ReceiveBufferSynch(u8 * Buffer, u8 Copy_u8BufferSize){
    /* A local variable that is used to store the error state of the function. */
    u8 Local_u8ErrorState = NO_ERROR;
    /* A local variable that is used to store the current index of buffer. */
    u8 Local_u8BufferCounter = 0;
    if (Buffer != NULL){
        while(Local_u8BufferCounter < Copy_u8BufferSize){
            Local_u8ErrorState = USART_u8ReceiveCharSynch(&Buffer[Local_u8BufferCounter]);
            Local_u8BufferCounter ++;
            if (Local_u8ErrorState != NO_ERROR){
                break;
            }
        }
    }
    else if (Buffer == NULL){
        Local_u8ErrorState = ERROR_NULL_POINTER;
    }

    return Local_u8ErrorState;
}


/**
 * @brief It takes a character and a pointer to a function as arguments, and sends the character
 * asynchronously.
 * 
 * @param Copy_u8Data The data to be sent
 * @param Copy_PvNotificationFunc pointer to function that will be called when the interrupt is fired.
 * 
 * @return the error state of the function.
 */
u8 USART_u8SendCharAsynch(u8 Copy_u8Data, void(*Copy_PvNotificationFunc)(void)){
    u8 Local_u8ErrorState = NO_ERROR;
    if(USART_u8BusyState == USART_BUSY_STATE_IDLE){
        if (Copy_PvNotificationFunc != NULL){
            USART_u8BusyState = USART_BUSY_STATE_BUSY;
            USART_pvCallBackNotificationFuncSendChar = Copy_PvNotificationFunc;
            USART_u8ISRsource = USART_ISR_SEND_CHAR_ASYNCH;
            USART_Global_u8CharToBeSent = Copy_u8Data;
            /* Enable Data Register Empty Interrupt */
            SET_BIT(UCSRB, UCSRB_UDRIE);
        }
        else if (Copy_PvNotificationFunc == NULL){
            Local_u8ErrorState = ERROR_NULL_POINTER;
        }
    }
    else if (USART_u8BusyState == USART_BUSY_STATE_BUSY){
        Local_u8ErrorState == BUSY_FUNCTION;
    }
    return Local_u8ErrorState;
}

/**
 * It takes a string and a pointer to a function and sends the string asynchronously
 * 
 * @param Copy_pcString pointer to the string to be sent
 * @param Copy_PvNotificationFunc is a pointer to a function that will be called when the string is
 * sent.
 * 
 * @return the error state of the function.
 */
u8 USART_u8SendStringAsynch(char * Copy_pcString, void(*Copy_PvNotificationFunc)(void)){
    u8 Local_u8ErrorState = NO_ERROR;
    if(USART_u8BusyState == USART_BUSY_STATE_IDLE){
        if (Copy_PvNotificationFunc != NULL && Copy_pcString != NULL){
            USART_u8BusyState = USART_BUSY_STATE_BUSY;
            USART_pvCallBackNotificationFuncSendString = Copy_PvNotificationFunc;
            USART_Global_pcString = Copy_pcString;
            USART_u8ISRsource = USART_ISR_SEND_STRING_ASYNCH;
            USART_Global_stringIndex = 0;
            /* Enable Data Register Empty Interrupt */
            SET_BIT(UCSRB, UCSRB_UDRIE);

        }
        else if (Copy_PvNotificationFunc == NULL || Copy_pcString == NULL){
            Local_u8ErrorState = ERROR_NULL_POINTER;
        }
    }
    else if (USART_u8BusyState == USART_BUSY_STATE_BUSY){
        Local_u8ErrorState == BUSY_FUNCTION;
    }
    return Local_u8ErrorState;

}

/**
 * @brief It takes a pointer to a function and a pointer to a variable, and then it sets the global variable
 * to the value of the pointer to the variable, and then it calls the function that the pointer to the
 * function points to
 * 
 * @param Copy_pu8ReceivedChar pointer to the variable that will hold the received character
 * @param Copy_PvNotificationFunc is a pointer to a function that will be called when the interrupt is
 * triggered.
 * 
 * @return the error state of the function.
 */
u8 USART_u8ReceiveCharAsynch(u8 * Copy_pu8ReceivedChar ,void(*Copy_PvNotificationFunc)(void)){
    u8 Local_u8ErrorState = NO_ERROR;
    if(USART_u8BusyState == USART_BUSY_STATE_IDLE){
        if (Copy_PvNotificationFunc != NULL && Copy_pu8ReceivedChar != NULL){
            USART_u8BusyState = USART_BUSY_STATE_BUSY;
            USART_u8ISRsource = USART_ISR_RECEIVE_CHAR_ASYNCH;
            USART_pvCallBackNotificationFuncReceiveChar = Copy_PvNotificationFunc();
            Global_pcReceivedChar = Copy_pu8ReceivedChar;
            /* Enable RX Complete Interrupt */
            SET_BIT(UCSRB, UCSRB_RXCIE);
        }
        else if (Copy_PvNotificationFunc == NULL || Copy_pu8ReceivedChar == NULL){
            Local_u8ErrorState = ERROR_NULL_POINTER;
        }
    }
    else if (USART_u8BusyState == USART_BUSY_STATE_BUSY){
        Local_u8ErrorState == BUSY_FUNCTION;
    }
    return Local_u8ErrorState;

}

/**
 * It receives a buffer of data asynchronously and calls a callback function when the buffer is full
 * 
 * @param Buffer pointer to the buffer that will hold the received data
 * @param Copy_u8BufferSize The size of the buffer that will be received.
 * @param Copy_PvNotificationFunc is a pointer to a function that will be called when the buffer is
 * full.
 * 
 * @return the error state of the function.
 */
u8 USART_u8ReceiveBufferAsynch(u8 * Buffer, u8 Copy_u8BufferSize, void(*Copy_PvNotificationFunc)(void)){
    u8 Local_u8ErrorState = NO_ERROR;
    if(USART_u8BusyState == USART_BUSY_STATE_IDLE){
        if (Copy_PvNotificationFunc != NULL && Buffer != NULL){
            USART_u8BusyState = USART_BUSY_STATE_BUSY;
            USART_u8ISRsource = ISART_ISR_RECEIVE_BUFFER_ASYNCH;
            USART_pvCallBackNotificationFuncRECEIVE_BUFFER = Copy_PvNotificationFunc;
            Global_pcReceivedBuffer = Buffer;
            USART_Global_u8BufferSize = Copy_u8BufferSize;
            USART_Global_BufferIndex = 0;

            /* Enable RX Complete Interrupt */
            SET_BIT(UCSRB, UCSRB_RXCIE);
        }
        else if (Copy_PvNotificationFunc == NULL || Buffer == NULL){
            Local_u8ErrorState = ERROR_NULL_POINTER;
        }
    }
    else if (USART_u8BusyState == USART_BUSY_STATE_BUSY){
        Local_u8ErrorState == BUSY_FUNCTION;
    }
    return Local_u8ErrorState;

}

/* USART, Rx Complete ISR */
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void){
    if(USART_u8ISRsource == USART_ISR_RECEIVE_CHAR_ASYNCH){
        USART_u8BusyState = USART_BUSY_STATE_IDLE;
        *(Global_pcReceivedChar) = UDR;
        USART_pvCallBackNotificationFuncReceiveChar();
        /* Disable RX Complete Interrupt */
        CLR_BIT(UCSRB, UCSRB_RXCIE);
    }
    else if (USART_u8ISRsource == ISART_ISR_RECEIVE_BUFFER_ASYNCH){
        if (USART_Global_BufferIndex < USART_Global_u8BufferSize){
            Global_pcReceivedBuffer[USART_Global_BufferIndex] = UDR;
            USART_Global_BufferIndex ++;
        }
        else if (USART_Global_BufferIndex == USART_Global_u8BufferSize){
            USART_u8BusyState = USART_BUSY_STATE_IDLE;
            USART_Global_BufferIndex =0;
            USART_pvCallBackNotificationFuncRECEIVE_BUFFER();
            /* Disable RX Complete Interrupt */
            CLR_BIT(UCSRB, UCSRB_RXCIE);
        }
    }

}
/*  USART Data Register Empty ISR */
void __vector_14 (void) __attribute__((signal));
void __vector_14 (void){
    if (USART_u8ISRsource == USART_ISR_SEND_CHAR_ASYNCH){
        /* Enable TX complete interrupt */
        SET_BIT(UCSRB, UCSRB_TXCIE);
        UDR = USART_Global_u8CharToBeSent;

        /* Disable Data Register Empty interrupt */
        CLR_BIT(UCSRB, UCSRB_UDRIE);
    }
    else if (USART_u8ISRsource == USART_ISR_SEND_STRING_ASYNCH){
        if (USART_Global_pcString[USART_Global_stringIndex] != '\0'){
            UDR = USART_Global_pcString[USART_Global_stringIndex];
            USART_Global_stringIndex++;
        }
        else if (USART_Global_pcString[USART_Global_stringIndex] == '\0'){
            /* Enable TX complete interrupt */
            SET_BIT(UCSRB, UCSRB_TXCIE);
            /* Disable Data Register Empty interrupt */
            CLR_BIT(UCSRB, UCSRB_UDRIE);
        }
    }
}

/*  USART, Tx Complete ISR */
void __vector_15 (void) __attribute__((signal));
void __vector_15 (void){
    if (USART_u8ISRsource == USART_ISR_SEND_CHAR_ASYNCH){
        USART_u8BusyState = USART_BUSY_STATE_IDLE;
        USART_pvCallBackNotificationFuncSendChar();
        
        /* Disable TX complete interrupt */
        CLR_BIT(UCSRB, UCSRB_TXCIE);
    }
    else if (USART_u8ISRsource == USART_ISR_SEND_STRING_ASYNCH){
        USART_u8BusyState = USART_BUSY_STATE_IDLE;
        USART_pvCallBackNotificationFuncSendString();
        USART_Global_stringIndex = 0;
        /* Disable TX complete interrupt */
        CLR_BIT(UCSRB, UCSRB_TXCIE);

    }
}