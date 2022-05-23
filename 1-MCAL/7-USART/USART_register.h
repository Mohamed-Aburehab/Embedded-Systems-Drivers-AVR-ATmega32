/*************************************************************************************************/
/*************************************************************************************************/
/**********************    Author : Mohamed Aburehab                        **********************/
/**********************    Layer  : MCAL                                    **********************/
/**********************    SWD    : USART (Universal serial communication)  **********************/
/**********************    Version: 1.0                                     **********************/
/*************************************************************************************************/
/*************************************************************************************************/

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_
/******************************************
USART I/O Data Register 
-----------------------------------------
|               RXB[7:0]                |
-----------------------------------------
-----------------------------------------
|               TXB[7:0]                |
-----------------------------------------
******************************************/
#define UDR                         *((volatile u8*)0x2C)

/******************************************
USART Control and Status Register A 
---------------------------------
|RXC|TXC|UDRE|FE|DOR|PE|U2X|MPCM|
---------------------------------
******************************************/
#define UCSRA                       *((volatile u8*)0x2B)
#define UCSRA_RXC                           7               // USART Receive Complete Flag
#define UCSRA_TXC                           6               // USART Transmit Complete Flag
#define UCSRA_UDRE                          5               // USART Data Register Empty Flag
#define UCSRA_FE                            4               // Frame Error Flag
#define UCSRA_DOR                           3               // Data OverRun Error Flag 
#define UCSRA_PE                            2               // Parity Error Flag
#define UCSRA_U2X                           1               // Double the USART Transmission Speed
#define UCSRA_MPCM                          0               // Multi-processor Communication Mode

/******************************************
USART Control and Status Register B 
---------------------------------------------
|RXCIE|TXCIE|UDRIE|RXEN|TXEN|UCSZ2|RXB8|TXB8|
---------------------------------------------
******************************************/
#define UCSRB                       *((volatile u8*)0x2A)
#define UCSRB_RXCIE                         7               // USART RX Complete Interrupt Enable
#define UCSRB_TXCIE                         6               // USART TX Complete Interrupt Enable
#define UCSRB_UDRIE                         5               // USART  Data Register Empty Interrupt Enable
#define UCSRB_RXEN                          4               // USART Receiver Enable
#define UCSRB_TXEN                          3               // USART Transmitter Enable 
#define UCSRB_UCSZ2                         2               // Character Size
#define UCSRB_RXB8                          1               // USART Receive Data Bit 8
#define UCSRB_TXB8                          0               // USART Transmit Data Bit 8

/******************************************
USART Control and Status Register C 
---------------------------------------------
|URSEL|UMSEL|UPM1|UPM0|USBS|UCSZ1|UCSZ0|UCPOL|
---------------------------------------------
******************************************/
#define UCSRC                       *((volatile u8*)0x40)   // ! same address as UBRRH
#define UCSRC_URSEL                         7               // Register Select 
#define UCSRC_UMSEL                         6               // USART Mode Select (UART/ USART)
#define UCSRC_UPM1                          5               // USART Parity Mode
#define UCSRC_UPM0                          4               // USART Parity Mode
#define UCSRC_USBS                          3               // USART Stop Bit Select 
#define UCSRC_UCSZ1                         2               // Character Size
#define UCSRC_UCSZ0                         1               // Character Size
#define UCSRC_UCPOL                         0               // USART Clock Polarity

/******************************************
USART Baud Rate Registers High (UBRRH) 
--------------------------------------
|URSEL|     |      |      |UBRR[11:8]|
--------------------------------------
******************************************/
#define UBRRH                       *((volatile u8*)0x40)   // ! same address as UCSRC
#define UBRRH_URSEL                        7               // Register Select 
#define UBRRH_UBRR8                        0               // USART Baud Rate Register Bit 8 
#define UBRRH_UBRR9                        1               // USART Baud Rate Register Bit 9
#define UBRRH_UBRR10                       2               // USART Baud Rate Register Bit 10
#define UBRRH_UBRR11                       3               // USART Baud Rate Register Bit 11

/******************************************
USART Baud Rate Registers Low (UBRRL) 
------------------------------------------------
UBRR7|UBRR5|UBRR5|UBRR4|UBRR3|UBRR2|UBRR1|UBRR0|
------------------------------------------------
******************************************/
#define UBRRL                       *((volatile u8*)0x29)  
#define UBRRL_URSEL                        7               // Register Select 
#define UBRRL_UBRR0                        0               // USART Baud Rate Register Bit 0 
#define UBRRL_UBRR1                        1               // USART Baud Rate Register Bit 1 
#define UBRRL_UBRR2                        2               // USART Baud Rate Register Bit  2
#define UBRRL_UBRR3                        3               // USART Baud Rate Register Bit 3 
#define UBRRL_UBRR4                        4               // USART Baud Rate Register Bit 4 
#define UBRRL_UBRR5                        5               // USART Baud Rate Register Bit 5 
#define UBRRL_UBRR6                        6               // USART Baud Rate Register Bit 6 
#define UBRRL_UBRR7                        7               // USART Baud Rate Register Bit 7 

#endif