/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"


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

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 8
};

void playTone(int _pin, int _frequency, int _length){
  analogWriteFreq(_frequency);  // this is the line that makes it go bananas and reset
  analogWrite(_pin, 512);
  delay(_length);
  analogWrite(_pin, 0);
}


void setup() {
  pinMode(D5, OUTPUT);
  for (int thisNote = 0; thisNote < 8; thisNote++) { // iterate over the notes of the melody:
    int noteDuration = 1000 / noteDurations[thisNote];
    playTone(D5, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
}

void loop() {
  delay(1);
  
  // no need to repeat the melody.
}
