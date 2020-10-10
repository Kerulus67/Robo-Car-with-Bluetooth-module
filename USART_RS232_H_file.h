
#define F_CPU 1000000UL						/* Define CPU clock Frequency e.g. here its 8MHz */
#include <avr/io.h>							/* Include AVR std. library file */
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 8UL))) - 1)	/* Define prescale value */

void USART_Init(long);				/* USART initialize function */
unsigned char USART_RxChar();						/* Data receiving function */
void USART_TxChar(char);					/* Data transmitting function */
void USART_SendString(char*);				/* Send string of USART data function */
									/* USART_RS232_H_FILE_H_ */