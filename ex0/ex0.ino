/* Example 0
  by Rodolfo Cossovich http://rudi.plobot.com
  This example code is in the public domain.

  RGB LED and Serial demonstration
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

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 500;           // interval at which to blink (milliseconds)


void setup()
{
  //
  Serial.begin(115200);

  pinMode( D0, OUTPUT);
  pinMode( D1, OUTPUT);
  pinMode( D2, OUTPUT);
  pinMode( D5, OUTPUT);
  pinMode( D6, OUTPUT);
  pinMode( D7, OUTPUT);
  pinMode( D8, OUTPUT);

  Serial.println("starting...");
}

void loop()
{
  breathe();
}


void breathe ( void ) {
  float currentMillis = millis() / 5000.0;
  int value = 512.0 + 512 * sin( currentMillis * 2.0 * PI  );
  analogWrite(D6, value);
  analogWrite(D7, value);
  analogWrite(D5, value);
}

