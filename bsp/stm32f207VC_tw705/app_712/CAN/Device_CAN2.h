#ifndef   _CAN2_DEV
#define    _CAN2_DEV
#include <rtthread.h>
#include <rthw.h>
#include "stm32f2xx.h"
#include "usart.h"
#include "board.h"
#include <serial.h>

#include  <stdlib.h>//����ת�����ַ���
#include  <stdio.h>
#include  <string.h>
#include "App_moduleConfig.h"
#include "Device_CAN.h"
#include <finsh.h>


#define  OIL_NOCONNECT 0
#define  OIL_NORMAL    1
#define  OIL_ABNORMAL  2



#define      U3_OUT_PWR_ON       GPIO_SetBits(GPIOE,GPIO_Pin_7)
#define      U3_OUT_PWR_OFF      GPIO_ResetBits(GPIOE,GPIO_Pin_7)


typedef  struct   _YH
{    
	uint32_t	oil_value;			///������������λΪ1/10��
	uint16_t	oil_realtime_value; 		///���������߶�ʵʱֵ����λΪ1/10mm
	uint16_t	oil_average_value;	///���������߶�ƽ��ʵʱֵ����λΪ1/10mm
	
	u8			oil_YH_workstate; 	 //  0:  ��ʾ�����쳣	1: ��ʾ��������  2:�ܹ���⵽��������������
	
	u32 		oil_YH_Abnormal_counter;	 //   ������ʻ�����У� ��ʵʱ�ͺ���ֵΪ 0  ��
										//	 ����300 �Σ��������300 ���ж��ͺĹ���
	u32 		oil_YH_0_value_cacheCounter;	//	�ٶ�Ϊ0 ������ ���ٶ�Ϊ0 ��������30 �� ��������������� 								   
	u32         oil_YH_no_data_Counter;  //  û�����ݼ�����
}YH;


extern  YH   Oil;

extern  struct rt_device  Device_CAN2;

extern void  u3_RxHandler(unsigned char rx_data);
extern void  Device_CAN2_regist(void );
extern void Oil_Sensor_Connect_Checking(void);



#endif
