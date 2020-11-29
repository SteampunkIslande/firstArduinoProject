#include "UserInterface.h"

UserInterface::UserInterface() : 
lcd(0x27,16,2)
{
  buttonActive=true;
  //currentEntry=&makeRainEntry;
}

void UserInterface::printSomething(int lineNo,char* msg)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(msg);
}

void UserInterface::update()
{
  buttonState=analogRead(A0);

  if(buttonState < 990 && buttonActive)//Button down (has to go up again to consider it down again
  {
    lcd.clear();
  lcd.setCursor(0,0);
    buttonActive=false;//Deactivates the button to tell we already pressed it
    //MenuEntry* tempEntry=0;//Temporary pointer to safely update currentEntry
    if(buttonState<100)
    {
      //tempEntry = currentEntry->update(-1);
      if(true)
      {
        //currentEntry=tempEntry;
      }
      lcd.print("<-");
    }
    else if(buttonState < 600)
    {
      //tempEntry = currentEntry->update(0);
      if(true)
      {
        //currentEntry=tempEntry;
      }
      lcd.print("Menu");
    }
    else if(buttonState <780)
    {
      //tempEntry = currentEntry->update(1);
      if(true)
      {
        //currentEntry=tempEntry;
      }
      lcd.print("->");
    }
    Serial.println(/*currentEntry->_line1*/"Clicked !");

  }

  if(analogRead(A0)>990)
  {
    buttonActive=true;
  }

}

void UserInterface::initializeUI()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello world");
}


