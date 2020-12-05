#include "UserInterface.h"


UserInterface::UserInterface() : 
lcd(0x27,16,2)
{
  buttonActive=true;
  snprintf(line1,17,"Hello world !");
  snprintf(line2,17,"Appuye sur OK :)");
  isUIActive=true;
}

void UserInterface::printAll()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(line1);
  lcd.setCursor(0,1);
  lcd.print(line2);
}

void UserInterface::update()
{
  buttonState=analogRead(A0);

  if(buttonState < 990 && buttonActive)//Button down (has to go up again to consider it down again
  {
    lastTimeClicked.restart();
    isUIActive=true;//Just clicked, so wake up if you were not
    buttonActive=false;//Deactivates the button to tell we already pressed it
    MenuEntry* tempEntry=0;//Temporary pointer to safely update currentEntry
    if(buttonState<100)
    {
      tempEntry = currentEntry->onClick(-1);
    }
    else if(buttonState < 600)
    {
      tempEntry = currentEntry->onClick(0);
    }
    else if(buttonState <780)
    {
      tempEntry = currentEntry->onClick(1);
    }
    if(tempEntry)
    {
      currentEntry=tempEntry;
    }
    refresh();
  }

  if(analogRead(A0)>990 && buttonClick.getElapsedTime()>500l)
  {
    buttonActive=true;
    buttonClick.restart();
  }
  
  if(lastTimeClicked.getElapsedTime()>30000l)
  {
    isUIActive=false;
  }

}

void UserInterface::refresh()
{
  if(currentEntry && isUIActive)
  {
    currentEntry->show(line1,line2);
    printAll();
  }
}

void UserInterface::initializeUI()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(line1);
  lcd.setCursor(0,1);
  lcd.print(line2);
}






