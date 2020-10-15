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



#include "headfile.h"


//实验现象说明：
//核心板LED会闪烁起来
int main(void)
{
	DisableGlobalIRQ();
    board_init();//务必保留，本函数用于初始化MPU 时钟 调试串口
    
    
   gpio_init(C9,GPO,1,GPIO_PIN_CONFIG);
   pwm_init(PWM2_MODULE1_CHB_C9, 50, 50000);
/*     gpio_init(C4,GPI,0,GPIO_PIN_CONFIG);
    pit_init();                     //初始化pit外设
    pit_interrupt_ms(PIT_CH0,100);  //初始化pit通道0 周期
	NVIC_SetPriority(PIT_IRQn,15);  //设置中断优先级 范围0-15 越小优先级越高 四路PIT共用一个PIT中断函数
 */
    gpio_interrupt_init(C4,FALLING,GPIO_PIN_CONFIG);
    NVIC_SetPriority(GPIO2_Combined_16_31_IRQn,1);
    EnableGlobalIRQ(0);
    //pit的中断函数在isr.c文件  名称为PIT_IRQHandler
    while (1)
    {
      pwm_duty(PWM2_MODULE1_CHB_C9,50000);
      systick_delay_ms(100);
      pwm_duty(PWM2_MODULE1_CHB_C9,0);
      systick_delay_ms(100);
    }
}
