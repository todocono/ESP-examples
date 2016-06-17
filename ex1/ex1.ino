/* Example 1
  by Rodolfo Cossovich http://rudi.plobot.com
  This example code is in the public domain.

  Servo connected to D2
*/

#include <Servo.h>

#define D0 16     //onboard LED 
#define D1 5
#define D2 4
#define D3 0
#define D4 2      //onboard LED
#define D5 14
#define D6 12
#define D7 13
#define D8 15   //needs to be open when flashing
// pin9 USB
// D10 USB 
//#define pinSD2 9 //reserved
#define pinSD3 10

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 500;           // interval at which to blink (milliseconds)


void setup()
{
  Serial.begin(115200);
  Serial.println("starting...");
}

void loop()
{
  servo();
}

void servo (void) {
  myservo.attach(D5);
  for (pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
  {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  myservo.detach();
}


