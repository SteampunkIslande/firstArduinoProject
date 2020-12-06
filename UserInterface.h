#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Arduino.h"
#include "LiquidCrystal_I2C.h"
#include "MenuEntry.h"

#include "Timer.h"

class UserInterface
{
public:
  UserInterface();

  void update();

  void initializeUI();

  void printAll();

  void refresh();
  
  MenuEntry* currentEntry;
  
private:

  boolean buttonActive=true;

  int buttonState=1023;

  LiquidCrystal_I2C lcd;

  

  char line1[17];
  char line2[17];


  Timer buttonClick;
  Timer lastTimeClicked;

  boolean isUIActive;



};

#endif




