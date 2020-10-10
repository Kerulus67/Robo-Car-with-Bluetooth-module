/*
 * USART_RS232_C_file.c
 *
 */ 

#include "USART_RS232_H_file.h"						/* Include USART header file */

void USART_Init(long BAUDRATE)				/* USART initialize function */
{ 
 UBRRL = BAUD_PRESCALE;							/* Load UBRRL with lower 8 bit of prescale value */
 UBRRH = (BAUD_PRESCALE >> 8);
 UCSRA |= (1<<U2X);
 UCSRB |= (1 << RXEN) | (1 << TXEN);				/* Enable USART transmitter and receiver */
 UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1);	 
// 			/* Load UBRRH with upper 8 bit of prescale value */
// 	UCSRA = 0x2;
// 	UCSRB = 0x18;
//  UCSRC = 0x86;
// 	UBRRH = 0x00;
// 	UBRRL = 12;

}

unsigned char USART_RxChar()									/* Data receiving function */
{
	while ((UCSRA & (1 << RXC)) == 0);					/* Wait until new data receive */
	return(UDR);									/* Get and return received data */ 
}

void USART_TxChar(char data)						/* Data transmitting function */
{
	        										/* Write data to be transmitting in UDR */
	while (!(UCSRA & (1<<UDRE)));					/* Wait until data transmit and buffer get empty */
	UDR = data;
}

void USART_SendString(char *str)					/* Send string of USART data function */ 
{
	int i=0;																	
	while (str[i]!=0)
	{
		USART_TxChar(str[i]);						/* Send each char of string till the NULL */
		i++;
	}
}