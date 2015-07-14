#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <gtkmm.h>
#include <string>
#include "TopMenuView.h"
#include "CardTableView.h"
#include "PlayerListView.h"
#include "HandCardsView.h"
#include "PlayerPickerView.h"

class GameWindowView : public Gtk::Window {
public:
  GameWindowView(const std::string);
  virtual ~GameWindowView();
private:
  Gtk::VBox mainVBox;
  TopMenuView topMenu;
  CardTableView cardTable;
  PlayerListView playerList;
  HandCardsView handCards;
};

#endif
