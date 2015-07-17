#ifndef _SUBJECT_
#define _SUBJECT_

#include <vector>
#include "Observer.h"

class Subject {
public:                               // PUBLIC
  Subject();                            // Constructor
  virtual ~Subject();                   // Destructor
  void subscribe(Observer*);            // Add observer to subscriber list
  void notify();                        // Call update on each subscriber
private:                              // PRIVATE
  std::vector<Observer*> subscribers_;  //
};

#endif
