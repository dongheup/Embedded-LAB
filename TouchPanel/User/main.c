/*********************************************************************************************************
*
* File                : main.c
* Hardware Environment: 
* Build Environment   : RealView MDK-ARM  Version: 4.20
* Version             : V1.0
* By                  : 
*
*                                  (c) Copyright 2005-2011, WaveShare
*                                       http://www.waveshare.net
*                                          All Rights Reserved
*
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "LCD/LCD.h"
#include "TouchPanel/TouchPanel.h"
#include <stdio.h>

/*******************************************************************************
* Function Name  : Delay
* Description    : Delay Time
* Input          : - nCount: Delay Time
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void  Delay (uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}


/*******************************************************************************
* Function Name  : main
* Description    : Main program
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
int main(void)
{
	int8_t	temp[20]={0};
	uint16_t tempx=0,tempy=0;
	TP_Init();
	LCD_Initializtion();
	LCD_Clear(Black);
  	TouchPanel_Calibrate();
	/* Infinite loop */
	while (1)
	{
		getDisplayPoint(&display, Read_Ads7846(), &matrix );
	    TP_DrawPoint(display.x,display.y);
		if(tempx != display.x || tempy != display.y)
		{
			sprintf(temp,"X:%3d,Y:%3d",tempx,tempy);
			GUI_Text(10,10,(uint8_t*)temp,Red,Black);
			tempx = display.x;
			tempy = display.y;
		}	
	}
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

