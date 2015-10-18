/*gcc -Wall -o blink blink.c -lwiringPi
 *sudo ./blink
 */

#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define RESET 1
#define	CFG0 3
#define CFG1 2
#define RTS 4
#define CTS 5


void receive(int fd){
    printf ("1");
  int c;
  int count = 0;
  int avail = serialDataAvail(fd);
  while(!(avail == 0)){
    count++;
    c = serialGetchar(fd);
    printf ("2");
    avail = serialDataAvail(fd);
    printf ("3");
    printf("availer %d", c);
    printf ("4");
    delay(100);
    printf ("5");

  }
    printf ("done receiving availerble %d", avail);

}

void send(int fd){
  int c = 0;
  int count = 0;

  printf ("enter int");
  while(c>-1){
    scanf("%x", &c);
    printf ("You entered %d  and in hex %x \n", c, c);
    count++;
    serialPutchar(fd, c);
  }
}

int main (void)
{

  wiringPiSetup () ;
  pinMode (CFG0, OUTPUT) ; //cfg0 High to indicate slep crystal
  pinMode (CFG1, OUTPUT) ; //cfg1 High to indicate SPI main pin conf
  pinMode (RESET, OUTPUT) ; //reset
  pinMode (RTS, OUTPUT) ; //Ready to send
  pinMode (CTS, INPUT) ; //Clear to send
  digitalWrite (CFG0, LOW) ;
  digitalWrite (CFG1, HIGH) ;
  digitalWrite (RTS, HIGH);
  digitalWrite (RESET, LOW) ; delay (500) ;

  int fd;
  fd = serialOpen ("/dev/ttyAMA0", 115200);
  if (fd < 0) {
    fprintf(stderr, "unable to open serial device %s\n", strerror (errno));
    return 1;
  } else {
    delay(100);
    printf ("11 %d \n", 1);
    printf("serialopen %d \n", 1);

  }

  serialFlush (fd) ;
    printf ("22");
  digitalWrite(RESET, HIGH); delay (2000);

    printf ("33");
  while(1){
    printf ("44");
    digitalWrite(RTS, LOW); delay(2000);
    receive(fd);
//    digitalWrite(RTS, HIGH); delay(1000);
//    send(fd);
  }


  serialClose(fd);
  printf("serialport closed\n");
  return 0 ;
}
