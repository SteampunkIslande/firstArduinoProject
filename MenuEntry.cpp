
#include "MenuEntry.h"

MenuEntry::MenuEntry()
{
  nextEntry=0;
  previousEntry=0;
  okEntry=0;
}

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
      return previousEntry;
    }
    if(button==1)
    {
      return nextEntry;
    }
  }

  void show(char* line1,char* line2)
  {
    if(isRaining)
    {
      //-----------------OOOOOOOOOOOOOOOO
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

class HumidityEntry : 
public MenuEntry
{
public:
  HumidityEntry()
  {
    curHumiShown=0;
    showingHumi=false;
  }

  MenuEntry* onClick(int button)
  {
    if(showingHumi)
    {
      if(button<0)
      {
        curHumiShown=curHumiShown>0?curHumiShown-1:humiCount-1;
      }
      if(button>0)
      {
        curHumiShown=curHumiShown<humiCount-1?curHumiShown+1:0;
      }
      if(button==0)
      {
        showingHumi=false;
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
        showingHumi=true;
      }
      return this;
    }
  }

  void show(char* line1, char* line2)
  {
    if(showingHumi)
    {
      snprintf(line1,17,"Humidit%c: %3d\%",233,humidities[curHumiShown]);
      snprintf(line2,17,"     < OK >     ");
    }
    else
    {
      snprintf(line1,17," Afficher humi. ");
      snprintf(line2,17,"      <OK>      ");
    }
  }

  int* humidities;
  int humiCount;

private:
  boolean showingHumi;
  int curHumiShown;

};




