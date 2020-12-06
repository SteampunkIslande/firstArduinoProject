#ifndef CONTROLRAIN_H
#define CONTROLRAIN_H

#include "MenuEntry.h"

class ControlRain : 
public MenuEntry
{
public:

  ControlRain()
  {
    isRaining=false;
    makeRain=0;
    stopRain=0;
  }

  MenuEntry *onClick(int button)
  {
    if(button==0)
    {
      if(isRaining)
      {
        if(stopRain)
          stopRain();
      }
      else
      {
        if(makeRain)
          makeRain();
      }
      isRaining=!isRaining;
      return this;
    }
    if(button==-1)
    {
      Serial.println("LEFT click");
      return previousEntry;
    }
    if(button==1)
    {
      Serial.println("RIGHT click");
      return nextEntry;
    }
  }

  void show(char* line1,char* line2)
  {
    if(isRaining)
    {
      snprintf(line1,17,"Stopper la pluie");
      snprintf(line2,17,"       OK       ");
    }
    else
    {
      snprintf(line1,17,"Faire pleuvoir !");
      snprintf(line2,17,"       OK       ");
    }
  }

  callBackFunction makeRain;
  callBackFunction stopRain;
private:
  boolean isRaining;

};

#endif
