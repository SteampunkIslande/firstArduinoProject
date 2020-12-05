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

ControlRain rainControl;
TemperatureEntry temperatureEntry;
HumidityEntry humidityEntry;

void setup()
{
  Serial.begin(9600);
  ui.initializeUI();
  
  dht1.begin();
  dht2.begin();
  
  rainControl.previousEntry=&humidityEntry;
  rainControl.okEntry=0;
  rainControl.nextEntry=&temperatureEntry;
  
  temperatureEntry.previousEntry=&rainControl;
  temperatureEntry.okEntry=0;
  temperatureEntry.nextEntry=&humidityEntry;
  
  humidityEntry.

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













