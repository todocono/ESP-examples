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
#define SD3 10

//#define trigPin D0
//#define echoPin D1//SD3
#define TrigEcho D0

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 500;           // interval at which to blink (milliseconds)


void setup()
{
  //
  Serial.begin(115200);

 //  pinMode(trigPin, OUTPUT);
 // pinMode(echoPin, INPUT);

  Serial.println("starting...");
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    int distance = ultra();
    if (distance < 200)   //checks
    {
      //Serial.println ( distance );
      //}

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
}


int ultra() {
  long duration, distance;
  pinMode(TrigEcho, OUTPUT);
//  delay(100);
  digitalWrite(TrigEcho, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(TrigEcho, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(TrigEcho, LOW); 
//  delayMicroseconds(11); // Added this line
  pinMode(TrigEcho, INPUT);
  
  duration = pulseIn(TrigEcho, HIGH);
  distance = (duration / 29) ;
  return (int)distance;
}

