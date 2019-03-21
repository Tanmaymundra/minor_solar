#include <Servo.h>
 
Servo servo1;          //declare servos
Servo servo2;
int pos1 = 0;          // pos1 is horizontal position
int pos2 = 0;          // pos2 is vertical position
int right = 0;         // right ldr
int left = 0;          // left ldr
int centre = 0;        // centre ldr
int up = 0;            // top ldr
int down = 0;          // bottom ldr
 
int ldr1 = 0;          // map LDR's to pins
int ldr2 = 1;
int ldr3 = 2;
int ldr4 = 3;
int ldr5 = 4;
 
void setup()
{
  servo1.attach(10);      // attach servo1 to digital pin 10
  servo1.write(90);       // set initial position as 90 deg
 
  servo2.attach(9);        // attach servo1 to digital pin 9
  servo2.write(90);        // set initial position as 90 deg
 
  pinMode(ldr1, INPUT);      // declare LDRs as input
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  pinMode(ldr4, INPUT);
  pinMode(ldr5, INPUT);
}
 
void loop()
{
 
  pos1 = servo1.read();            // pos1 takes reading from current servo1 position
  pos2 = servo2.read();            // pos2 takes reading from current servo2 position
  int right = analogRead(ldr1);    // records reading from each LDRs
  int centre = analogRead(ldr2);
  int left = analogRead(ldr3);
  int up = analogRead(ldr4);
  int down = analogRead(ldr5);
 
                  // this portion is to control horizontal position
  if(right > centre && left < centre)          // if right LDR has more light than centre LDR, and centre LDR has more light than left (means light is towards right)
  {
    servo1.write(pos1 +1);                    //increase position of servo1 by 1 (0 is left, 90 is centre, 180 is right)
    delay(10);                                // this delay is needed to prevent servo from going 0-180 without stopping
  }
 
  else if(left > centre && right < centre)      // if light is towards centre
  {
    servo1.write(pos1 -1);                    // decrease position of servo1 by 1 (0 is left, 90 is centre, 180 is right)
    delay(10);
  }
 
  else
  {
    servo1.write(pos1);                    // if neither condition is met, this means the panel is centre. Do not move panel
  }
                 
                 // this portion is to control vertical position
  if(up > centre && down < centre)
  {
    servo2.write(pos2 +1);
    delay(10);
  }
 
  else if(down > centre && up < centre)
  {
    servo2.write(pos2 -1);
    delay(10);
  }
 
  else
  {
    servo2.write(pos2);
  }
 
}pp
