#ifndef HAND_CARDS_VIEW_H
#define HAND_CARDS_VIEW_H

#include <gtkmm.h>
#include <string>
#include <sstream>

class HandCardsView : public Gtk::Frame {
public:
  HandCardsView(Gtk::Window&);
  virtual ~HandCardsView();
private:
  Gtk::Window &parent_;
  Gtk::Table cards_;
  Gtk::Image images_[13];
  std::string toImageFile(const int, const int) const;
};

#endif
