#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <gtkmm.h>
#include <string>
#include "TopMenuView.h"
#include "CardTableView.h"
#include "PlayerListView.h"
#include "HandCardsView.h"
#include "PlayerPickerView.h"
#include "Game.h"
#include "GameController.h"
#include "Observer.h"

class GameWindowView : public Gtk::Window, public Observer {
public:
  GameWindowView(const std::string, Game*, GameController*);
  virtual ~GameWindowView();
  virtual void update();
  void assignPlayerType(std::string, int);
  void playGame();
private:
  Gtk::VBox mainVBox;
  TopMenuView topMenu;
  CardTableView cardTable;
  PlayerListView playerList;
  HandCardsView handCards;
  Game* game_;
  GameController* controller_;
  // The index of the current player
  int currentPlayerIndex_;
};

#endif
