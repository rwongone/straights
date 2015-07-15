#ifndef HAND_CARDS_VIEW_H
#define HAND_CARDS_VIEW_H

#include <gtkmm.h>
#include <string>
#include <sstream>
#include <vector>
#include "Game.h"
#include "GameController.h"
#include "Observer.h"
#include "Player.h"
#include "Card.h"

class HandCardsView : public Gtk::Frame, public Observer {
public:
  HandCardsView(Gtk::Window&, Game*, GameController*);
  virtual ~HandCardsView();
  virtual void update();
  void setHand(std::vector<Card*>);
private:
  Gtk::Window &parent_;
  Gtk::Table cards_;
  Gtk::Image images_[13];
  Game* game_;
  GameController* controller_;
  std::string toImageFile(const int, const int) const;
  std::string toImageFile(const Card&) const;
  Player* currentPlayer_;
};

#endif
