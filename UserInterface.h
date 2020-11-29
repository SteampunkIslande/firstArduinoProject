#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Arduino.h"
#include "LiquidCrystal_I2C.h"
#include "MenuEntry.h"

class UserInterface
{
public:
  UserInterface();

  void update();

  void initializeUI();
  
  void printSomething(int lineNo,char* msg);

private:

  boolean buttonActive;

  int buttonState=1023;

  LiquidCrystal_I2C lcd;

  MenuEntry currentEntry;

  MenuEntry makeRainEntry;
  MenuEntry stopRainEntry;
  MenuEntry lookTempEntry;
  MenuEntry lookHumiEntry;


  MenuEntry temperWatcher;
  MenuEntry humidiWatcher;



};

#endif

