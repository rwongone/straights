#include "Subject.h"

// Constructor
Subject::Subject() {}

// Destructor
Subject::~Subject() {}

// Add observer to subscriber list
void Subject::subscribe(Observer* o) {
  subscribers_.push_back(o);
}

// Call update on each subscriber
void Subject::notify() {
  for (auto it=subscribers_.begin(); it!=subscribers_.end(); ++it) {
    (*it)->update();
  }
}
