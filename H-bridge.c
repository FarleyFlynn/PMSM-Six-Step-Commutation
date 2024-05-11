#include "main.h"
TIM_HandleTypeDef htim2;
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
volatile uint16_t numberS=1000;
uint16_t i0=0;

const uint16_t tabT[1000]={
361, 363, 365, 367, 369, 371, 373, 375, 377, 379, 381, 383, 385, 387, 389, 391, 393, 395, 397, 399, 
401, 403, 405, 407, 409, 411, 413, 415, 417, 419, 421, 423, 425, 427, 429, 431, 433, 435, 437, 439, 
441, 443, 444, 446, 448, 450, 452, 454, 456, 458, 460, 462, 464, 466, 467, 469, 471, 473, 475, 477, 
479, 481, 482, 484, 486, 488, 490, 492, 494, 495, 497, 499, 501, 503, 504, 506, 508, 510, 511, 513, 
515, 517, 519, 520, 522, 524, 525, 527, 529, 531, 532, 534, 536, 537, 539, 541, 542, 544, 546, 547, 
549, 551, 552, 554, 555, 557, 559, 560, 562, 563, 565, 566, 568, 569, 571, 572, 574, 575, 577, 578, 
580, 581, 583, 584, 586, 587, 588, 590, 591, 593, 594, 595, 597, 598, 599, 601, 602, 603, 605, 606, 
607, 608, 610, 611, 612, 613, 615, 616, 617, 618, 619, 621, 622, 623, 624, 625, 626, 627, 629, 630, 
631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 646, 647, 648, 649, 
650, 651, 652, 652, 653, 654, 655, 656, 656, 657, 658, 659, 659, 660, 661, 661, 662, 663, 663, 664, 
665, 665, 666, 667, 667, 668, 668, 669, 669, 670, 670, 671, 671, 672, 672, 673, 673, 673, 674, 674, 
675, 675, 675, 676, 676, 676, 677, 677, 677, 677, 678, 678, 678, 678, 678, 679, 679, 679, 679, 679, 
679, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 679, 
679, 679, 679, 679, 679, 678, 678, 678, 678, 678, 677, 677, 677, 677, 676, 676, 676, 675, 675, 675, 
674, 674, 673, 673, 673, 672, 672, 671, 671, 670, 670, 669, 669, 668, 668, 667, 667, 666, 665, 665, 
664, 663, 663, 662, 661, 661, 660, 659, 659, 658, 657, 656, 656, 655, 654, 653, 652, 652, 651, 650, 
649, 648, 647, 646, 646, 645, 644, 643, 642, 641, 640, 639, 638, 637, 636, 635, 634, 633, 632, 631, 
630, 629, 627, 626, 625, 624, 623, 622, 621, 619, 618, 617, 616, 615, 613, 612, 611, 610, 608, 607, 
606, 605, 603, 602, 601, 599, 598, 597, 595, 594, 593, 591, 590, 588, 587, 586, 584, 583, 581, 580, 
578, 577, 575, 574, 572, 571, 569, 568, 566, 565, 563, 562, 560, 559, 557, 555, 554, 552, 551, 549, 
547, 546, 544, 542, 541, 539, 537, 536, 534, 532, 531, 529, 527, 525, 524, 522, 520, 519, 517, 515, 
513, 511, 510, 508, 506, 504, 503, 501, 499, 497, 495, 494, 492, 490, 488, 486, 484, 482, 481, 479, 
477, 475, 473, 471, 469, 467, 466, 464, 462, 460, 458, 456, 454, 452, 450, 448, 446, 444, 443, 441, 
439, 437, 435, 433, 431, 429, 427, 425, 423, 421, 419, 417, 415, 413, 411, 409, 407, 405, 403, 401, 
399, 397, 395, 393, 391, 389, 387, 385, 383, 381, 379, 377, 375, 373, 371, 369, 367, 365, 363, 361, 
359, 357, 355, 353, 351, 349, 347, 345, 343, 341, 339, 337, 335, 333, 331, 329, 327, 325, 323, 321, 
319, 317, 315, 313, 311, 309, 307, 305, 303, 301, 299, 297, 295, 293, 291, 289, 287, 285, 283, 281, 
279, 277, 276, 274, 272, 270, 268, 266, 264, 262, 260, 258, 256, 254, 253, 251, 249, 247, 245, 243, 
241, 239, 238, 236, 234, 232, 230, 228, 227, 225, 223, 221, 219, 217, 216, 214, 212, 210, 209, 207, 
205, 203, 201, 200, 198, 196, 195, 193, 191, 189, 188, 186, 184, 183, 181, 179, 178, 176, 174, 173, 
171, 169, 168, 166, 165, 163, 161, 160, 158, 157, 155, 154, 152, 151, 149, 148, 146, 145, 143, 142, 
140, 139, 137, 136, 134, 133, 132, 130, 129, 127, 126, 125, 123, 122, 121, 119, 118, 117, 115, 114, 
113, 112, 110, 109, 108, 107, 105, 104, 103, 102, 101, 99, 98, 97, 96, 95, 94, 93, 91, 90, 
89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 74, 73, 72, 71, 
70, 69, 68, 68, 67, 66, 65, 64, 64, 63, 62, 61, 61, 60, 59, 59, 58, 57, 57, 56, 
55, 55, 54, 53, 53, 52, 52, 51, 51, 50, 50, 49, 49, 48, 48, 48, 47, 47, 46, 46, 
45, 45, 45, 44, 44, 44, 43, 43, 43, 43, 42, 42, 42, 42, 41, 41, 41, 41, 41, 41, 
41, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 41, 
41, 41, 41, 41, 41, 41, 42, 42, 42, 42, 43, 43, 43, 43, 44, 44, 44, 45, 45, 45, 
46, 46, 47, 47, 48, 48, 48, 49, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 55, 55, 
56, 57, 57, 58, 59, 59, 60, 61, 61, 62, 63, 64, 64, 65, 66, 67, 68, 68, 69, 70, 
71, 72, 73, 74, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 
90, 91, 93, 94, 95, 96, 97, 98, 99, 101, 102, 103, 104, 105, 107, 108, 109, 110, 112, 113, 
114, 115, 117, 118, 119, 121, 122, 123, 125, 126, 127, 129, 130, 132, 133, 134, 136, 137, 139, 140, 
142, 143, 145, 146, 148, 149, 151, 152, 154, 155, 157, 158, 160, 161, 163, 165, 166, 168, 169, 171, 
173, 174, 176, 178, 179, 181, 183, 184, 186, 188, 189, 191, 193, 195, 196, 198, 200, 201, 203, 205, 
207, 209, 210, 212, 214, 216, 217, 219, 221, 223, 225, 227, 228, 230, 232, 234, 236, 238, 239, 241, 
243, 245, 247, 249, 251, 253, 254, 256, 258, 260, 262, 264, 266, 268, 270, 272, 274, 276, 277, 279, 
281, 283, 285, 287, 289, 291, 293, 295, 297, 299, 301, 303, 305, 307, 309, 311, 313, 315, 317, 319, 
321, 323, 325, 327, 329, 331, 333, 335, 337, 339, 341, 343, 345, 347, 349, 351, 353, 355, 357, 359
};

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_TIM2_Init();
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
	TIM2->ARR = 720;
	TIM2->CCR1 = 0;
	TIM2->CCR2 = 0;
	TIM2->CCR3 = 0;
	TIM2->CCR4 = 0;
  while (1)
  {

  }
  /* USER CODE END 3 */
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim2)
{
							
	TIM2->CCR1 = tabT[i0];
	TIM2->CCR2 = tabT[i0];
	TIM2->CCR3 = tabT[i0];
	TIM2->CCR4 = tabT[i0];
	
	i0++;	
	if (i0==numberS)
		{
			i0 = 0;	
		}	
	
}



void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM2;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
