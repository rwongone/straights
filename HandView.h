#ifndef HAND_VIEW_H
#define HAND_VIEW_H

#include <gtkmm.h>
#include <string>
#include <sstream>
#include "Game.h"
#include "GameController.h"

class HandView : public Gtk::Frame {
public:
  HandView(Gtk::Window&, Game*, GameController*);
  virtual ~HandView();
private:
  Gtk::Window &parent_;
  Gtk::Table cards_;
  Gtk::Image images_[13];
  std::string toImageFile(const int, const int) const;
};

#endif
