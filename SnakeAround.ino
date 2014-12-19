/**
 * Snake Around External : Display a snake turning around and delay the given time value
 */
 void SnakeAround(int time, bool randomize)  {
   int h=altitude;
   
   if(randomize)  {
     h=random(2)*2-1+h; //h +ou- 1
     if(h>7)
       h=0;
     else if(h<0)
       h=7;
     altitude = h;
   }
   else
     h=ZSnake;
     
   //First line
   for(int l=0; l<LEDS_PER_ROW; l++)  {
     displayCoord(l,0,h);
     delay(time);
   }
   
   //Second line
   for(int m=1; m<LEDS_PER_ROW; m++)  {
     displayCoord((LEDS_PER_ROW-1),m,h);
     delay(time);
   }
   
   //Third line
   for(int n=(LEDS_PER_ROW-1)-1; n>=0; n--)  {
     displayCoord(n,(LEDS_PER_ROW-1),h);
     delay(time);
   }
   
   //Fourth line
   for(int p=(LEDS_PER_ROW-1)-1; p>0; p--)  {
     displayCoord(0,p,h);
     delay(time);
   }
   
   if(ZSnake == LEDS_PER_ROW-1)
     ZSnake = 0;
   else
     ZSnake++;
 }
