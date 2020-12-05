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
  
  MenuEntry makeRainEntry;
  MenuEntry stopRainEntry;
  MenuEntry lookTempEntry;
  MenuEntry lookHumiEntry;


  MenuEntry temperWatcher;
  MenuEntry humidiWatcher;

private:

  boolean buttonActive;

  int buttonState=1023;

  LiquidCrystal_I2C lcd;

  MenuEntry* currentEntry;
  
  char line1[17];
  char line2[17];
  
  
  Timer buttonClick;
  Timer lastTimeClicked;
  
  boolean isUIActive;



};

#endif


