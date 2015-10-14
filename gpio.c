/*gcc -Wall -o blink blink.c -lwiringPi
 *sudo ./blink
 */

#include <wiringPi.h>
int main (void)
{
  wiringPiSetup () ;
  pinMode (0, OUTPUT) ; //cfg0 High to indicate slep crystal
  pinMode (1, OUTPUT) ; //cfg1 High to indicate SPI main pin conf
  pinMode (2, OUTPUT) ; //reset
//  for (;;)
//  {
    digitalWrite (0, HIGH) ;
    digitalWrite (1, HIGH) ;
    digitalWrite (2, HIGH) ; delay (500) ;
    digitalWrite (2,  LOW) ;
//  }
  return 0 ;
}
