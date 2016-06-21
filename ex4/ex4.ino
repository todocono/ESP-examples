/* Example 4
  by Rodolfo Cossovich http://rudi.plobot.com
  This example code is in the public domain.

  Two motors
*/

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
// #define SD3 10  //reserved

#define PWMA D1
#define DIRA D2
#define PWMB D3
#define DIRB D4


// constants won't change :
const long TIME = 2000;           // interval at which to blink (milliseconds)

int cycle = 512;                // a number between 0 and 1024

void setup()
{
  //
  Serial.begin(115200);
  pinMode( PWMA, OUTPUT);
  pinMode( DIRA, OUTPUT);
  pinMode( PWMB, OUTPUT);
  pinMode( DIRB, OUTPUT);
  Serial.println("starting...");
}

void loop()
{
  //  testMotors();
  /*  Serial.println("half...");
    cycle = 512;
    motor0 (cycle, 0);
    delay(TIME);
    motor0 (cycle, 1);
    delay(TIME);

    motor0 (0, 1);
    Serial.println("stopping...");

    digitalWrite(DIRA, LOW);
    digitalWrite(PWMA, LOW);
    delay(TIME);

    cycle = 1024;

    Serial.println("full...");
    motor0 (cycle, 0);
    delay(TIME);
    motor0 (cycle, 1);
    delay(TIME);

    Serial.println("stopping...");
    motor0 (0, 1);
    delay(TIME);
  */

  analogWrite(PWMA, 512);
  digitalWrite(DIRA, LOW);
  analogWrite(PWMB, (1024 - 512));
  digitalWrite(DIRB, HIGH);
  delay (2000);
  analogWrite(PWMA, 768);
  digitalWrite(DIRA, LOW);
  analogWrite(PWMB, (1024 - 768));
  digitalWrite(DIRB, HIGH);
  delay (2000);
  analogWrite(PWMA, 1024);
  digitalWrite(DIRA, LOW);
  analogWrite(PWMB, (1024 - 1024));
  digitalWrite(DIRB, HIGH);
  delay (2000);
  digitalWrite(PWMA, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRB, LOW);
  delay (2000);
  analogWrite(PWMA, (1024 - 512));
  digitalWrite(DIRA, HIGH);
  analogWrite(PWMB, 512);
  digitalWrite(DIRB, LOW);
  delay (2000);
  analogWrite(PWMA, (1024 - 768));
  digitalWrite(DIRA, HIGH);
  analogWrite(PWMB, 768);
  digitalWrite(DIRB, LOW);
  delay (2000);
  analogWrite(PWMA, (1024 - 1024));
  digitalWrite(DIRA, HIGH);
  analogWrite(PWMB, 1024);
  digitalWrite(DIRB, LOW);
  delay (2000);
  digitalWrite(PWMA, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRB, LOW);
  delay (2000);
}

void testMotors( void ) {
  Serial.println("test1...");
  motor0 (cycle, 0);
  motor1 (cycle, 1);
  delay (TIME);
  motor0 (0, 0);
  motor1 (0, 0);
  delay (TIME);

  Serial.println("test2...");
  motor0 (cycle, 1);
  motor1 (cycle, 0);
  delay (TIME);
  motor0 (0, 0);
  motor1 (0, 0);
  delay (TIME);

  cycle = cycle + 128;
  if (cycle > 1024)
    cycle = 512;
}

void motor0 ( int var1, int var2) {
  if ( var1 == 0  ) {
    digitalWrite(DIRA, LOW);
    digitalWrite(PWMA, LOW);
  }
  else {
    if (!var2) {
      analogWrite(PWMA, var1);
      digitalWrite(DIRA, LOW);
    }
    else {
      analogWrite(PWMA, (1024 - var1));
      digitalWrite(DIRA, HIGH);
    }
  }
}


void motor1 ( int cycle, int direction) {
  if (direction) {
    digitalWrite(DIRB, LOW);
    analogWrite(PWMB, cycle);
  }
  else {
    digitalWrite(DIRB, HIGH);
    analogWrite(PWMB, (1024 - cycle));
  }
}

