/*****************************************************************************/
/*****************************************************************************/
/**********************    Author : Mohamed Aburehab    **********************/
/**********************    SWD    : LIB                 **********************/
/**********************    Version: 1.0                 **********************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short int s16;

typedef unsigned long int u32;
typedef signed long int s32;

typedef float f32;
typedef double f64;

#define NULL 0

// Error states

#define NO_ERROR 1
#define ERROR_WRONG_FUNCTION_ARGUMENTS 2
#define ERROR_NULL_POINTER 3
#define ERROR_TIMEOUT 4
#define BUSY_FUNCTION 5 

#endif