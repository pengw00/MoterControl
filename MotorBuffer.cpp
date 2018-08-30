/*===功能：步进电机控制，型号35BYS08===*/
#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int
uchar MotorBuf[4]={0x30,0x60,0xc0,0x90};	//电机正转表<<反转表：30H,90H,C0H,60H>>
void motor(void);
void delay(uint t);
void main()
{
  while(1)
  {
   motor();
   TR1=0;
   //P2=0x00;
   //delay(4000);
   break;
  }
}
void delay(uint t) //定时时间tt*0.5ms
{
  do
  {
    TMOD=0x10;//定时器1方式1,Fosc=12M
  	TH1=0xFE;	//定时初值，定时0.5ms
	TL1=0x0C;
	TR1=1;
	while(!TF1);//查询方式
	TF1=0;
	TR1=0;
  }
  while(--t);
}
 uchar i,j;
 uchar a=144;
void motor(void)	//正转3圈
{
  while(1) 	//步距角为7.5°，一圈要48个脉冲，3圈需144个脉冲
 { i++;
  P2=MotorBuf[i];
  delay(5);
  if(i==4)  i=1;
  j++;
  if(j==a)
     {
	   //P2=0x00;
	   //TR1=0;
	   //close_timer1();
	   break;
	 }
   }
}
