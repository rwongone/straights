#ifndef PLAYER_LIST_VIEW_H
#define PLAYER_LIST_VIEW_H

#include <gtkmm.h>
#include "Game.h"
#include "GameController.h"
#include "Observer.h"

class PlayerListView : public Gtk::HBox, public Observer {
public:                                                // PUBLIC
  PlayerListView(Gtk::Window&, Game*, GameController*);  // Constructor
  virtual ~PlayerListView();                             // Destructor
  virtual void update();                                 // Update view with model data
private:                                               // PRIVATE
  Gtk::Window &parent_;                                  // Reference to GameWindowView
  Gtk::Frame frames_[4];                                 // Frames containing each player
  Gtk::VBox playerStats_[4];                             // VBox within each player frame
  Gtk::Button togglePlayerType_[4];                      // Toggle player type buttons
  Gtk::Label points_[4];                                 // Label with player points from discards
  Gtk::Label discards_[4];                               // Label with number of discards in current round
  Game* game_;                                           // Pointer to the model
  GameController* controller_;                           // Pointer to the controller
  void togglePlayerTypeButtonClicked(const int);         // Toggle Player Type button handler
};

#endif
