/* Example 6
  by Rodolfo Cossovich http://rudi.plobot.com
  This example code is in the public domain.

  Two motors with ultrasound
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
// pin9 USB
// D10 USB
//#define pinSD2 9 //reserved
#define SD3 10


//pins for ultrasound
#define PWMA D1
#define DIRA D3
#define PWMB D2
#define DIRB D4


#define trigPin D0
#define echoPin SD3


unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 500;           // interval at which to blink (milliseconds)


void setup()
{

  Serial.begin(115200);

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
  // servo();
  breathe();

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    int distance = ultra();
    Serial.println ( distance );
    if (distance < 4) {  // This is where the LED On/Off happens
      Serial.print("really close!");
      backward( 1000 );
      left( 200 );
    }
    else {
      //do nothing
      //  Serial.print(distance);
      //  Serial.println(" cm");
    }
    motor0 (1024, 1);
    motor1 (1024, 0);


  }
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

