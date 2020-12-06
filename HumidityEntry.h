#ifndef HUMIDITYENTRY_H
#define HUMIDITYENTRY_H

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
      snprintf(line1,17,"Humidit%c: %3d%c",1,humidities[curHumiShown],37);
      snprintf(line2,17,"      %cOK%c      ",29,30);
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

#endif
