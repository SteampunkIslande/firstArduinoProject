#include <Wire.h>

#include <LiquidCrystal_I2C.h>

#include "UserInterface.h"
#include "MenuEntry.h"

boolean rain=false;//--Tells if it should rain or not

int currTempShown=0;
int currHumiShown=0;

float temperatures[4]={
  0.0,1.0,2.0,3.0};

int humidities[2]={
  50,90};

int startDayH=9;
int startDayM=0;

int endDayH=20;
int endDayM=0;


boolean isUIActive=false;
UserInterface ui;

void setup()
{
  Serial.begin(9600);
  ui.initializeUI();
  /*
  makeRainEntry.previous=toLookHumidEntry;
  makeRainEntry.validate=makeRain;
  makeRainEntry.next=toLookTempEntry;

  lookTempEntry.previous=toRainEntry;
  lookTempEntry.validate=toTempWatcher;
  lookTempEntry.next=toLookHumidEntry;

  lookHumiEntry.previous=toLookTempEntry;
  lookHumiEntry.validate=0;
  lookHumiEntry.next=toRainEntry;
*/

}

char line1[17];
char line2[17];

void loop()
{
  ui.update();
}










