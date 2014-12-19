/****************************/
/* ** Affichage tournant ** */

void turningDisplayString(String message, int time)
{
  int length = message.length();
  int letter[length];
  int n = 0;
  int face = 0;
  int j;
  unsigned long previousMillis = millis();

  for(int i=0; i<length; i++)  {
    letter[i] = charToIntPortal(message.charAt(i));
  }

  for(int d=0; d<(3*7+6*length-1); d++)  {

    while(millis() < time + previousMillis)  {

      for(int k=0; k<length; k++)  {
        j = 0;
        //n[k] = Alphabet[letter[k]][j] + 6 - 5*k - (d%26)%6; //We take a led to light from each character which we translate to the border of the plan

//        if(letter[k]>=27 && letter[k]<=37)
//          n = Digits[letter[k]-27][j];
//        else
//          n = Alphabet[letter[k]][j];

          n = pgm_read_byte_near(Alphabet[letter[k]] + j);
          //n = Alphabet[letter[k]][j];

        face = Face(n, 6 + 6*k - d);

        while(n != 0)  {
          //Condition on the viability of the led number --> 0 <=> no more led to light in character's array

          if(face != 0)//the LED is not on any face
          {
            int nZ = n/8;
            //            int nX = 6-5*k-(d%26)+(face-1)*7 + n%8;
            int nX = n%8 +(face-1)*7+6 + k*6 - d;
            displayIfPossible(nZ*8 + nX, face);
          }

          j++;
          n = pgm_read_byte_near(Alphabet[letter[k]] + j);
          //n = Alphabet[letter[k]][j];
//          if(letter[k]>=27 && letter[k]<=37)
//            n = Digits[letter[k]-27][j];
//          else
//            n = Alphabet[letter[k]][j];
          face = Face(n, 6 + 6*k - d); // Find the face where the LED have to be turned on after translation
        }
      }
    }
    previousMillis = millis();
  }
}

void turningDisplayChar(char character, int time)
{
  int letter= charToIntPortal(character);
  int n = 0;
  int face = 0;
  int j;
  unsigned long previousMillis = millis();

  for(int d=0; d<26; d++)  {
    while(millis() < time + previousMillis)  {
      j = 0;

//      if(letter>=27 && letter<=37)
//        n = pgm_read_byte_near(Digits[letter-27] + j);
//      else
      n = pgm_read_byte_near(Alphabet[letter] + j);

      face = Face(n, 6 - d);
      while(n != 0)  {
        //Condition on the viability of the led number --> 0 <=> no more led to light in character's array

        if(face != 0)//the LED is not on any face
        {
          int nZ = n/8;
          int nX = 6-d+(face-1)*7 + n%8;
          displayIfPossible(nZ*8 + nX, face);
        }

        j++;

//        if(letter>=27 && letter<=37)
//          n = Digits[letter-27][j];
//        else
//          n = Alphabet[letter][j];
        n = pgm_read_byte_near(Alphabet[letter] + j);
        //n = Alphabet[letter][j];
        face = Face(n, 6 - d); // Find the face where the LED have to be turned on after translation
      }

    }
    previousMillis = millis();
  }
}

void turningDisplayStringOneAfterOne(String message, int time)
{
  for(int i=0; i<message.length(); i++)
    turningDisplayChar(message.charAt(i), time);
}

int Face(int faceNum, int xVector)  {
  int faceX = faceNum%8;//0->7
  int faceZ = faceNum/8;
  int Xtr = faceX+xVector;
  if(Xtr>=0 && Xtr<=7)
    return 1;
  else if(Xtr>-7 && Xtr<0)
    return 2;
  else if(Xtr>=-14 && Xtr<=-7)
    return 3;
  else
    return 0;
}

void displayIfPossible(int ntr, int face)
{
  if(ntr>=0 && ntr<64)  {
    int X,Y;
    int Z = ntr/8;
    switch(face)  {
    case 1:
      //ntr = ntr+56*(ntr/8+1)+7-2*(ntr%8);
      X = 7 - (ntr%8);
      Y = 7;
      break;
    case 2:
      X = 7;
      Y = ntr%8;
      break;
    case 3:
      X = ntr%8;
      Y = 0;
      break;
    default:
      X = 7;
      Y = 7;
    }
    displayCoord(X,Y,Z);
    delayMicroseconds(600);
  }


}
















