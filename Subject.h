#ifndef _SUBJECT_
#define _SUBJECT_

#include "Observer.h"
#include <set>

class Subject {
public:
  Subject();
  ~Subject();
  void subscribe(Observer*);
protected:
  void notify();
private:
  typedef std::set<Observer*> Observers;
  Observers observers_;
};

#endif
