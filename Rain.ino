void descendreColonne(int milli, int Num)  {
  
  for(int i = (LEDS_PER_ROW-1); i>=0; i--)  {
    long t = millis();
    while(millis() < t+ milli)  {
      displayNum(Num);
      cathode(i);
    }  
  }
}

void rain(int milli)  {
  //descendreColonne(milli, random(25));
  int firstRandy = random(LEDS_PER_ROW*LEDS_PER_ROW);
  //int secondRandy = random(25);
  //int thirdRandy = random(25);
  for(int i = (LEDS_PER_ROW-1); i>=0; i--)  {
    long t = millis();
    while(millis() < t+ milli)  {
        displayCoord(firstRandy%LEDS_PER_ROW,firstRandy/LEDS_PER_ROW,constrain(i, 0, LEDS_PER_ROW-1));
//      cathode(i);
//      displayAnodeNum(firstRandy);
      delay(2);
//      cathode((i-1)%LEDS_PER_ROW);
//      displayAnodeNum(firstRandy);
      displayCoord(firstRandy%LEDS_PER_ROW,firstRandy/LEDS_PER_ROW,constrain(i-1, 0, LEDS_PER_ROW-1));
      delay(2);
//      displayNum(secondRandy);
//      cathode(i);
//      delay(2);
//      displayNum(secondRandy);
//      cathode((i-1)%5);
//      delay(2);
//      displayNum(thirdRandy);
//      cathode(i);
//      delay(2);
//      displayNum(thirdRandy);
//      cathode((i-1)%5);
//      delay(2);
      //delayMicroseconds(250);
    }  
  }
}
