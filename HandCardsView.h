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
  void setHand(const int, std::vector<Card*>);
private:
  Gtk::Window &parent_;
  Gtk::Table cards_;
  Gtk::Button clickableImages_[13];
  sigc::connection clickableImagesHandlers_[13];
  Gtk::Image images_[13];
  // Gtk::Button discardButtons_[13];
  // sigc::connection discardButtonsHandlers_[13];
  Gtk::Image discardIcons_[13];
  Game* game_;
  GameController* controller_;
  std::string toImageFile(const int, const int) const;
  std::string toImageFile(const Card&) const;
  void cardInHandClicked(const int, Card);
  void discardButtonClicked(const int, Card);
  void NOOP() const;
  Player* currentPlayer_;
};

#endif
