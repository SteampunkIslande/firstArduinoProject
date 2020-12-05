
#include "MenuEntry.h"


MenuEntry* MenuEntry::update(int button)
{
  if(button==-1)
  {
    if(previous)
    {
      return previous(this,button);
    }
  }
  if(button==0)
  {
    if(validate)
    {
      return validate(this,button);
    }
  }
  if(button==1)
  {
    if(next)
    {
    return next(this,button);
    }
  }
  
  return 0;
  
}

void MenuEntry::show(char* line1,char* line2)
{
  if(showFn)
  {
    showFn(line1,line2);
  }
}



