int charToIntPortal(char character)
{
  if((character >= ' ') && (character <= 'Z'))
    return (character-' ');
  else if((character == 'é') || (character == 'è'))
    return ('E' - ' ');
  else if((character == 'ç') || (character == 'Ç'))
    return ('C' - ' ');
  else if((character >= 'a') && (character <= 'z'))
    return (character-'a'+('A'-' '));
  else
    return 0;
}

void displayString(String string, int time) {
  for(int c = 0; c < string.length(); c++) {
    displayChar((char)string.charAt(c), time);
  }
}

void displayChar(char character, int time)  {
  int correspondingRankInAlphabet = charToIntPortal(character);
  displayCharOnePlan(correspondingRankInAlphabet, time);
}

/* ** One Plan Display ** */

void displayCharOnePlan(int CharNumber, int time)
{
  //CharNumber = constrain(CharNumber, 0, ('Z'-'A'));
  unsigned long previousMillis = millis();

  while(millis() < time + previousMillis)
  {
    for(int i=0; i<25; i++)
    {
      if((pgm_read_byte_near(Alphabet[CharNumber] + i)==0))
        break;
      else if((pgm_read_byte_near(Alphabet[CharNumber] + i))==64)  {
        unsigned long pM = millis();
        
        while(millis()-pM < 2)
        {
          displayCoord(4,4,4);
          delayMicroseconds(1500);
        }
      }
      else  {
        int planNumber = pgm_read_byte_near(Alphabet[CharNumber] + i);
        displayCoord(planNumber%LEDS_PER_ROW, 0, planNumber/LEDS_PER_ROW);
        delayMicroseconds(1500);
      }
    }
  }
}

void displayDigitOnePlan(int Digit, int time)
{
  unsigned long previousMillis = millis();

  while(millis() < time + previousMillis)
  {
    for(int i=0; i<25; i++)
    {
      if((pgm_read_byte_near(Alphabet[charToIntPortal('0') + Digit] + i))==0)
        break;
      else if((pgm_read_byte_near(Alphabet[charToIntPortal('0') + Digit] + i))==64)  {
        unsigned long pM = millis();
        
        while(millis()-pM < 2)
        {
          displayCoord(4,4,4);
          delayMicroseconds(1500);
          displayCoord(4,4,3);
          delayMicroseconds(1500);
          displayCoord(4,3,4);
          delayMicroseconds(1500);
          displayCoord(3,4,4);
          delayMicroseconds(1500);
          displayCoord(3,3,4);
          delayMicroseconds(1500);
          displayCoord(4,3,3);
          delayMicroseconds(1500);
          displayCoord(3,4,3);
          delayMicroseconds(1500);
          displayCoord(3,3,3);
          delayMicroseconds(1500);
        }
      }
      else  {
        int planNumber = pgm_read_byte_near(Alphabet[charToIntPortal('0') + Digit] + i);
        displayCoord(planNumber%LEDS_PER_ROW, 0, planNumber/LEDS_PER_ROW);
        delayMicroseconds(1200);
      }
    }
  }
}

/* ** Character/String Patterns ** */

void displayAlphabet(int time)
{
  for(int j=0; j<26; j++)
    displayChar(j, time);
}

void displayCountDown(int time);



