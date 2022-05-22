/*****************************************************************************************/
/*****************************************************************************************/
/**********************    Author : Mohamed Aburehab                **********************/
/**********************    Layer  : MCAL                            **********************/
/**********************    SWD    : EXTI (external interrupts)      **********************/
/**********************    Version: 1.0                             **********************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

// sense control states
#define LOW_LEVEL           1
#define LOGICAL_CHANGE      2
#define FALLING_EDGE        3
#define RISING_EDGE         4

//Interrupts IDS 
#define INT0                6
#define INT1                7
#define INT2                5

/**
  * @brief  : PreBuild initialize for INT0 
  * @param  : void
  * @return : void
*/
void EXTI_voidInt0Init(void);

/**
  * @brief  : PreBuild initialize for INT1
  * @param  : void
  * @return : void
*/
void EXTI_voidInt1Init(void);

/**
  * @brief  : PreBuild initialize for INT2
  * @param  : void
  * @return : void
*/
void EXTI_voidInt2Init(void);


/**
  * @brief  : post build initialize for INT0 sense controll 

  * @param  : sense controll option:    1 = LOW_LEVEL
                                        2 = LOGICAL_CHANGE
                                        3 = FALLING_EDGE
                                        4 = RISING_EDGE

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);

/**
  * @brief  : post build initialize for INT1 sense controll 

  * @param  : sense controll option:    1 = LOW_LEVEL
                                        2 = LOGICAL_CHANGE
                                        3 = FALLING_EDGE
                                        4 = RISING_EDGE

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);

/**
  * @brief  : post build initialize for INT2 sense controll 

  * @param  : sense controll option:    3 = FALLING_EDGE
                                        4 = RISING_EDGE

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);

/**
  * @brief  : make a Call Back for INT0 ISR 

  * @param  : Pointer to the INT0 ISR function

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));

/**
  * @brief  : make a Call Back for INT1 ISR 

  * @param  : Pointer to the INT0 ISR function

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void));

/**
  * @brief  : make a Call Back for INT2 ISR 

  * @param  : Pointer to the INT0 ISR function

  * @return : error state :             1 = NO_ERROR
                                        2 = ERROR_WRONG_FUNCTION_ARGUMENTS
                                        3 = ERROR_NULL_POINTER)
*/
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void));


u8 EXTI_u8DisableInterrupt(u8 Copy_INTERRUPT_ID);
#endif