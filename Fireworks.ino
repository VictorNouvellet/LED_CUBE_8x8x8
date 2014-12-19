void firework(int time)
{
  int randAnode = random(LEDS_PER_ROW*LEDS_PER_ROW);
  for(int i=0; i<LEDS_PER_ROW;i++)
  {
    long t = millis();
    while(millis() < t+ time)  {
      displayCoord(randAnode%LEDS_PER_ROW,randAnode/LEDS_PER_ROW,constrain(i, 0, LEDS_PER_ROW-1));
      delay(2);
      displayCoord(randAnode%LEDS_PER_ROW,randAnode/LEDS_PER_ROW,constrain(i-1, 0, LEDS_PER_ROW-1));
      delay(2);
    }
  }
}
