#ifndef MENUENTRY_H
#define MENUENTRY_H

#include "Arduino.h"

class MenuEntry
{

public:

  typedef MenuEntry* (callBack)(MenuEntry *self, int);
  
  MenuEntry *update(int button);
  MenuEntry *show(int button);

  callBack *next;
  callBack *previous;
  callBack *validate;
  callBack *showFn;

  char* line1;
  char* line2;

};

#endif

