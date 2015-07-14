#ifndef HAND_CARDS_VIEW_H
#define HAND_CARDS_VIEW_H

#include <gtkmm.h>
#include <string>
#include <sstream>
#include "Game.h"
#include "GameController.h"

class HandCardsView : public Gtk::Frame {
public:
  HandCardsView(Gtk::Window&, Game*, GameController*);
  virtual ~HandCardsView();
private:
  Gtk::Window &parent_;
  Gtk::Table cards_;
  Gtk::Image images_[13];
  Game* game_;
  GameController* controller_;
  std::string toImageFile(const int, const int) const;
};

#endif
