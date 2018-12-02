#include <msp430.h> 

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	        // stop watchdog timer
	volatile  int i = 0;                // variable for delay

	P1DIR |=BIT0;                       // sets BIT0 output

	while(1){                           //loop
	    P1OUT &=~BIT0;                  //light up BIT0
	    for(i=0;i<20000;i++);       //delay
	    P1OUT |=BIT0;                   //light down BIT0
	    for(i=0;i<20000;i++);       //delay
	}
	return 0;
}
