#include <msp430.h>
int main(){
   WDTCTL = WDTPW + WDTHOLD;   //settings
   //most microprecessors has 8 bit-registers that uses control input/output.
   //example 00000010 or 00111100
   //P1DIR sets pins outputs or input.
   //P1OUT sets output 00000001 BIT0 is high ,others low.
   //P1OUT sets output 00000011 BIT1 and BIT0 is high ,others low.
   //==========================================
   //lets suppose P1DIR is 00000001. in this case if P1OUT is 00000001,BIT0 going to light up.
   P1DIR=BIT0; //0000001 BIT0=00000001
   P1OUT=BIT0; //0000001 BIT6=00100000
   //lets suppose P1DIR is 00100000.in this case if P1OUT is 00100000,BIT6 going to light up.
   P1DIR=BIT6;
   P1OUT=BIT6;
   //this code is not going to light up two led at the same time
   //to make that possible we use operators + , |:or , &:and , ^:xor , |=~ :nor , &=~nand
   // for example BIT0+BIT6=00100001

   //==========================================
   P1DIR=0x00;
   P1OUT=0x00;
   //reset registers
   P1DIR=BIT0;  //P1DIR=00000001
   P1OUT=BIT0;  //P1OUT=00000001
   P1DIR|=BIT6; //P1DIR=00100001
   P1OUT|=BIT6; //P1OUT=00100001
   // |= is makes P1OUT=P1OUT|BIT6
   return 1;// ends program
}
