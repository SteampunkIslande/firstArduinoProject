#ifndef MENUENTRY_H
#define MENUENTRY_H

#include "Arduino.h"

class MenuEntry
{

public:

  typedef MenuEntry* (*callBack)(MenuEntry *self, int);
  typedef void (*showFunction)(char* line1,char* line2);
  
  MenuEntry *update(int button);
  void show(char* line1,char* line2);

  callBack next;
  callBack previous;
  callBack validate;
  showFunction showFn;
  

};

#endif


