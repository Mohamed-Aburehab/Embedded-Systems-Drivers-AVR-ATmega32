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

/**
 * @brief It sets the callback function of the timer to the scheduler function, 
 * enables the global interrupt, and initializes the timer.
 */
void RTOS_voidStart(void);

/**
 * @brief It takes a priority, a periodicity, and a function pointer, 
 * and it creates a task with the given priority, periodicity, and function pointer
 * 
 * @param Copy_u8Priority The priority of the task.
 * @param Copy_u16Periodicity The time between each task execution.
 * @param Copy_pvTaskFunc is a pointer to the function that will be executed by the task.
 * @param Copy_u16FirstDelay the first delay before the task is being excuted to enhance the CPU load
 */
void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*Copy_pvTaskFunc)(void), u16 Copy_u16FirstDelay);

/**
 * @brief It sets the task state to suspended
 * 
 * @param Copy_Priority The priority of the task you want to suspend.
 */
void RTOS_voidSuspendTask(u8 Copy_Priority);

/**
 * @brief It resumes the task with the given priority.
 * 
 * @param Copy_Priority The priority of the task you want to resume.
 */
void RTOS_voidResumeTask(u8 Copy_Priority);

/**
 * @brief It deletes a task by setting it's task function pointer to NULL
 * 
 * @param Copy_Priority The priority of the task you want to delete.
 */
void RTOS_voidDeleteTask(u8 Copy_Priority);
#endif