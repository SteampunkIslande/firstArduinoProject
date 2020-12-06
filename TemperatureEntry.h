#ifndef TEMPERATUREENTRY_H
#define TEMPERATUREENTRY_H

#include "MenuEntry.h"

class TemperatureEntry : 
public MenuEntry
{
public:

  TemperatureEntry()
  {
    curTempShown=0;
    showingTemperature=false;
  }

  MenuEntry *onClick(int button)
  {
    if(showingTemperature)
    {
      if(button<0)
      {
        curTempShown=curTempShown>0?curTempShown-1:temperatureCount-1;
      }
      if(button>0)
      {
        curTempShown=curTempShown<temperatureCount-1?curTempShown+1:0;
      }
      if(button==0)
      {
        showingTemperature=false;
        return this;
      }
      return this;
    }
    else
    {
      if(button<0)
      {
        return previousEntry;
      }
      if(button>0)
      {
        return nextEntry;
      }
      if(button==0)
      {
        showingTemperature=true;
      }
      return this;
    }
  }

  void show(char* line1,char* line2)
  {
    if(showingTemperature)
    {
      snprintf(line1,17,"Temp. %d: %2d.%d%cC",curTempShown+1,temperatures[curTempShown]/10,temperatures[curTempShown]%10,223);
      snprintf(line2,17,"      <OK>      ");
    }
    else
    {
      snprintf(line1,17," Afficher temp. ");
      snprintf(line2,17,"      <OK>      ");
    }
  }

  int* temperatures;
  int temperatureCount;

private:
  boolean showingTemperature;
  int curTempShown;
};

#endif
