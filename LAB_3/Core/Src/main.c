/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "software_timer.h"
//#include "led7_segment.h"
//#include "traffic_light.h"


#include "fsm_automatic.h"
#include "fsm_manual.h"


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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


//  int led7_freq1 = 0;
//  int led7_freq2 = 0;
//  int bien1 = 20;
//  int bien2 = 16;
//  int bien3 = 8;
//  int bien4 = 6;






//  int led_auto_buffer[3] = {5, 3, 2};
//  int time_red_copy = led_auto_buffer[0];
//  int time_green_copy = led_auto_buffer[1]; // chi lam vay de khai bao thoi
//  int time_yellow_copy = led_auto_buffer[2];
//  int led7_freq1 = 0;
//  int led7_freq2 = 0;




  status = INIT;
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


	  fsm_automatic_Run();
	  fsm_manual_Run();

//	  	if(button_flag[0] == 1 || button_flag[1] == 1 || button_flag[2] == 1)
//	  	{
//	  		button_flag[0] = 0;
//	  		button_flag[1] = 0;
//	  		button_flag[2] = 0;
//	  		HAL_GPIO_TogglePin(LED_TEST_GPIO_Port, LED_TEST_Pin);
//	  	}
//        if(timer_2hz_flag == 1)
//        {
//        	setTimer_2hz(25);
//        	HAL_GPIO_TogglePin(LED_TEST_GPIO_Port, LED_TEST_Pin);
//        }
//	  switch(status){
//		  case INIT:
//			  light_1(black);
//			  light_2(black);
////			  time_red_copy = led_auto_buffer[0];
////			  time_green_copy = led_auto_buffer[1];
////			  time_yellow_copy =led_auto_buffer[2];
//			  status = AUTO_RED_GREEN;
////			  setTimer_1s1(100);             // timer 1s
////			  setTimer_EN_GR1(freq1_led7);   // timer freg giua 2 con led7 cua 1 cum
//
//			  break;
//	  	  case AUTO_RED_GREEN:
//	  		  if(timer_EN_GR1_flag == 1)
//			  {
//				  setTimer_EN_GR1(25);
//				  switch(led7_freq1){
//					  case 0:
//						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
//						display_1(time_green_copy % 10);
//						led7_freq1 = 1;
//						break;
//					  case 1:
//						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
//						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//						display_1(time_green_copy / 10);
//						led7_freq1 = 0;
//						break;
//				  }
//				  switch(led7_freq2){
//					  case 0:
//						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
//						display_2(time_red_copy % 10);
//						led7_freq2 = 1;
//						break;
//					  case 1:
//						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
//						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
//						display_2(time_red_copy / 10);
//						led7_freq2 = 0;
//						break;
//				  }
//
//			  }
//			  if(timer1_1s_flag == 1)
//			  {
//				  setTimer_1s1(100);
//				  time_green_copy--;
//				  time_red_copy--;
//				  if(time_green_copy <= 0)
//				  {
//					  time_green_copy = led_auto_buffer[1];
//					  status = AUTO_RED_YELLOW;
//				  }
//			  }
//			  light_1(red);
//			  light_2(green);
//			  break;
//	  	  case AUTO_RED_YELLOW:
//	  		  if(timer_EN_GR1_flag == 1)
//			  {
//				  setTimer_EN_GR1(25);
//				  switch(led7_freq1){
//					  case 0:
//						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
//						display_1(time_yellow_copy % 10);
//						led7_freq1 = 1;
//						break;
//					  case 1:
//						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
//						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//						display_1(time_yellow_copy / 10);
//						led7_freq1 = 0;
//						break;
//				  }
//				  switch(led7_freq2){
//					  case 0:
//						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
//						display_2(time_red_copy % 10);
//						led7_freq2 = 1;
//						break;
//					  case 1:
//						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
//						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
//						display_2(time_red_copy / 10);
//						led7_freq2 = 0;
//						break;
//				  }
//			  }
//			  if(timer1_1s_flag == 1)
//			  {
//				  setTimer_1s1(100);
//				  time_yellow_copy--;
//				  time_red_copy--;
//				  if(time_yellow_copy <= 0 || time_red_copy <= 0)
//				  {
//					  time_yellow_copy = led_auto_buffer[2];
//					  time_red_copy = led_auto_buffer[0];
//					  status = AUTO_GREEN_RED;
//				  }
//			  }
//			  light_1(red);
//			  light_2(yellow);
//			  break;
//	  	  case AUTO_GREEN_RED:
//			  if(timer_EN_GR1_flag == 1)
//			  {
//				  setTimer_EN_GR1(25);
//				  switch(led7_freq1){
//					  case 0:
//						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
//						display_1(time_red_copy % 10);
//						led7_freq1 = 1;
//						break;
//					  case 1:
//						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
//						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//						display_1(time_red_copy / 10);
//						led7_freq1 = 0;
//						break;
//				  }
//				  switch(led7_freq2){
//					  case 0:
//						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
//						display_2(time_green_copy % 10);
//						led7_freq2 = 1;
//						break;
//					  case 1:
//						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
//						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
//						display_2(time_green_copy / 10);
//						led7_freq2 = 0;
//						break;
//				  }
//			  }
//			  if(timer1_1s_flag == 1)
//			  {
//				  setTimer_1s1(100);
//				  time_red_copy--;
//				  time_green_copy--;
//				  if(time_green_copy <= 0)
//				  {
//					  time_green_copy = led_auto_buffer[1];
//					  status = AUTO_YELLOW_RED;
//				  }
//			  }
//			  light_1(green);
//			  light_2(red);
//			  break;
//	  	  case AUTO_YELLOW_RED:
//			  if(timer_EN_GR1_flag == 1)
//			  {
//				  setTimer_EN_GR1(25);
//				  switch(led7_freq1){
//					  case 0:
//						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
//						display_1(time_red_copy % 10);
//						led7_freq1 = 1;
//						break;
//					  case 1:
//						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
//						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//						display_1(time_red_copy / 10);
//						led7_freq1 = 0;
//						break;
//				  }
//				  switch(led7_freq2){
//					  case 0:
//						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
//						display_2(time_yellow_copy % 10);
//						led7_freq2 = 1;
//						break;
//					  case 1:
//						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
//						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
//						display_2(time_yellow_copy / 10);
//						led7_freq2 = 0;
//						break;
//				  }
//			  }
//			  if(timer1_1s_flag == 1)
//			  {
//				  setTimer_1s1(100);
//				  time_red_copy--;
//				  time_yellow_copy--;
//				  if(time_red_copy <= 0 || time_yellow_copy <= 0)
//				  {
//					  time_red_copy = led_auto_buffer[0];
//					  time_yellow_copy = led_auto_buffer[2];
//					  status = AUTO_RED_GREEN;
//				  }
//			  }
//			  light_1(yellow);
//			  light_2(red);
//			  break;
//	  	  default:
//	  		  break;
//	  }









  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_TEST_Pin|GREEN_1_Pin|YELLOW_1_Pin|RED_1_Pin
                          |GREEN_2_Pin|YELLOW_2_Pin|RED_2_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin|EN4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG11_Pin|SEG12_Pin|SEG13_Pin
                          |SEG14_Pin|SEG15_Pin|SEG16_Pin|SEG1_Pin
                          |SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|SEG10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_TEST_Pin GREEN_1_Pin YELLOW_1_Pin RED_1_Pin
                           GREEN_2_Pin YELLOW_2_Pin RED_2_Pin EN1_Pin
                           EN2_Pin EN3_Pin EN4_Pin */
  GPIO_InitStruct.Pin = LED_TEST_Pin|GREEN_1_Pin|YELLOW_1_Pin|RED_1_Pin
                          |GREEN_2_Pin|YELLOW_2_Pin|RED_2_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin|EN4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG0_Pin SEG11_Pin SEG12_Pin SEG13_Pin
                           SEG14_Pin SEG15_Pin SEG16_Pin SEG1_Pin
                           SEG2_Pin SEG3_Pin SEG4_Pin SEG5_Pin
                           SEG6_Pin SEG10_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG11_Pin|SEG12_Pin|SEG13_Pin
                          |SEG14_Pin|SEG15_Pin|SEG16_Pin|SEG1_Pin
                          |SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|SEG10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BUTTON_1_Pin BUTTON_2_Pin BUTTON_3_Pin */
  GPIO_InitStruct.Pin = BUTTON_1_Pin|BUTTON_2_Pin|BUTTON_3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  timerRun();
  getKeyInput();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
