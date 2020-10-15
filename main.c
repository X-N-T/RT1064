/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.24
 * @Target core		NXP RT1064DVL6A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-04-30
 ********************************************************************************************************************/


//整套推荐IO查看Projecct文件夹下的TXT文本



//打开新的工程或者工程移动了位置务必执行以下操作
//第一步 关闭上面所有打开的文件
//第二步 project  clean  等待下方进度条走完

//数码管


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
    board_init();   //务必保留，本函数用于初始化MPU 时钟 调试串口
    


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
      //需要关定时器中断  

      led_disp();
//      systick_delay_ms(20);
      
      //需要开定时器中断  
    }

    
}


