#include <SoftwareSerial.h>
#include "ASCII.h"
#include "LEDs.h"
#include "Variables.h"

//SoftwareSerial impSerial =  SoftwareSerial(rxPin, txPin);

void setup() {
  // initialize serial:
  Serial.begin(9600);
  
  //Some variables to initialize
  inputString = "";
  lastMessage = "";
  commandComplete = false;
  ledNumber = 0;
  altitude = 3;
  ZSnake = 0;
  for(int k = 0;k<64; k++)
    vumeter[k] = k%8+1;
  for(int i=1; i<20; i++)
    coloring[i] = 0;
  randomSeed(analogRead(0));
  mode = 0;
  
  for(int i=0; i<3; i++)  {
    pinMode(pgm_read_word_near(anodeDecoderPins + i), OUTPUT);
    pinMode(pgm_read_word_near(masterDecoderPins + i), OUTPUT);
    pinMode(pgm_read_word_near(cathodeDecoderPins + i), OUTPUT);
  }
  
  //pinMode(rxPin, INPUT);
  //pinMode(txPin, OUTPUT);  // reserve 200 bytes for the inputString:
  inputString.reserve(100);
  
}

void loop() {
  // print the string when a newline arrives:
  if(serialEvent()) {
    AnalyseCommand();
  }

  // ASK : Comment et ou est inclu le commandManager ?
  menu(mode);
}

