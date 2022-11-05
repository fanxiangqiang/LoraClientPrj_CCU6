/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "DebugLog.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for LoraTread */
osThreadId_t LoraTreadHandle;
const osThreadAttr_t LoraTread_attributes = {
  .name = "LoraTread",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for LedBlinkThread */
osThreadId_t LedBlinkThreadHandle;
const osThreadAttr_t LedBlinkThread_attributes = {
  .name = "LedBlinkThread",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 256 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void LoraTask(void *argument);
void LedBlink(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of LoraTread */
  LoraTreadHandle = osThreadNew(LoraTask, NULL, &LoraTread_attributes);

  /* creation of LedBlinkThread */
  LedBlinkThreadHandle = osThreadNew(LedBlink, NULL, &LedBlinkThread_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_LoraTask */
/**
  * @brief  Function implementing the LoraTread thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_LoraTask */
void LoraTask(void *argument)
{
  /* USER CODE BEGIN LoraTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1000);

  }
  /* USER CODE END LoraTask */
}

/* USER CODE BEGIN Header_LedBlink */
/**
* @brief Function implementing the LedBlinkThread thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LedBlink */
void LedBlink(void *argument)
{
  /* USER CODE BEGIN LedBlink */
  /* Infinite loop */
  for(;;)
  {
	  HAL_GPIO_TogglePin(Led_PB3_GPIO_Port, Led_PB3_Pin);
	  osDelay(1000);
	  DBG("hello world %2f -\r\n",3.14);
  }
  /* USER CODE END LedBlink */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
