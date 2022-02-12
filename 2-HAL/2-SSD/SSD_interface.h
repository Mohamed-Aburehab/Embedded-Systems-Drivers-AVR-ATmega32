/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    Layer  : HAL                 **********************/
/**********************    SWD    : SSD                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

// error state
#define NO_ERROR                        0
#define ERROR_WRONG_FUNCTION_ARGUMENTS  1
#define ERROR_NULL_POINTER              2

// common types
#define SSD_COMMON_CATHODE                  0
#define SSD_COMMON_ANODE                    1

// 7 segment data struct
typedef struct {
    u8 commonType;
    u8 port;
    u8 enablePort;
    u8 enablePin;
} SSD_T;


u8 SSD_u8SetNumber(u8 Copy_u8Number,SSD_T * Copy_pSSD_T);

#endif