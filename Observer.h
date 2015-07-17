#ifndef _OBSERVER_H
#define _OBSERVER_H

class Observer {
public:                     // PUBLIC
  Observer();                 // Constructor
  virtual ~Observer();        // Destructor
  virtual void update() = 0;  // Update view with model data
};

#endif
