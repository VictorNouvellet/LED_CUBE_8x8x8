void menu(int mode)  {
  switch(mode)  {
  case 0:
    if(lastMessage != "")
      turningDisplayString(lastMessage,90);
    else
      turningDisplayString(connexionState, 70);
    break;
  case 1:
    rand(50);
    break;
  case 2:
    allTest(10);
    break;
  case 3:
    SnakeAround(20, false);
    break;
  case 4:
    SnakeAround(20, true);
    break;
  case 5:
    firework(100);
    break;
  case 6:
    rain(80);
    break;
  case 7:
    DisplayVumeter();
    break;
  case 8:
    LeapDraw();
    break;
  case 9:
    littleLight(10, true, true);
    break;
  default:
    rain(100);
    break;
  }
}

//    gateau();
//    turningDisplayStringOneAfterOne("TIPE", 35);
//    displayAlphabet(800);
//    displayChar('O', 2000);
//    displayString("VICO ", 600);
//    testitall(10);
