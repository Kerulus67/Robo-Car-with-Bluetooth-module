
#include <avr/io.h>
#include "USART_RS232_H_file.h"		/* include USART library */
#include <util/delay.h>
#define  MTR_1 1
#define  MTR_2 2				/* connected LED on PORT pin */

int main(void)
{
	char Data_in;
	DDRB = 0xff;
	DDRC =0xff;							/* make PORT as output port */
	USART_Init(9600);						/* initialize USART with 9600 baud rate */
	
	while(1)
	{
		Data_in = USART_RxChar();						/* receive data from Bluetooth device*/
		if(Data_in == 'f')
		{	PORTB = 0b00001010;
			PORTC = 0b00001010;
			USART_SendString("Forward\r\n");			/* Turn ON LED */
			
		}
		else if(Data_in =='b')
		{
		 PORTB = 0b01010101;
		 PORTC= 0b01010101;
		 USART_SendString("Backward\r\n");							/* Turn OFF LED */
		} 
		else if(Data_in == 'r'){
			PORTB = 0b10100010;
			PORTC = 0b10101000;
			USART_SendString("Moved right\r\n");
		}
		else if(Data_in == 'l'){
			PORTB = 0b10101000;
			PORTC = 0b10100010;
			USART_SendString("Moved left\r\n");
		} 
		else if(Data_in == 's'){
		PORTB = 0b00000000;
		PORTC = 0b00000000;
		USART_SendString("Stopped\r\n");
		} 
		else {
			PORTB = 0b00000000;
			PORTC = 0b00000000;
			USART_SendString("Wrong Input mate\r\n");
		}
	}		
	return 0;
}