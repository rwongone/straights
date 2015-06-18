#include "Subject.h"

Subject::Subject() {}
Subject::~Subject() {}

void Subject::subscribe(View* view) {
  view_ = view;
}
