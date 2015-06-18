#include "Subject.h"

Subject::Subject() {}
Subject::~Subject() {}

void Subject::subscribe(Observer* o) {
  observers_.insert(o);
}

void Subject::notify(){
  Observers::iterator it;
  for(it= observers_.begin(); it != observers_.end(); it++){
    (*it)->update();
  }
}
