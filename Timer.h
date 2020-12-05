#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
  Timer() : 
  _t(millis())
  {
  }
  void restart()
  {
    _t=millis();
  }
  unsigned long getElapsedTime()
  {
    return millis()-_t;
  }
private:
  unsigned long _t;
};

#endif
