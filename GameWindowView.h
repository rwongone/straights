#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <gtkmm.h>
#include <string>
#include "TopMenuView.h"
#include "CardTableView.h"
#include "PlayerListView.h"
#include "HandCardsView.h"
#include "PlayerPickerView.h"
#include "RoundSummaryView.h"
#include "Game.h"
#include "GameController.h"
#include "Observer.h"

class GameWindowView : public Gtk::Window, public Observer {
public:                                                      // PUBLIC
  GameWindowView(const std::string, Game*, GameController*);   // Constructor
  virtual ~GameWindowView();                                   // Destructor
  virtual void update();                                       // Update view when notify() is called
  void assignPlayerType(std::string, int);                     // Tell controller to assign human or computer player
private:                                                     // PRIVATE
  Game* game_;                                                 // Pointer to the model
  GameController* controller_;                                 // Pointer to the controller
  Gtk::VBox mainVBox;                                          // VBox containing the 4 sections of the view
  TopMenuView topMenu;                                         // View containing "Start game with seed" and "Quit game" buttons
  CardTableView cardTable;                                     // View containing the cards that have been played on the table
  PlayerListView playerList;                                   // View containing the player points, discards and type toggle
  HandCardsView handCards;                                     // View containing the current player's cards
};

#endif
