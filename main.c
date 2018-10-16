
#include "button.h"

/**
  ******************************************************************
													   ��������
  ******************************************************************
  */ 

Button_t Button1;
Button_t Button2; 


/**
  ******************************************************************
														��������
  ******************************************************************
  */ 
  
static void BSP_Init(void);


uint8_t Read_KEY1_Level(void)
{
  return GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN);
}

uint8_t Read_KEY2_Level(void)
{
  return GPIO_ReadInputDataBit(KEY2_GPIO_PORT,KEY2_GPIO_PIN);
}



void Btn1_Dowm_CallBack(void *btn)
{
  PRINT_INFO("Button1 ����!");
}

void Btn1_Double_CallBack(void *btn)
{
  PRINT_INFO("Button1 ˫��!");
}

void Btn1_Long_CallBack(void *btn)
{
  PRINT_INFO("Button1 ����!");
  
  Button_Delete(&Button2);
  PRINT_INFO("ɾ��Button1");
  Search_Button();
}

void Btn2_Dowm_CallBack(void *btn)
{
  PRINT_INFO("Button2 ����!");
}

void Btn2_Double_CallBack(void *btn)
{
  PRINT_INFO("Button2 ˫��!");
}

void Btn2_Long_CallBack(void *btn)
{
  PRINT_INFO("Button2 ����!");
}


/**
  ******************************************************************
  * @brief   ������
  * @author  jiejie
  * @version V1.0
  * @date    2018-xx-xx
  ******************************************************************
  */ 
int main(void)
{
  uint32_t i = 100000;
  
	BSP_Init();
  
//  PRINT_DEBUG("��ǰ��ƽ��%d",Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN));
  
  Button_Create("Button1",
                &Button1, 
                Read_KEY1_Level, 
                KEY_ON);
  Button_Attach(&Button1,BUTTON_DOWM,Btn1_Dowm_CallBack);
//  Button_Attach(&Button1,BUTTON_DOUBLE,Btn1_Double_CallBack);
  Button_Attach(&Button1,BUTTON_LONG,Btn1_Long_CallBack);
  
  Button_Create("Button2",
                &Button2, 
                Read_KEY2_Level, 
                KEY_ON);
  Button_Attach(&Button2,BUTTON_DOWM,Btn2_Dowm_CallBack);
//  Button_Attach(&Button2,BUTTON_DOUBLE,Btn2_Double_CallBack);
  Button_Attach(&Button2,BUTTON_LONG,Btn2_Long_CallBack);
 
	while(1)                            
	{

    Button_Process();     //��Ҫ���ڵ��ð���������

    Delay_ms(20);
    
    
	}
}

/**
  ******************************************************************
  * @brief   BSP_Init���������а弶��ʼ��
  * @author  jiejie
  * @version V1.0
  * @date    2018-xx-xx
  ******************************************************************
  */ 
static void BSP_Init(void)
{
	/* LED ��ʼ�� */
	LED_GPIO_Config();
	
	/* ���ڳ�ʼ�� */
	USART_Config();
  
	/* ������ʼ�� */
  Key_GPIO_Config();
  
	
	/* ��ӡ��Ϣ */
	PRINT_INFO("welcome to learn jiejie stm32 library!\n");
	
}


/********************************END OF FILE***************************************/
