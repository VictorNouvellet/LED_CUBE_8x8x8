void AnalyseCommand()  {
  //inputString = inputString.substring(0,inputString.length()-1); //delete the '$'
  inputString.replace("$", "");//delete the '$'

  //Serial.println(inputString);
  
  //Vumetre
  if(inputString.charAt(0)=='%')  {
    //inputString -- We now have a JSON string
    //In the form : %[6,5,5,5,4,4,4,3,3,4,3,3,3,2,2,2,2,2,2,2,2,2,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    //Analyse the JSON string (best in an array)
    for(int i=0; i<64; i++)  {
      vumeter[i]=inputString.charAt(2*(i+1)) - '0';
    }
    //If success change mode and save the array (vumeter[])
    mode = 7;
  }
  //Coloring with your finger over the LeapMotion
  else if(inputString.charAt(0)=='.')  {
    inputString = inputString.substring(1);
    if(AddToColoring(inputString.toInt()) == -1)
      Serial.println("This number couldn't be displayed");
  }
  //Change Mode
  else if(isDigit(inputString.charAt(0)))  {
    mode = constrain(inputString.toInt(), 0, 9);
  }
  //Return led numbers of coloring (obsolet)
  else if(inputString.charAt(0)=='*') {
    //for(int i=0; i<(sizeof(coloring)/sizeof(int)); i++)
    for(int i=0; i<10; i++)
      Serial.println(coloring[i]-1);
  }
  //Display string
  else  {
    turningDisplayString(inputString,100);
    if(inputString.substring(0,6) != "N.SMS:")  {
      lastMessage = inputString;
      mode = 0;
    }
    else
      mode = 1;
  }

  // clear the string:
  inputString = "";
  commandComplete = false;
}

/*******************************************************
 * SerialEvent occurs whenever a new data comes in the
 * hardware serial RX.  This routine is run between each
 * time loop() runs, so using delay inside loop can delay
 * response.  Multiple bytes of data may be available.
 ******************************************************/
bool serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '$') {
      commandComplete = true;
    }
  }
  return commandComplete;
}




