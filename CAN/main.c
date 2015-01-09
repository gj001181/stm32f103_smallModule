#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "led.h" 
#include "myprintf.h"
#include "uart.h"
#include "pwm.h"
#include "systick.h"
#include "can.h"

static inline void Delay(uint32_t nCnt_1us)
{

      while(nCnt_1us--);
}

int main(void)
{
 	CanTxMsg TxMessage;
  uint16_t ccrrrrr=0;
	SysTick_Config(SYSTICK_PRESCALER);
	LED_Init();
	//Usart2_Init(115200);
	Myprintf_Init(0x00,myputc);

  HP_PWM_Init(20000, 10);
	CAN_Mode_Init(CAN_SJW_1tq,CAN_BS1_8tq,CAN_BS2_7tq,5,CAN_Mode_Normal);//CAN初始化环回模式,波特率450Kbps

  TxMessage.StdId=0x12;
  TxMessage.ExtId=0x12;
  TxMessage.IDE=0;		
  TxMessage.RTR=0;		
  TxMessage.DLC=4;		
  
  TxMessage.Data[0]= 0x01;
  TxMessage.Data[1]= 0x01;
  TxMessage.Data[2]= 0x01;
  TxMessage.Data[3]= 0x01;
  TxMessage.Data[4]= 0x01;		        
  //CAN_Transmit(CAN1, &TxMessage);   
  // void TIM_SetAutoreload(TIM_TypeDef* TIMx, uint16_t Autoreload);
	while (1) 
	{
      HP_PWM_PulseSet(ccrrrrr++);
      Delay(1000);

    if(can_RX0_received_flag == 1){

  PackageIdentifier(&CAN1Rx0Message);
  can_RX0_received_flag =0;

    }
  //CAN_Transmit(CAN1, &TxMessage); 
			
	}
}
