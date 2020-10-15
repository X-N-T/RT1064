/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.24
 * @Target core		NXP RT1064DVL6A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-04-30
 ********************************************************************************************************************/


//�����Ƽ�IO�鿴Projecct�ļ����µ�TXT�ı�



//���µĹ��̻��߹����ƶ���λ�����ִ�����²���
//��һ�� �ر��������д򿪵��ļ�
//�ڶ��� project  clean  �ȴ��·�����������


/*
#include "headfile.h"


uint8 gpio_status;
int main(void)
{
  int i;
    DisableGlobalIRQ();
    board_init();   //��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
    
    
    //��ʼ��GPIO B9 Ϊ��� Ĭ������͵�ƽ ʹ��Ĭ����������GPIO_PIN_CONFIG
    gpio_init(C9,GPO,0,GPIO_PIN_CONFIG);

    //��ʼ��GPIO D0 D1 Ϊ��������
//    gpio_init(D0 ,GPI,0,GPIO_PIN_CONFIG);
//    gpio_init(D1 ,GPI,0,GPIO_PIN_CONFIG);
    pwm_init(PWM2_MODULE1_CHB_C9, 50, 5000);
    EnableGlobalIRQ(0);
    
    
    
    while(1)
    {
        gpio_set(B9,1);//�������ŵ�ƽΪ�ߵ�ƽ
        systick_delay_ms(100);
        gpio_set(B9,0);//�������ŵ�ƽΪ�͵�ƽ
        systick_delay_ms(100);
        gpio_toggle(B9);//��ת���ŵ�ƽ
        systick_delay_ms(100);
        
        
        
        gpio_status = gpio_get(D0);//��ȡ���ŵ�ƽ
        systick_delay_ms(100);
        
    }
    while (1)
    {
     for(i=0;i<=1000;i++)
      {
      pwm_duty(PWM2_MODULE1_CHB_C9,50*(1000-i));
    systick_delay_ms(1);
      }
      for(i=0;i<=1000;i++)
      {
      pwm_duty(PWM2_MODULE1_CHB_C9,50*i);
   systick_delay_ms(1);
    }
      pwm_duty(PWM2_MODULE1_CHB_C9,5000);
      systick_delay_ms(1);
      pwm_duty(PWM2_MODULE1_CHB_C9,0);
      systick_delay_ms(1);
    }
  
}
*/

#include "headfile.h"


uint8 gpio_status;

uint8 table_seg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
uint8 disp_buf[2];
uint8 data;

void led_disp(void)
{
    int i;
    disp_buf[1] = data/10;
    disp_buf[0] = data%10;
    data=data+0x01;
    for(i=0;i<=50;i++)
    {
    gpio_set(C8, (table_seg[ disp_buf[0] ]&0x01) );
    gpio_set(C9, ( table_seg[ disp_buf[0] ]>>1&0x01) );
    gpio_set(C10, ( table_seg[ disp_buf[0] ]>>2&0x01) ); 
    gpio_set(C11, ( table_seg[ disp_buf[0] ]>>3&0x01) ); 
    gpio_set(C12, ( table_seg[ disp_buf[0] ]>>4&0x01) ); 
    gpio_set(C13, ( table_seg[ disp_buf[0] ]>>5&0x01) );
    gpio_set(C14, ( table_seg[ disp_buf[0] ]>>6&0x01) );
    gpio_set(C15, ( table_seg[ disp_buf[0] ]>>7&0x01) );
    gpio_set(C5,0);
    systick_delay_ms(10);
    gpio_set(C5,1);
    
    gpio_set(C8, (table_seg[ disp_buf[1] ]&0x01) );
    gpio_set(C9, ( table_seg[ disp_buf[1] ]>>1&0x01) );
    gpio_set(C10, ( table_seg[ disp_buf[1] ]>>2&0x01) ); 
    gpio_set(C11, ( table_seg[ disp_buf[1] ]>>3&0x01) ); 
    gpio_set(C12, ( table_seg[ disp_buf[1] ]>>4&0x01) ); 
    gpio_set(C13, ( table_seg[ disp_buf[1] ]>>5&0x01) );
    gpio_set(C14, ( table_seg[ disp_buf[1] ]>>6&0x01) );
    gpio_set(C15, ( table_seg[ disp_buf[1] ]>>7&0x01) );
    gpio_set(C6,0);
    systick_delay_ms(10);
    gpio_set(C6,1); 
    }
}



int main(void)
{
    DisableGlobalIRQ();
    board_init();   //��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
    


    gpio_init(C5,GPO,1,GPIO_PIN_CONFIG);
    gpio_init(C6,GPO,1,GPIO_PIN_CONFIG);
    
    gpio_init(C8,GPO,0,GPIO_PIN_CONFIG);
    gpio_init(C9,GPO,0,GPIO_PIN_CONFIG);
    gpio_init(C10,GPO,0,GPIO_PIN_CONFIG);   
    gpio_init(C11,GPO,0,GPIO_PIN_CONFIG);
    gpio_init(C12,GPO,0,GPIO_PIN_CONFIG);
    gpio_init(C13,GPO,0,GPIO_PIN_CONFIG);
    gpio_init(C14,GPO,0,GPIO_PIN_CONFIG);
    gpio_init(C15,GPO,0,GPIO_PIN_CONFIG);

   
    EnableGlobalIRQ(0);
    
    
    
    while(1)
    {
      //��Ҫ�ض�ʱ���ж�  

      led_disp();
//      systick_delay_ms(20);
      
      //��Ҫ����ʱ���ж�  
    }

    
}


