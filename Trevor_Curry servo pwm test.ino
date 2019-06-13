/*  Trevor's Awesome Code
 *  Physics Stuff & Code! 
 * 
 */

#include <Servo.h>

//start = 575 us
//end = 2360 us

Servo N88;
int x;

//int x=230;
void setup() {
  // put your setup code here, to run once:
  N88.attach(9);
  Serial.begin(9600);
  N88.write(0);
  delay(750);
  x=575;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  while (x<2361){
     N88.writeMicroseconds(x); 
     x++;
     Serial.print("now testing: ");
     Serial.println(x); 
  }
  
  x=575;
  N88.write(0);
  delay(500);
  Serial.println("starting retest... "); 
  delay(3000);
  /*
   * 
   x--;
  Serial.println(x);
*/  
/*  while (x<11){
     Serial.println(x);
     x=x+1;
     delay(1000);
  }
  Serial.println(x);
  */
}
