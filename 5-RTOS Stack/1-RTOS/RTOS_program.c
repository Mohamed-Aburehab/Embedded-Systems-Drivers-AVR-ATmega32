/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : RTOS Stack                      **********************/
/**********************    SWD    : RTOS                            **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#include "STD_TYPES.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"

#include "RTOS_interface.h"
#include "RTOS_config.h"
#include "RTOS_private.h"

Task_t SystemTasks[TASK_NUM] = {{NULL}};

void RTOS_voidStart(void){
    TIMER0_u8SetCallBackFuncOnCTC(&voidScheduler);
    GIE_voidEnable();
    TIMER0_voidInit(); 
}

void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void)){
    SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
    SystemTasks[Copy_u8Priority].TaskFunc = Copy_pvTaskFunc;
    SystemTasks[Copy_u8Priority].TaskState = TASK_STATE_RESUMED; 
}

static void voidScheduler(void){
    static u16 Local_u16TICKCounter = 0;
    u8 Local_u8TaskCounter;

    Local_u16TICKCounter ++;
    // loop on all tasks to check their periodicity
    for (Local_u8TaskCounter = 0 ; Local_u8TaskCounter < TASK_NUM ; Local_u8TaskCounter ++){
        if ((Local_u16TICKCounter % SystemTasks[Local_u8TaskCounter].Periodicity) == 0){
            // invoke the task function 
            if ((SystemTasks[Local_u8TaskCounter].TaskFunc != NULL) && (SystemTasks[Local_u8TaskCounter].TaskState == TASK_STATE_RESUMED)) {
                SystemTasks[Local_u8TaskCounter].TaskFunc();
            }
        }
    }
}

void RTOS_voidSuspendTask(u8 Copy_Priority){
    SystemTasks[Copy_Priority].TaskState = TASK_STATE_SUSPENED;
}

void RTOS_voidResumeTask(u8 Copy_Priority){
    SystemTasks[Copy_Priority].TaskState = TASK_STATE_RESUMED;
}
