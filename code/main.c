#include<stc15.h>
//晶振频率20Mhz 8级优化
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define led_number 240
sbit send_date_1=P1^1;
sbit send_date_2=P1^0;
sbit send_date_3=P1^2;
sbit send_date_4=P1^3;
sbit send_date_5=P1^4;
bit flag_uart=0;
uchar uart_date;
uchar RGB_date[8][3]={{0xff,0xff,0xff},//白（最大亮度）0    255                            注意：黄色，橙色不支持亮度调节
										 {0x00,0xff,0x00},//红（最大亮度）1
										 {0xaa,0xff,0x00},//橙（最大亮度）2
	                   {0xff,0xff,0x00},//黄（最大亮度）3
	                   {0xff,0x00,0x00},//绿（最大亮度）4
										 {0x00,0x00,0x00},//关闭指令5
										 {0x00,0x00,0xff},//蓝（最大亮度）6
										 {0x00,0xaa,0xff},//紫（最大亮度）7
                     };//初始数组
uchar RGB_date_mix[8][3]={{0x55,0x55,0x55},//白（低亮度）1       85
										 {0x00,0x55,0x00},//红（低亮度）2
										 {0xaa,0xff,0x00},//橙（低亮度）3
	                   {0xff,0xff,0x00},//黄（低亮度）4
	                   {0x55,0x00,0x00},//绿（低亮度）5
										 {0x00,0x00,0x00},//关闭指令6
										 {0x00,0x00,0x55},//蓝（低亮度）7
										 {0x00,0xaa,0xff},//紫（低亮度）8
                     };//初始数组
/*void delay()		//@20.000MHz
{
	unsigned char i;

	_nop_();
	i = 80;
	while (--i);
}
*/
void init()
{
  P_SW1=0x40;//将串口1放到3.6 3.7
	EA=1;
	ES=1;
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x04;		//定时器2时钟为Fosc,即1T
	T2L = 0xF7;		//设定定时初值
	T2H = 0xFD;		//设定定时初值
	AUXR |= 0x01;		//串口1选择定时器2为波特率发生器
	AUXR |= 0x10;		//启动定时器2
}
void write_bit(uchar cn,uchar date_bit)
{
//Send_Dat=0;
	switch(cn)
	{
		case 1:
			if (date_bit==1)
{
send_date_1=1;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
send_date_1=0;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	}
 else
 {
	send_date_1=1;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	send_date_1=0;
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
}
 break;
 
		case 2:
			if (date_bit==1)
{
send_date_2=1;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
send_date_2=0;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	}
 else
 {
	send_date_2=1;
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	send_date_2=0;
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
}
  break;
		case 3:
			if (date_bit==1)
{
send_date_3=1;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
send_date_3=0;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	}
 else
 {
	send_date_3=1;
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	send_date_3=0;
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
}
  break;
		case 4:
			if (date_bit==1)
{
send_date_4=1;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
send_date_4=0;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	}
 else
 {
	send_date_4=1;
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	send_date_4=0;
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
}	
  break;
		case 5:
					if (date_bit==1)
{
send_date_5=1;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();_nop_();
send_date_5=0;
	_nop_();_nop_();_nop_();_nop_();_nop_();
	}
 else
 {
	send_date_5=1;
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	send_date_5=0;
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
	 _nop_();_nop_();_nop_();_nop_();_nop_();
}
 break; 
	}
}
void write_date(uchar cmd,uchar cn)//选择数据,选择灯带序号1 1
{
		uchar i,w,h;
	for(i=0;i<3;i++)//先传输高位
	{
		w=RGB_date[cmd][i];
	//	w=RGB[i];
		for(h=0;h<8;h++)
		{
			w=w<<1;
		write_bit(cn,CY);//向灯带cn发送数据
		}
}
	}
void write_date_mix(uchar cmd,uchar cn)//选择数据,选择灯带序号
{
		uchar i,w,h;
	for(i=0;i<3;i++)//先传输高位
	{
		w=RGB_date_mix[cmd][i];
	//	w=RGB[i];
		for(h=0;h<8;h++)
		{
			w=w<<1;
		write_bit(cn,CY);//向灯带cn发送数据
		}
}
}/*
void qc_led(uchar cn)
{
	uchar h;
for(h=0;h<led_number;h++){write_date(0,cn);}delay100ms();
delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
	delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		for(h=0;h<led_number;h++){write_date(5,cn);}		delay100ms();
			delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		for(h=0;h<led_number;h++){write_date(1,cn);}delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		for(h=0;h<led_number;h++){write_date(5,cn);}delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		for(h=0;h<led_number;h++){write_date(2,cn);}delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		for(h=0;h<led_number;h++){write_date(5,cn);}delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		for(h=0;h<led_number;h++){write_date(3,cn);}delay100ms();
				delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		for(h=0;h<led_number;h++){write_date(5,cn);}delay100ms();
				delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		for(h=0;h<led_number;h++){write_date(4,cn);}delay100ms();
				delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		for(h=0;h<led_number;h++){write_date(5,cn);}delay100ms();
				delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		for(h=0;h<led_number;h++){write_date(6,cn);}delay100ms();
				delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		for(h=0;h<led_number;h++){write_date(5,cn);}delay100ms();
				delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
    for(h=0;h<led_number;h++){write_date(7,cn);}delay100ms();
				delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
	  for(h=0;h<led_number;h++){write_date(5,cn);}delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
		delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();delay100ms();
}*/
void uart_dispose()
{
	uchar i;                                         /*Xagent通信协议*/
	uchar h;//灯数                                   前八位 ：灯带序号 01：1号灯带，02：二号灯带.03:3号灯带 04：四号灯带 05：五号灯带
	if(flag_uart==1)                                 //后八位（前四位）：亮度选择，0：高      2：低
	{ 	
flag_uart=0;		//  后八位（后四位）：颜色选择：0：关闭灯带 1：白光 2：红光 3：橙光 4：黄光 5：绿光  7：蓝光 8：紫光
		switch(uart_date)
		{
		/*总控部分*/
			case 0x63:for(i=1;i<=5;i++){ for(h=0;h<led_number;h++){write_date(5,i);}}//依次关闭5条灯带灯带
		/*灯带1分控*/
			case 0x00:for(i=1;i<=1;i++){for(h=0;h<led_number;h++){write_date(5,i);}}break;//关闭灯带1
		//	case 0x16:for(i=0;i<60;i++){qc_led(1);}break;//闪烁模式
			/*高亮度部分*/
			case 0x01:for(h=0;h<led_number;h++){write_date(0,1);}break;//白光
			case 0x02:for(h=0;h<led_number;h++){write_date(1,1);}break;//红光
			case 0x03:for(h=0;h<led_number;h++){write_date(2,1);}break;//橙光
			case 0x04:for(h=0;h<led_number;h++){write_date(3,1);}break;//黄光
			case 0x06:for(h=0;h<led_number;h++){write_date(4,1);}break;//绿光
			case 0x07:for(h=0;h<led_number;h++){write_date(6,1);}break;//蓝光
			case 0x08:for(h=0;h<led_number;h++){write_date(7,1);}break;//紫光
	/*		/*低亮度部分*/
			case 0x09:for(h=0;h<led_number;h++){write_date_mix(0,1);}break;//白光
			case 0x0a:for(h=0;h<led_number;h++){write_date_mix(1,1);}break;//红光
			case 0x0b:for(h=0;h<led_number;h++){write_date_mix(2,1);}break;//橙光
			case 0x0c:for(h=0;h<led_number;h++){write_date_mix(3,1);}break;//黄光
			case 0x0d:for(h=0;h<led_number;h++){write_date_mix(4,1);}break;//绿光
			case 0x0e:for(h=0;h<led_number;h++){write_date_mix(6,1);}break;//蓝光
			case 0x0f:for(h=0;h<led_number;h++){write_date_mix(7,1);}break;//紫光
			/*灯带2分控*/
			case 0x14:for(i=2;i<=2;i++){ for(h=1;h<led_number;h++){write_date(5,i);}}break;//关闭灯带2
	//		case 0x35:for(i=0;i<60;i++){qc_led(2);}break;//闪烁模式
			/*高亮度部分*/
			case 0x15:for(h=0;h<led_number;h++){write_date(0,2);}break;//白光
			case 0x16:for(h=0;h<led_number;h++){write_date(1,2);}break;//红光
			case 0x17:for(h=0;h<led_number;h++){write_date(2,2);}break;//橙光
			case 0x18:for(h=0;h<led_number;h++){write_date(3,2);}break;//黄光
			case 0x19:for(h=0;h<led_number;h++){write_date(4,2);}break;//绿光
			case 0x1a:for(h=0;h<led_number;h++){write_date(6,2);}break;//蓝光
			case 0x1b:for(h=0;h<led_number;h++){write_date(7,2);}break;//紫光
			//低亮度部分
			case 0x1c:for(h=0;h<led_number;h++){write_date_mix(0,2);}break;//白光
			case 0x1d:for(h=0;h<led_number;h++){write_date_mix(1,2);}break;//红光
			case 0x1e:for(h=0;h<led_number;h++){write_date_mix(2,2);}break;//橙光
			case 0x1f:for(h=0;h<led_number;h++){write_date_mix(3,2);}break;//黄光
			case 0x20:for(h=0;h<led_number;h++){write_date_mix(4,2);}break;//绿光
			case 0x21:for(h=0;h<led_number;h++){write_date_mix(6,2);}break;//蓝光
			case 0x22:for(h=0;h<led_number;h++){write_date_mix(7,2);}break;//紫光
			/*灯带3分控*/
			case 0x28:for(i=3;i<=3;i++){ for(h=1;h<led_number;h++){write_date(5,i);}}break;//关闭灯带3
	//		case 0x55:for(i=0;i<60;i++){qc_led(3);}break;//闪烁模式
			/*高亮度部分*/
			case 0x29:for(h=0;h<led_number;h++){write_date(0,3);}break;//白光
			case 0x2a:for(h=0;h<led_number;h++){write_date(1,3);}break;//红光
			case 0x2b:for(h=0;h<led_number;h++){write_date(2,3);}break;//橙光
			case 0x2c:for(h=0;h<led_number;h++){write_date(3,3);}break;//黄光
			case 0x2d:for(h=0;h<led_number;h++){write_date(4,3);}break;//绿光
			case 0x2e:for(h=0;h<led_number;h++){write_date(6,3);}break;//蓝光
			case 0x2f:for(h=0;h<led_number;h++){write_date(7,3);}break;//紫光
			/*低亮度部分*/
			case 0x30:for(h=0;h<led_number;h++){write_date_mix(0,3);}break;//白光
			case 0x31:for(h=0;h<led_number;h++){write_date_mix(1,3);}break;//红光
			case 0x32:for(h=0;h<led_number;h++){write_date_mix(2,3);}break;//橙光
			case 0x33:for(h=0;h<led_number;h++){write_date_mix(3,3);}break;//黄光
			case 0x34:for(h=0;h<led_number;h++){write_date_mix(4,3);}break;//绿光
			case 0x35:for(h=0;h<led_number;h++){write_date_mix(6,3);}break;//蓝光
			case 0x36:for(h=0;h<led_number;h++){write_date_mix(7,3);}break;//紫光*/
			/*灯带4分控*/
			case 0x3c:for(i=4;i<=4;i++){ for(h=1;h<led_number;h++){write_date(5,i);}}break;//关闭灯带4
		//	case 0x75:for(i=0;i<60;i++){qc_led(4);}break;//闪烁模式
			/*高亮度部分*/
			case 0x3d:for(h=0;h<led_number;h++){write_date(0,4);}break;//白光
			case 0x3e:for(h=0;h<led_number;h++){write_date(1,4);}break;//红光
			case 0x3f:for(h=0;h<led_number;h++){write_date(2,4);}break;//橙光
			case 0x40:for(h=0;h<led_number;h++){write_date(3,4);}break;//黄光
			case 0x41:for(h=0;h<led_number;h++){write_date(4,4);}break;//绿光
			case 0x42:for(h=0;h<led_number;h++){write_date(6,4);}break;//蓝光
			case 0x43:for(h=0;h<led_number;h++){write_date(7,4);}break;//紫光
			//低亮度部分
			case 0x44:for(h=0;h<led_number;h++){write_date_mix(0,4);}break;//白光
			case 0x45:for(h=0;h<led_number;h++){write_date_mix(1,4);}break;//红光
			case 0x46:for(h=0;h<led_number;h++){write_date_mix(2,4);}break;//橙光
			case 0x47:for(h=0;h<led_number;h++){write_date_mix(3,4);}break;//黄光
			case 0x48:for(h=0;h<led_number;h++){write_date_mix(4,4);}break;//绿光
			case 0x49:for(h=0;h<led_number;h++){write_date_mix(6,4);}break;//蓝光
			case 0x4a:for(h=0;h<led_number;h++){write_date_mix(7,4);}break;
			/*灯带5分控*/
			case 0x50:for(i=5;i<=5;i++){ for(h=1;h<led_number;h++){write_date(5,i);}}break;//关闭灯带5
//			case 0x95:for(i=0;i<60;i++){qc_led(5);}break;//闪烁模式
			/*高亮度部分*/
			case 0x51:for(h=0;h<led_number;h++){write_date(0,5);}break;//白光
			case 0x52:for(h=0;h<led_number;h++){write_date(1,5);}break;//红光
			case 0x53:for(h=0;h<led_number;h++){write_date(2,5);}break;//橙光
			case 0x54:for(h=0;h<led_number;h++){write_date(3,5);}break;//黄光
			case 0x55:for(h=0;h<led_number;h++){write_date(4,5);}break;//绿光
			case 0x56:for(h=0;h<led_number;h++){write_date(6,5);}break;//蓝光
			case 0x57:for(h=0;h<led_number;h++){write_date(7,5);}break;//紫光
	//	低亮度部分
			case 0x58:for(h=0;h<led_number;h++){write_date_mix(0,5);}break;//白光
			case 0x59:for(h=0;h<led_number;h++){write_date_mix(1,5);}break;//红光
//			case 0x53:for(h=0;h<led_number;h++){write_date_mix(2,5);}break;//橙光
	//		case 0x54:for(h=0;h<led_number;h++){write_date_mix(3,5);}break;//黄光
			case 0x5c:for(h=0;h<led_number;h++){write_date_mix(4,5);}break;//绿光
			case 0x5d:for(h=0;h<led_number;h++){write_date_mix(6,5);}break;//蓝光
	//		case 0x57:for(h=0;h<led_number;h++){write_date_mix(7,5);}break;//紫光
			default:break;
			}
		}
	}
void uart_1() interrupt 4
{
	//while(!RI);
		RI=0;
	uart_date=SBUF;
	flag_uart=1;
}
void main()
{
	init();
	while(1)
	{
uart_dispose();
		}
	}	