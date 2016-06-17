/* Example 8
  by Rodolfo Cossovich http://rudi.plobot.com
  This example code is in the public domain.

  Motors and battery connected
  All peripherals as well
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
// D9 USB
// D10 USB
//#define pinSD2 9 //reserved
#define SD3 10

//pins for ultrasound
#define trigPin D0
#define echoPin D1

//pins for ultrasound
#define PWMA D1
#define DIRA D3
#define PWMB D2
#define DIRB D4

// constants won't change :
const long TIME = 500;           // interval at which to blink (milliseconds)


#define trigPin D0
#define echoPin SD3

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 500;           // interval at which to blink (milliseconds)


void setup()
{
  Serial.begin(115200);
  pinMode( D6, OUTPUT);
  pinMode( D7, OUTPUT);
  pinMode( D5, OUTPUT);

  pinMode( PWMA, OUTPUT);
  pinMode( DIRA, OUTPUT);
  pinMode( PWMB, OUTPUT);
  pinMode( DIRB, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println("starting...");
}

void loop()
{

  breathe();

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    int distance = ultra();
    Serial.println ( distance );
    if (distance < 4) {  // 
      Serial.print("really close! ");
      Serial.println("MOVING BKWD");
      motor0 (512, 1);
      motor1 (512, 0);
      servo();
      delay(500);
    }
    else if (distance < 20) {  // 
      Serial.print("something ahead.. ");
      Serial.println("TURNING...");
      if (random(3) > 1) {
        motor0 (0, 1);
      }
      else {
        motor1 (0, 1);
      }

      Serial.print(distance);
      Serial.println(" cm");

    }
    else {
      //move forward
      motor0 (1024, 0);
      motor1 (1024, 1);
    }

  }



}


void motor0 ( int speed, int direction) {
  if (direction) {
    digitalWrite(DIRA, HIGH);
  }
  else {
    digitalWrite(DIRA, LOW);
  }
  analogWrite(PWMA, speed);
}


void motor1 ( int speed, int direction) {
  if (direction) {
    digitalWrite(DIRB, HIGH);
  }
  else {
    digitalWrite(DIRB, LOW);
  }
  analogWrite(PWMB, speed);
}


void servo (void) {
  myservo.attach(D2);
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

void breathe ( void ) {
  float currentMillis = millis() / 5000.0;
  int value = 512.0 + 512 * sin( currentMillis * 2.0 * PI  );
  analogWrite(D6, value);
  analogWrite(D7, value);
  analogWrite(D5, value);
}

int ultra() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 29) ;
  return (int)distance;
}

