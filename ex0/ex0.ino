/* Example 0
  by Rodolfo Cossovich http://rudi.plobot.com
  This example code is in the public domain.

  RGB LED connected to D5, D6 & D7
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
#define SD3 10

// constants won't change :
const long TIME = 500;           // interval at which to blink (milliseconds)


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
  Serial.println("MOTOR A...");
  motor0 (1024, 0);
  delay (TIME);
  motor0 (1024, 1);
  delay (TIME);
  motor0 (0, 0);

  Serial.println("MOTOR B...");
  motor1 (1024, 0);
  delay (TIME);
  motor1 (1024, 1);
  delay (TIME);
  motor1 (0, 0);
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

