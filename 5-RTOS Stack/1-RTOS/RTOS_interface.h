/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : RTOS Stack                      **********************/
/**********************    SWD    : RTOS                            **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_voidStart(void);

void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void));

void RTOS_voidSuspendTask(u8 Copy_Priority);
void RTOS_voidResumeTask(u8 Copy_Priority);
#endif