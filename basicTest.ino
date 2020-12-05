#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#include "UserInterface.h"
#include "MenuEntry.h"
#include "Timer.h"


#define DHTPIN_1 2
#define DHTPIN_2 3



#define DHTTYPE DHT22

DHT dht1(DHTPIN_1, DHTTYPE);
DHT dht2(DHTPIN_2, DHTTYPE);

boolean rain=false;//--Tells if it should rain or not

int currTempShown=0;
int currHumiShown=0;

int temperatures[4]={
  0,10,20,30};

int humidities[2]={
  50,90};

int startDayH=9;
int startDayM=0;

int endDayH=20;
int endDayM=0;

char line1[17];
char line2[17];

Timer sensorTimer;

boolean isUIActive=false;
UserInterface ui;

MenuEntry *toMakeItRainEntry(MenuEntry * self, int button)
{
  return &ui.makeRainEntry;
}

MenuEntry *toTemperatureEntry(MenuEntry * self, int button)
{

  return &ui.lookTempEntry;
}

MenuEntry *toHumidityEntry(MenuEntry *self, int button)
{
  return &ui.lookHumiEntry;
}

MenuEntry *toStopRainEntry(MenuEntry *self, int button)
{
  return &ui.stopRainEntry;
}

MenuEntry *toTempWatcher(MenuEntry *self, int button)
{
  return &ui.temperWatcher;
}

MenuEntry *toHumidityWatcher(MenuEntry *self, int button)
{
  return &ui.humidiWatcher;
}

MenuEntry *navigateTemperature(MenuEntry *self, int button)
{
  currTempShown+=button;
  if(currTempShown<0)
  {
    currTempShown=3;
  }
  currTempShown=currTempShown%4;
  Serial.println(temperatures[currTempShown]);
  return self;
}

MenuEntry *navigateHumidity(MenuEntry *self, int button)
{
  currHumiShown+=button;
  if(currHumiShown<0)
  {
    currHumiShown=1;
  }
  currHumiShown=currHumiShown%2;
  return self;
}

void showMakeRainEntry(char *line1,char *line2)
{
  snprintf(line1,17,"Faire pleuvoir !");
  snprintf(line2,17,"     < OK >     ");
}

void showStopRainEntry(char *line1,char *line2)
{
  snprintf(line1,17,"Arreter la pluie");
  snprintf(line2,17,"     < OK >     ");
}

void showTempEntry(char *line1,char *line2)
{
  snprintf(line1,17,"Afficher temp.");
  snprintf(line2,17,"     < OK >     ");
}

void showHumiEntry(char *line1,char *line2)
{
  snprintf(line1,17,"Afficher humidi.");
  snprintf(line2,17,"     < OK >     ");
}

void showTemperatureEntry(char *line1,char *line2)
{
  snprintf(line1,17,"Afficher temp.");
  snprintf(line2,17,"     < OK >     ");
}

void showTemperature(char *line1,char *line2)
{
  snprintf(line1,17,"Temp. %d: %2d.%d%cC",currTempShown+1,temperatures[currTempShown]/10,temperatures[currTempShown]%10,223);
  snprintf(line2,17,"     < OK >     ");
}

void showHumidity(char *line1,char *line2)
{
  snprintf(line1,17,"Humidity: %3d\%",humidities[currHumiShown]);
  snprintf(line2,17,"     < OK >     ");
}

void setup()
{
  Serial.begin(9600);
  ui.initializeUI();

  ui.makeRainEntry.previous=toHumidityEntry;
  ui.makeRainEntry.validate=toStopRainEntry;
  ui.makeRainEntry.next=toTemperatureEntry;
  ui.makeRainEntry.showFn=showMakeRainEntry;

  ui.stopRainEntry.previous=0;
  ui.stopRainEntry.validate=toMakeItRainEntry;
  ui.stopRainEntry.next=0;
  ui.stopRainEntry.showFn=showStopRainEntry;

  ui.lookTempEntry.previous=toMakeItRainEntry;
  ui.lookTempEntry.validate=toTempWatcher;
  ui.lookTempEntry.next=toHumidityEntry;
  ui.lookTempEntry.showFn=showTempEntry;


  ui.lookHumiEntry.previous=toTemperatureEntry;
  ui.lookHumiEntry.validate=/*toHumidityWatcher*/0;
  ui.lookHumiEntry.next=toMakeItRainEntry;
  ui.lookHumiEntry.showFn=showHumiEntry;

  ui.temperWatcher.previous=navigateTemperature;
  ui.temperWatcher.next=navigateTemperature;
  ui.temperWatcher.validate=toTemperatureEntry;
  ui.temperWatcher.showFn=showTemperature;
  
  dht1.begin();
  dht2.begin();


}

void retrieveSensorInfo()
{
  temperatures[0]=(int)(dht1.readTemperature()*10);
  temperatures[1]=(int)(dht2.readTemperature()*10);
  ui.refresh();
}


void loop()
{
  ui.update();
  if(sensorTimer.getElapsedTime()>5000l)
  {
    retrieveSensorInfo();
    sensorTimer.restart();
  }
}












