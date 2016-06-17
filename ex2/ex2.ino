/* Example 2
  by Rodolfo Cossovich http://rudi.plobot.com
  This example code is in the public domain.

  Ultrasound HC-SR04
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
#define pinSD3 10

#define trigPin D0
#define echoPin D1

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 500;           // interval at which to blink (milliseconds)


void setup()
{
  //
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println("starting...");
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    int distance = ultra();
    Serial.println ( distance );
    if (distance < 4) {  // This is where the LED On/Off happens
      Serial.print("really close!");
    
    }
    else {
      //do nothing
    }

    Serial.print(distance);
    Serial.println(" cm");
  }
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

