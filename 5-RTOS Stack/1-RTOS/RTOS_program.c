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

/**
 * @brief It sets the callback function of the timer to the scheduler function, 
 * enables the global interrupt, and initializes the timer.
 */
void RTOS_voidStart(void){
    TIMER0_u8SetCallBackFuncOnCTC(&voidScheduler);
    GIE_voidEnable();
    TIMER0_voidInit(); 
}

 * @param Copy_u8Priority The priority of the task.
 * @param Copy_u16Periodicity The time between each task execution.
 * @param Copy_pvTaskFunc is a pointer to the function that will be executed by the task.
 * @param Copy_u16FirstDelay the first delay before the task is being excuted to enhance the CPU load
 */
void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void), u16 Copy_u16FirstDelay){
    if (SystemTasks[Copy_u8Priority].TaskFunc == NULL){
        SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
        SystemTasks[Copy_u8Priority].TaskFunc = Copy_pvTaskFunc;
        SystemTasks[Copy_u8Priority].TaskState = TASK_STATE_RESUMED; 
        SystemTasks[Copy_u8Priority].TaskState = Copy_u16FirstDelay;
    }
}

/**
 * @brief The function loops on all tasks to check their periodicity, and if the task is resumed, 
 * it will be invoked.
 * 
 */
static void voidScheduler(void){
    u8 Local_u8TaskCounter;

    // loop on all tasks to check their periodicity
    for (Local_u8TaskCounter = 0 ; Local_u8TaskCounter < TASK_NUM ; Local_u8TaskCounter ++){
        if (SystemTasks[Local_u8TaskCounter].TaskState == TASK_STATE_RESUMED){
            if (SystemTasks[Local_u8TaskCounter].FirstDelay == 0){
                // invoke the task function 
                if ((SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)) {
                    SystemTasks[Local_u8TaskCounter].TaskFunc();
                    /*Assign the first delay parameter to Periodicity*/
                    SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].Periodicity -1;
                }
            }else {
                // decrement the first delay
                SystemTasks[Local_u8TaskCounter].FirstDelay --;
            }
        }
    }
}

/**
 * @brief It sets the task state to suspended
 * 
 * @param Copy_Priority The priority of the task you want to suspend.
 */
void RTOS_voidSuspendTask(u8 Copy_Priority){
    SystemTasks[Copy_Priority].TaskState = TASK_STATE_SUSPENED;
}

/**
 * @brief It resumes the task with the given priority.
 * 
 * @param Copy_Priority The priority of the task you want to resume.
 */
void RTOS_voidResumeTask(u8 Copy_Priority){
    SystemTasks[Copy_Priority].TaskState = TASK_STATE_RESUMED;
}

/**
 * @brief It deletes a task by setting it's task function pointer to NULL
 * 
 * @param Copy_Priority The priority of the task you want to delete.
 */
void RTOS_voidDeleteTask(u8 Copy_Priority){
    SystemTasks[Copy_u8Priority].TaskFunc = NULL;
}