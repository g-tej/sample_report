 #include <lpc214x.h>
#define RS   (1<<10)
#define RW   (1<<12)
#define EN   (1<<13)
#define LCD_DATA  (0xFF<<16)

void LCD_display(char *);
void LCD_data(unsigned char a);
void LCD_command (unsigned char a);

void delay(int count)
	{
		int i,j;
		for(i =0;i < count;i++)
			for(j = 0;j < 5000;j++);
	}
	void LCD_init(void)
    {
	IODIR0=0X00000000;
	IODIR0 |= EN|RS|RW|LCD_DATA|0X000080F0;
	//LCD_command(0x02);		//reset the lcd display
	LCD_command(0X38); 		//intializes the 16x2 ,5x7 LCD matrix  8-bit mode
	LCD_command(0X0F); 		//  display on cursor blinking
  	LCD_command(0X01); 		//clear screen ,cursor home
	LCD_command(0X80);		//Start with first line
 }
   void LCD_display(char *str)
{
	while(*str)
	{
		{
			LCD_data(*str);
		}
		str++;
		delay(50);
	}
}
void LCD_data(unsigned char a)	 
{
	IOPIN0 = a << 16;
	IOCLR0 = RW;
	IOSET0 = RS;  //RS=1 for data
	IOSET0 |= EN;
	delay(100);
	IOCLR0 = EN;
	delay(100);
 }

 void LCD_command (unsigned char a)
{
	IOPIN0 = a<<16;
	IOCLR0 = RS;	//RS should be 0 for command
	IOCLR0 |= RW;
	IOSET0 = EN;
	delay(100);
	IOCLR0 = EN;
	delay(100);
  }
 
void display(int a)
{
   LCD_command(0x01);
   LCD_command(0xC0);
	if(a != 0)
	{
		display(a/10);
		 
		 LCD_data(a%10 + 48);
	}

}
#define MI 200
#define RESERVED_L 201
#define RESERVED_H 300
#define FULL_L 301
#define FULL_H 400
#define MAX_L 401
#define MAX_H 600
#define DELAY 5000
#define LDRPINSELPIN0 18
#define LDRPINSELPIN1 19
#define ADCSTARTBIT 24
#define SHIFTVALUE 6
#define EXTRACTBITS 0X000003FF
#define IGNITIONLED 7
#define BUZZORPIN 15
#define RESERVEDLED 4
#define FULLLED 5
#define MAXLED 6
	int main()
	{  	 
	    int res;
		LCD_init();
	   // LCD_display("ADC VALUE=");
		delay(500);
	//	//PINSEL1 = 0x01000000; /* P0.28 as AD0.1 */
	        PINSEL1=1<<LDRPINSELPIN0|0<<LDRPINSELPIN1;   //P0.25 as AD0.4
		    AD0CR = 0x00200310; 

		while(1)
		{		
		if(IOPIN0&1){ 

		LCD_display("ignition on"); 
			LCD_command(0X80);
			AD0CR = AD0CR | (1<<ADCSTARTBIT); /* Start Conversion */
			//while ( !(AD0DR1 & 0x80000000) ); /* Wait till DONE */
	     	//res = AD0DR1;
			while ( !(AD0GDR & 0x80000000) ); /* Wait till DONE */
	     	res = AD0GDR;
			res = (res>>SHIFTVALUE);
		     res = (res & EXTRACTBITS);	
			 LCD_command(0xC0);
			display(res);
			delay(DELAY);
		if(res<MI)
		{
		LCD_command(0x80);
           LCD_display("no fuel");
		   IOSET0=1<<IGNITIONLED|1<<BUZZORPIN;
		   	LCD_command(0x01);
			LCD_command(0xc0);
		   delay(DELAY); 
								   
		}
	else if(res>RESERVED_L&&res<RESERVED_H)
		{			
			LCD_command(0x80);		  
           LCD_display("reserved");
		   IOSET0=1<<IGNITIONLED|1<<RESERVEDLED;
		   	LCD_command(0x01);
			LCD_command(0xc0);
		   delay(DELAY); 			
		}

	else if(res>FULL_L&&res<FULL_H)
		{					
			LCD_command(0x80);					  	
           LCD_display("FULL");
		   IOSET0=1<<IGNITIONLED|1<<FULLLED;
		   	LCD_command(0x01);
			LCD_command(0xc0);
		   delay(DELAY); 			
		}
	else if(res>MAX_L)
		{					
			LCD_command(0x80);										  	
           LCD_display("MAX");
		   IOSET0=1<<IGNITIONLED|1<<MAXLED;
		   	LCD_command(0x01);
			LCD_command(0xc0);
		   delay(DELAY); 			
		}
		}
		else
		{
		   IOCLR0=0X11111111;
			LCD_command(0x01);
			LCD_command(0xc0);
			LCD_display("IGNITION OFF");
		}
	}
	}
