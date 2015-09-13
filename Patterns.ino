#define DISPLAY_TIME 10000

/**
 * Display a random and delay the given time value 
 */
 void rand(int milli){
  displayNum(random(LEDS_PER_ROW*LEDS_PER_ROW*LEDS_PER_ROW));  
  delay(milli);
}

/**
 * Tests all LEDs, x -> y -> z
 */
void allTest(int milli){
  for(int z = 0; z < LEDS_PER_ROW; z++){
    for(int y = 0; y < LEDS_PER_ROW; y++){
      for(int x = 0; x < LEDS_PER_ROW; x++){
        displayCoord(x, y, z);
        delay(milli);
      }
    }
  }
}

/**
* Draw the border of a square, beginning to the given coordonate
* The x variable is fixed for the sqaure to be drawn on the y,z plan
*/
void xSquareBorder(int milli, int xStart, int yStart, int zStart, int squareSize) {

  // TODO : Are the corner displayed twice ? Think about it. Later... :D. Sure they do x)

  int x = xStart,
      y = yStart,
      z = zStart;

  // draw the first side of the border
  // y iterates (increasing) over the width, z is fixed
  for (; y < yStart + squareSize; ++y){
    displayCoord(x, y, z);
    delay(milli);
  }

  // draw the second side of the border
  // y is fixed, z iterates (increasing) over the width
  for (; z < zStart + squareSize; ++z){
    displayCoord(x, y, z);
    delay(milli);
  }

  // draw the third side of the border
  // y iterates (decreasing) over the width, z is fixed
  for (; y >= yStart; --y){
    displayCoord(x, y, z);
    delay(milli);
  }

  // draw the fourth side of the border
  // y is fixed, z iterates (decreasing) over the width
  for (; z < zStart + squareSize; --z){
    displayCoord(x, y, z);
    delay(milli);
  }
}

/**
* @author Touzard Loïc loic.touzard@gmail.com
*
* Fill a "layer" with a spiral by default the x = 0 layer, y and z may change to draw the spiral
* The draw start at point (0,0,0) then iterate over +y, +z, -y, -z
*
* Algorithm : The spiral is drawn by drawing squares' borders.
*   Starting with a 8-width square (the outer one), drawing its border
*   Then drawing the inner 6-width square's border (8 minus 2 from the border)
*   And so forth ...
*/
void spiralTest(int milli, bool fromOuterToInner) {

  // OPTIMIZATION, use 'byte' variable since x, y, z, squareSize are constrainted between 0 and 8, 'byte' is widely enougb

  // firstly, initialyze the x coordonates
  int x = 0;  // Will be the fixed one
  int startPoint, squareSize;

  if (!fromOuterToInner)
  {
    // if the drawing direction start from the inside, change the startPoint to be the innermost square
   
    // startPoint = (LEDS_PER_ROW%2 == 0) ? LEDS_PER_ROW/2-1 : LEDS_PER_ROW/2;
    startPoint = LEDS_PER_ROW / 2 - 1 + (LEDS_PER_ROW % 2);
    // smaller width possible : 1 or 2
    // squareSize = (LEDS_PER_ROW%2 == 0) ? 2 : 1;
    squareSize = 2 - (LEDS_PER_ROW % 2);

    if (squareSize == 1){
      // the first point for the 1-width square
      displayCoord(x, startPoint, startPoint);
      delay(milli);
      ++squareSize;
      --startPoint;
    }

    // Let's draw the current Square's border
    for (; squareSize <= LEDS_PER_ROW; squareSize+2){
      xSquareBorder(milli, x, startPoint, startPoint, squareSize);
      //set the new start for the next spiral
      --startPoint;
    }

  }
  else{
    squareSize = LEDS_PER_ROW;  // Size of the outer square
    startPoint = 0; // spiral will start at (0,0,0)

    // Let's draw the current Square's border
    for (; squareSize > 1; squareSize-2){
      xSquareBorder(milli, x, startPoint, startPoint, squareSize);
      //set the new start for the next spiral
      ++startPoint;
    }

    if (squareSize == 1){
      // one last point for the 1-width square
      displayCoord(x, y, z);
      delay(milli);
    }
  }
}


void LeapDraw()  {
    for(int i=0;i<20; i++)  {
    if(coloring[i]==0)
      break;
    else  {
      displayNum(coloring[i]-1);
      delayMicroseconds(1500);
    }
  }
}

void DisplayVumeter()  {
  int vum = 0;
  for(int i=0;i<LEDS_PER_ROW*LEDS_PER_ROW; i++)  {
    //display the entire column
    vum = constrain(vumeter[i],0,8);
    if(vum > 0)  {
      for(int j=0; j<vum; j++)  {
        displayNum(j*(LEDS_PER_ROW*LEDS_PER_ROW)+i);
//        displayNum((vum-1)*(LEDS_PER_ROW*LEDS_PER_ROW)+i);
        delayMicroseconds(20);
      } 
    }
  }
}

//void DisplayVumeter()  {
//  //vumeter[] array
//  for(int i=0;i<(LEDS_PER_ROW*LEDS_PER_ROW); i++)  {
//    //display the entire column
//    if(vumeter[i] > 0)  {
//      int height = vumeter[i]-1;
//      for(int j=0; j<height; j++)  {
//        displayNum(j*LEDS_PER_ROW*LEDS_PER_ROW+i);
//        delayMicroseconds(1000);
//      } 
//    }
//  }
//}

/**
 * Tests all LEDs, x -> y -> z
 */
//void layerElevator(int time) {
//  for(int k=0; k<8; k++) {
//    for(int w=0; w<abs(time); w++) {
//      for(int j=0; j<8; j++) {
//        for(int i=0; i<8; i++) {
//          displayCoord(i,j,k);
//        }
//      }
//    }
//  }
//}
