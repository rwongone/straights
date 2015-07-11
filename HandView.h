#ifndef HAND_VIEW_H
#define HAND_VIEW_H

#include <gtkmm.h>

class HandView : public Gtk::Frame {
public:
  HandView(Gtk::Window&);
  virtual ~HandView();
private:
  Gtk::Window &parent_;
  Gtk::HBox cardHBox;
  Gtk::Image *cards_[13];
};

#endif
