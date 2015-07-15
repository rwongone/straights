#ifndef CARD_TABLE_VIEW_H
#define CARD_TABLE_VIEW_H

#include <gtkmm.h>
#include <sstream>
#include <iostream>
#include <string>
#include <set>
#include "Card.h"
#include "Game.h"
#include "GameController.h"
#include "Observer.h"

class CardTableView: public Gtk::Frame, public Observer {
public:
  CardTableView(Gtk::Window&, Game*, GameController*);
  ~CardTableView();
  virtual void update();
private:
  Gtk::Window &parent_;
  Gtk::Table cards_;
  Gtk::Image images_[13][4];
  Game* game_;
  Table* table_;
  GameController* controller_;
  std::set<Card*>* cardsOnTable_;
  std::string toImageFile(const int, const int) const;
  void setCard(const int, const int, const bool);
  void setCard(const Card, const bool);
};

#endif
