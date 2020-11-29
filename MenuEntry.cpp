
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

MenuEntry* MenuEntry::show(int button)
{
  if(showFn)
  {
    showFn(this,button);
  }
}


