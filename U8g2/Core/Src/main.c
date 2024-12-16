/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "gpio.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32_u8g2.h"
#include "test.h"
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
// �������ڱ�ʾ"Ϊ"�ֵĵ������ݣ���һ����Ϊ���֣�������֮ǰ�в�ͬ��ʽ�ġ�Ϊ���֣����������ʵ����ģ���ȷ����ʾ������дһ�֣�
static const unsigned char wei[] ={
0x80,0x00,0x84,0x00,0x88,0x00,0x88,0x00,0x80,0x00,0xFE,0x1F,0x40,0x10,0x40,0x10,
0x40,0x11,0x20,0x12,0x20,0x12,0x10,0x10,0x08,0x10,0x04,0x10,0x02,0x0A,0x01,0x04
};
// �������ڱ�ʾ"��"�ֵĵ�������
static const unsigned char suo[] ={
0x40,0x10,0xE0,0x38,0x1C,0x07,0x04,0x01,0x04,0x01,0x7C,0x01,0x44,0x7F,0x44,0x11,
0x44,0x11,0x7C,0x11,0x04,0x11,0x04,0x11,0x82,0x10,0x82,0x10,0x41,0x10,0x20,0x10
};
// �������ڱ�ʾ"��"�ֵĵ�������
static const unsigned char yu[] ={
0x28,0x04,0x48,0x04,0x84,0x04,0x92,0x7E,0x10,0x42,0x28,0x21,0x44,0x08,0x82,0x08,
0x7D,0x08,0x44,0x08,0x44,0x14,0x44,0x14,0x44,0x12,0x7C,0x22,0x44,0x21,0x80,0x40
};
// �������ڱ�ʾ"Ϊ"�ֵĵ������ݣ��ڶ�����Ϊ���֣����в�ͬ��ģ��ʽ��
static const unsigned char wei1[] ={
0x80,0x00,0x84,0x00,0x88,0x00,0x88,0x00,0x80,0x00,0xFE,0x1F,0x40,0x10,0x40,0x10,
0x40,0x11,0x20,0x12,0x20,0x12,0x10,0x10,0x08,0x10,0x04,0x10,0x02,0x0A,0x01,0x04
};
// �������ڱ�ʾ"��"�ֵĵ�������
static const unsigned char fa[] ={
0x00,0x02,0x04,0x02,0x08,0x02,0x08,0x02,0xE1,0x3F,0x02,0x02,0x02,0x02,0x08,0x02,
0xF8,0x7F,0x04,0x02,0x07,0x01,0x84,0x00,0x44,0x08,0x24,0x10,0xF4,0x3F,0x20,0x20
};
// �������ڱ�ʾ"ǿ"�ֵĵ�������
static const unsigned char qiang[] ={
0x00,0x00,0x9F,0x3F,0x90,0x20,0x90,0x20,0x90,0x3F,0x1E,0x04,0x02,0x04,0xC2,0x7F,
0x42,0x44,0x5E,0x44,0xD0,0x7F,0x10,0x04,0x10,0x24,0x10,0x44,0xEA,0x7F,0x04,0x40
};
// �������ڱ�ʾ"��"�ֵĵ�������
static const unsigned char de[] ={
0x08,0x02,0x08,0x02,0xF4,0x7F,0x02,0x02,0xE9,0x3F,0x28,0x25,0x24,0x25,0xE6,0x3F,
0x05,0x00,0xF4,0x7F,0x04,0x02,0x04,0x24,0xA4,0x44,0xA4,0x50,0x94,0x10,0x04,0x1F
};

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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
    HAL_Init();

    /* Configure the system clock */
    SystemClock_Config();

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_I2C2_Init();
    MX_TIM1_Init();

    /* USER CODE BEGIN 2 */
    u8g2_t u8g2;
    u8g2Init(&u8g2);
    u8g2_SetFont(&u8g2, u8g2_font_ncenB12_tf);
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
		unsigned int x=0;
    while (1)
    {
       if (x <= 128)
    {
        x++;  // ���һ������������ÿ��x�������������ƻ����ٶȣ�ÿ������1���������ƶ������ʵ������ֵ�ӿ��ٶ�
    }
    else if (x > 128)
    {
        x = 0;  // ��������Ļ��Χ���������128�Ǻ��ʵı߽�ֵ���ɸ�����Ļ��ȵ�ʵ��������������������´��Ҳ࿪ʼ����
    }
                // ���ơ�Ϊ���֣���һ����
                u8g2_DrawXBMP(&u8g2, x+16, 0, 16, 16, wei);
                // ���ơ�������
                u8g2_DrawXBMP(&u8g2, x+32, 0, 16, 16, suo);
                // ���ơ�������
                u8g2_DrawXBMP(&u8g2, x+48, 0, 16, 16, yu);
                // ���ơ�Ϊ���֣��ڶ�����
                u8g2_DrawXBMP(&u8g2, x+64, 0, 16, 16, wei1);
                // ���ơ�������
                u8g2_DrawXBMP(&u8g2, x+80, 0, 16, 16, fa);
                // ���ơ�ǿ����
                u8g2_DrawXBMP(&u8g2, x+96, 0, 16, 16, qiang);
                // ���ơ��¡���
                u8g2_DrawXBMP(&u8g2, x+112, 0, 16, 16, de);

                // ���������ʽΪ���ʵ�����������ʾ���֣��������u8g2_font_ncenB10_tf���ʣ��ɸ���ʵ�ʵ�����
                u8g2_SetFont(&u8g2, u8g2_font_ncenB10_tf);
                // ���������ַ������������꣬ʹ����ʾ�ں���λ�ã�ʾ�����꣬�ɸ���ʵ��OLED��Ļ���ֵ�����
                u8g2_DrawStr(&u8g2, 16, 50, "632207030313");

       
        u8g2_SendBuffer(&u8g2);
        HAL_Delay(100);
    }
    /* USER CODE END WHILE */
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
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
    {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                  | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2)!= HAL_OK)
    {
        Error_Handler();
    }
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/