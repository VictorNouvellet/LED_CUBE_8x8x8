#define MICRO 10

//////// Utility Functions \\\\\\\\\\

/**
 * Displays the LED according to its number
 */
void displayNum(int num){
  num = constrain(num, 0,LEDS_PER_ROW*LEDS_PER_ROW*LEDS_PER_ROW-1); 
  
  displayLayer(num/(LEDS_PER_ROW*LEDS_PER_ROW));
  displayAnodeNum(num%(LEDS_PER_ROW*LEDS_PER_ROW));
}

/**
 * Displays the LED at the given x, y, z coordinate. x, y z between 1 and 5
 */
void displayCoord(int x, int y, int z){
  cathode(z);
  displayAnodeNum(y * LEDS_PER_ROW + x);
}

/**
 * Displays the anode column at the given x, y coordiate. 
 * Cathode must be handled seperately.
 */
void displayCoord(int x, int y){
  //convert x, y coordinate to corrresponding number value
  displayAnodeNum(y * LEDS_PER_ROW + x);
}

/**
 * MAGIC !
 * Displays the anode column with the given number value; [0, 63].
 */
void displayAnodeNum(int num){
  //constrain the argument to be between 0 and 63 inclusive.
  num = constrain(num, 0, LEDS_PER_ROW*LEDS_PER_ROW-1);
  
  /*
   * AND: selects the bit, the bit at weight will be 1 if the pin is to be high
   * >>: shifts the selected bit to the end of the word, making the value a 0 or 1
   * first result is lsb
   * digitalWrite: write the approptiate result (HIGH or LOW) to the appropriate decoder pin
   */
  for(int weight=1, pin=0; pin < 3; weight*=2, pin++)
    digitalWrite(pgm_read_word_near(anodeDecoderPins + pin) ,((num%LEDS_PER_ROW) & weight) >> pin);
  
  //Then, select the right decoder using the master decoder
  for(int weight=1, pin=0; pin < 3; weight*=2, pin++)
    digitalWrite(pgm_read_word_near(masterDecoderPins + pin) ,((num/LEDS_PER_ROW) & weight) >> pin);
    
  //delay, this is the absoloute minimum time the light will be displayed. 
  //ensures adiquate delay for decoders as well. 
  delayMicroseconds(MICRO);
}

void cathode(int z){
//To improve : if z>7, then light all the layers
  
  displayLayer(z);
}

/*
 * Displays the cathode layer with the given number value; [0, 7].
 */
void displayLayer(int num){
  //constrain the argument to be between 0 and 7 inclusive.
  num = constrain(num, 0, LEDS_PER_ROW-1);
  
  /*
   * AND: selects the bit, the bit at weight will be 1 if the pin is to be high
   * >>: shifts the selected bit to the end of the word, making the value a 0 or 1
   * first result is lsb
   * digitalWrite: write the approptiate result (HIGH or LOW) to the appropriate decoder pin
   */
  for(int weight=1, pin=0; pin < 3; weight*=2, pin++)
    digitalWrite(pgm_read_word_near(cathodeDecoderPins + pin) ,(num & weight) >> pin);
}
