#include<stc15.h>
//����Ƶ��20Mhz 8���Ż�
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
uchar RGB_date[8][3]={{0xff,0xff,0xff},//�ף�������ȣ�0    255                            ע�⣺��ɫ����ɫ��֧�����ȵ���
										 {0x00,0xff,0x00},//�죨������ȣ�1
										 {0xaa,0xff,0x00},//�ȣ�������ȣ�2
	                   {0xff,0xff,0x00},//�ƣ�������ȣ�3
	                   {0xff,0x00,0x00},//�̣�������ȣ�4
										 {0x00,0x00,0x00},//�ر�ָ��5
										 {0x00,0x00,0xff},//����������ȣ�6
										 {0x00,0xaa,0xff},//�ϣ�������ȣ�7
                     };//��ʼ����
uchar RGB_date_mix[8][3]={{0x55,0x55,0x55},//�ף������ȣ�1       85
										 {0x00,0x55,0x00},//�죨�����ȣ�2
										 {0xaa,0xff,0x00},//�ȣ������ȣ�3
	                   {0xff,0xff,0x00},//�ƣ������ȣ�4
	                   {0x55,0x00,0x00},//�̣������ȣ�5
										 {0x00,0x00,0x00},//�ر�ָ��6
										 {0x00,0x00,0x55},//���������ȣ�7
										 {0x00,0xaa,0xff},//�ϣ������ȣ�8
                     };//��ʼ����
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
  P_SW1=0x40;//������1�ŵ�3.6 3.7
	EA=1;
	ES=1;
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x04;		//��ʱ��2ʱ��ΪFosc,��1T
	T2L = 0xF7;		//�趨��ʱ��ֵ
	T2H = 0xFD;		//�趨��ʱ��ֵ
	AUXR |= 0x01;		//����1ѡ��ʱ��2Ϊ�����ʷ�����
	AUXR |= 0x10;		//������ʱ��2
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
void write_date(uchar cmd,uchar cn)//ѡ������,ѡ��ƴ����1 1
{
		uchar i,w,h;
	for(i=0;i<3;i++)//�ȴ����λ
	{
		w=RGB_date[cmd][i];
	//	w=RGB[i];
		for(h=0;h<8;h++)
		{
			w=w<<1;
		write_bit(cn,CY);//��ƴ�cn��������
		}
}
	}
void write_date_mix(uchar cmd,uchar cn)//ѡ������,ѡ��ƴ����
{
		uchar i,w,h;
	for(i=0;i<3;i++)//�ȴ����λ
	{
		w=RGB_date_mix[cmd][i];
	//	w=RGB[i];
		for(h=0;h<8;h++)
		{
			w=w<<1;
		write_bit(cn,CY);//��ƴ�cn��������
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
	uchar i;                                         /*Xagentͨ��Э��*/
	uchar h;//����                                   ǰ��λ ���ƴ���� 01��1�ŵƴ���02�����ŵƴ�.03:3�ŵƴ� 04���ĺŵƴ� 05����ŵƴ�
	if(flag_uart==1)                                 //���λ��ǰ��λ��������ѡ��0����      2����
	{ 	
flag_uart=0;		//  ���λ������λ������ɫѡ��0���رյƴ� 1���׹� 2����� 3���ȹ� 4���ƹ� 5���̹�  7������ 8���Ϲ�
		switch(uart_date)
		{
		/*�ܿز���*/
			case 0x63:for(i=1;i<=5;i++){ for(h=0;h<led_number;h++){write_date(5,i);}}//���ιر�5���ƴ��ƴ�
		/*�ƴ�1�ֿ�*/
			case 0x00:for(i=1;i<=1;i++){for(h=0;h<led_number;h++){write_date(5,i);}}break;//�رյƴ�1
		//	case 0x16:for(i=0;i<60;i++){qc_led(1);}break;//��˸ģʽ
			/*�����Ȳ���*/
			case 0x01:for(h=0;h<led_number;h++){write_date(0,1);}break;//�׹�
			case 0x02:for(h=0;h<led_number;h++){write_date(1,1);}break;//���
			case 0x03:for(h=0;h<led_number;h++){write_date(2,1);}break;//�ȹ�
			case 0x04:for(h=0;h<led_number;h++){write_date(3,1);}break;//�ƹ�
			case 0x06:for(h=0;h<led_number;h++){write_date(4,1);}break;//�̹�
			case 0x07:for(h=0;h<led_number;h++){write_date(6,1);}break;//����
			case 0x08:for(h=0;h<led_number;h++){write_date(7,1);}break;//�Ϲ�
	/*		/*�����Ȳ���*/
			case 0x09:for(h=0;h<led_number;h++){write_date_mix(0,1);}break;//�׹�
			case 0x0a:for(h=0;h<led_number;h++){write_date_mix(1,1);}break;//���
			case 0x0b:for(h=0;h<led_number;h++){write_date_mix(2,1);}break;//�ȹ�
			case 0x0c:for(h=0;h<led_number;h++){write_date_mix(3,1);}break;//�ƹ�
			case 0x0d:for(h=0;h<led_number;h++){write_date_mix(4,1);}break;//�̹�
			case 0x0e:for(h=0;h<led_number;h++){write_date_mix(6,1);}break;//����
			case 0x0f:for(h=0;h<led_number;h++){write_date_mix(7,1);}break;//�Ϲ�
			/*�ƴ�2�ֿ�*/
			case 0x14:for(i=2;i<=2;i++){ for(h=1;h<led_number;h++){write_date(5,i);}}break;//�رյƴ�2
	//		case 0x35:for(i=0;i<60;i++){qc_led(2);}break;//��˸ģʽ
			/*�����Ȳ���*/
			case 0x15:for(h=0;h<led_number;h++){write_date(0,2);}break;//�׹�
			case 0x16:for(h=0;h<led_number;h++){write_date(1,2);}break;//���
			case 0x17:for(h=0;h<led_number;h++){write_date(2,2);}break;//�ȹ�
			case 0x18:for(h=0;h<led_number;h++){write_date(3,2);}break;//�ƹ�
			case 0x19:for(h=0;h<led_number;h++){write_date(4,2);}break;//�̹�
			case 0x1a:for(h=0;h<led_number;h++){write_date(6,2);}break;//����
			case 0x1b:for(h=0;h<led_number;h++){write_date(7,2);}break;//�Ϲ�
			//�����Ȳ���
			case 0x1c:for(h=0;h<led_number;h++){write_date_mix(0,2);}break;//�׹�
			case 0x1d:for(h=0;h<led_number;h++){write_date_mix(1,2);}break;//���
			case 0x1e:for(h=0;h<led_number;h++){write_date_mix(2,2);}break;//�ȹ�
			case 0x1f:for(h=0;h<led_number;h++){write_date_mix(3,2);}break;//�ƹ�
			case 0x20:for(h=0;h<led_number;h++){write_date_mix(4,2);}break;//�̹�
			case 0x21:for(h=0;h<led_number;h++){write_date_mix(6,2);}break;//����
			case 0x22:for(h=0;h<led_number;h++){write_date_mix(7,2);}break;//�Ϲ�
			/*�ƴ�3�ֿ�*/
			case 0x28:for(i=3;i<=3;i++){ for(h=1;h<led_number;h++){write_date(5,i);}}break;//�رյƴ�3
	//		case 0x55:for(i=0;i<60;i++){qc_led(3);}break;//��˸ģʽ
			/*�����Ȳ���*/
			case 0x29:for(h=0;h<led_number;h++){write_date(0,3);}break;//�׹�
			case 0x2a:for(h=0;h<led_number;h++){write_date(1,3);}break;//���
			case 0x2b:for(h=0;h<led_number;h++){write_date(2,3);}break;//�ȹ�
			case 0x2c:for(h=0;h<led_number;h++){write_date(3,3);}break;//�ƹ�
			case 0x2d:for(h=0;h<led_number;h++){write_date(4,3);}break;//�̹�
			case 0x2e:for(h=0;h<led_number;h++){write_date(6,3);}break;//����
			case 0x2f:for(h=0;h<led_number;h++){write_date(7,3);}break;//�Ϲ�
			/*�����Ȳ���*/
			case 0x30:for(h=0;h<led_number;h++){write_date_mix(0,3);}break;//�׹�
			case 0x31:for(h=0;h<led_number;h++){write_date_mix(1,3);}break;//���
			case 0x32:for(h=0;h<led_number;h++){write_date_mix(2,3);}break;//�ȹ�
			case 0x33:for(h=0;h<led_number;h++){write_date_mix(3,3);}break;//�ƹ�
			case 0x34:for(h=0;h<led_number;h++){write_date_mix(4,3);}break;//�̹�
			case 0x35:for(h=0;h<led_number;h++){write_date_mix(6,3);}break;//����
			case 0x36:for(h=0;h<led_number;h++){write_date_mix(7,3);}break;//�Ϲ�*/
			/*�ƴ�4�ֿ�*/
			case 0x3c:for(i=4;i<=4;i++){ for(h=1;h<led_number;h++){write_date(5,i);}}break;//�رյƴ�4
		//	case 0x75:for(i=0;i<60;i++){qc_led(4);}break;//��˸ģʽ
			/*�����Ȳ���*/
			case 0x3d:for(h=0;h<led_number;h++){write_date(0,4);}break;//�׹�
			case 0x3e:for(h=0;h<led_number;h++){write_date(1,4);}break;//���
			case 0x3f:for(h=0;h<led_number;h++){write_date(2,4);}break;//�ȹ�
			case 0x40:for(h=0;h<led_number;h++){write_date(3,4);}break;//�ƹ�
			case 0x41:for(h=0;h<led_number;h++){write_date(4,4);}break;//�̹�
			case 0x42:for(h=0;h<led_number;h++){write_date(6,4);}break;//����
			case 0x43:for(h=0;h<led_number;h++){write_date(7,4);}break;//�Ϲ�
			//�����Ȳ���
			case 0x44:for(h=0;h<led_number;h++){write_date_mix(0,4);}break;//�׹�
			case 0x45:for(h=0;h<led_number;h++){write_date_mix(1,4);}break;//���
			case 0x46:for(h=0;h<led_number;h++){write_date_mix(2,4);}break;//�ȹ�
			case 0x47:for(h=0;h<led_number;h++){write_date_mix(3,4);}break;//�ƹ�
			case 0x48:for(h=0;h<led_number;h++){write_date_mix(4,4);}break;//�̹�
			case 0x49:for(h=0;h<led_number;h++){write_date_mix(6,4);}break;//����
			case 0x4a:for(h=0;h<led_number;h++){write_date_mix(7,4);}break;
			/*�ƴ�5�ֿ�*/
			case 0x50:for(i=5;i<=5;i++){ for(h=1;h<led_number;h++){write_date(5,i);}}break;//�رյƴ�5
//			case 0x95:for(i=0;i<60;i++){qc_led(5);}break;//��˸ģʽ
			/*�����Ȳ���*/
			case 0x51:for(h=0;h<led_number;h++){write_date(0,5);}break;//�׹�
			case 0x52:for(h=0;h<led_number;h++){write_date(1,5);}break;//���
			case 0x53:for(h=0;h<led_number;h++){write_date(2,5);}break;//�ȹ�
			case 0x54:for(h=0;h<led_number;h++){write_date(3,5);}break;//�ƹ�
			case 0x55:for(h=0;h<led_number;h++){write_date(4,5);}break;//�̹�
			case 0x56:for(h=0;h<led_number;h++){write_date(6,5);}break;//����
			case 0x57:for(h=0;h<led_number;h++){write_date(7,5);}break;//�Ϲ�
	//	�����Ȳ���
			case 0x58:for(h=0;h<led_number;h++){write_date_mix(0,5);}break;//�׹�
			case 0x59:for(h=0;h<led_number;h++){write_date_mix(1,5);}break;//���
//			case 0x53:for(h=0;h<led_number;h++){write_date_mix(2,5);}break;//�ȹ�
	//		case 0x54:for(h=0;h<led_number;h++){write_date_mix(3,5);}break;//�ƹ�
			case 0x5c:for(h=0;h<led_number;h++){write_date_mix(4,5);}break;//�̹�
			case 0x5d:for(h=0;h<led_number;h++){write_date_mix(6,5);}break;//����
	//		case 0x57:for(h=0;h<led_number;h++){write_date_mix(7,5);}break;//�Ϲ�
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