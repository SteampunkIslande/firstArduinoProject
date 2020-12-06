#ifndef MENUENTRY_H
#define MENUENTRY_H

#include "Arduino.h"

typedef void (*callBackFunction)(void);

class MenuEntry
{

public:
  MenuEntry();
  virtual MenuEntry *onClick(int button)=0;
  virtual void show(char* line1,char* line2)=0;

  MenuEntry *nextEntry;
  MenuEntry *previousEntry;
  MenuEntry *okEntry;

};

class ControlRain;
class TemperatureEntry;
class HumidityEntry;

#endif




