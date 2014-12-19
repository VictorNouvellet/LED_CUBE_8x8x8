//void shiftSurface(int milli, int surface)  {
//  int randy = random(5);
//  for(int k = (LEDS_PER_ROW-1); k >= 0; k--){
//    long t = millis();
//    while(millis()<t+(milli))  {
//      for(int i = 0; i < LEDS_PER_ROW; i++){
//        for(int j = 0; j < LEDS_PER_ROW; j++){
//          //delayMicroseconds(50);
//
//          if (surface == 1)  {  
//            displayCoord(j, i, (k+j)%LEDS_PER_ROW);
//          }
//          else if (surface == 2)  {  
//            displayCoord(j, i, (k+i)%LEDS_PER_ROW);
//          }
//          else if (surface == 3)  {  
//            displayCoord(j, i, (k+k)%LEDS_PER_ROW);
//          }
//          else  {  
//            displayCoord(j, i, k);
//          }
//          //          delayMicroseconds(50);
//          //          displayCoord(j, i, (k+(i*3*randy)%5+(j*3)%5)%5);
//        }
//      }
//    }
//  }
//}
//
//void testitall(int time)
//{
//  for(int i=0; i<512; i++)
//  {
//    displayNum(i);
//    //delayMicroseconds(time);
//  }
//}

int AddToColoring(int LedNumber)
{
  int shouldIlightThisLED;
  if(LedNumber<512 && LedNumber>=0)  {
    if(mode!=6)
      mode = 6;
      
    shouldIlightThisLED = 1;
    for(int i=0; i<20; i++)  {
      if(LedNumber==coloring[i]-1)  {
//        cutTheLED(i);
        shouldIlightThisLED = 0;
        break;
      }
    }
    if(shouldIlightThisLED)  {
      for(int i=0; i<20; i++)  {
        if(coloring[i]==0)  {
          coloring[i]=LedNumber+1;
          break;
        }
        if(i==20-1 && coloring[i]!=0)  {
          for(int j=0; j<20-1; j++)
            coloring[j] = coloring[j+1];
          coloring[20-1]=LedNumber+1;
        }
      }
    }
  }
  else  {
    shouldIlightThisLED = -1;
  }
  
  return shouldIlightThisLED;
}

void cutTheLED(int rank)
{
  if(rank<9)  {
    for(int i=rank; i<20-1; i++)  {
      coloring[i] = coloring[i+1];
      if(coloring[i+1]==0)
        break;
    }
  }
  else  {
    for(int i=0; i<20; i++)
      coloring[i] = 0;
  }
}


