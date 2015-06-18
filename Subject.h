#ifndef _SUBJECT_
#define _SUBJECT_

class View;

class Subject {
public:
  Subject();
  ~Subject();
  void subscribe(View*);
  virtual void notify() = 0;
private:
  View* view_;
};

#endif
