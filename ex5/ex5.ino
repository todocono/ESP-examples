/* Example 5
  by Rodolfo Cossovich http://rudi.plobot.com
  This example code is in the public domain.

  Motors moving in sequences
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
#define pinSD3 10

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


void setup()
{
  Serial.begin(115200);

  pinMode( PWMA, OUTPUT);
  pinMode( DIRA, OUTPUT);
  pinMode( PWMB, OUTPUT);
  pinMode( DIRB, OUTPUT);
  Serial.println("starting...");
}

void loop()
{
  forward( 1000 );
  backward( 1000 );
  left( 200 );
  right( 200 );
}


void forward ( int t_motor ) {
  motor0 (1024, 0);
  motor1 (1024, 1);
  delay (t_motor);
}

void backward ( int t_motor ) {
  motor0 (1024, 1);
  motor1 (1024, 0);
  delay (t_motor);
}

void left ( int t_motor ) {
  motor0 (1024, 1);
  motor1 (1024, 1);
  delay (t_motor);
}

void right ( int t_motor ) {
  motor0 (1024, 0);
  motor1 (1024, 0);
  delay (t_motor);
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

