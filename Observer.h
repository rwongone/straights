#ifndef _OBSERVER_H
#define _OBSERVER_H

class Observer {
public:
  Observer();
  virtual ~Observer();
  virtual void update() = 0;
};

#endif
