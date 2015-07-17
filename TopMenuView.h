#ifndef TOP_MENU_VIEW_H
#define TOP_MENU_VIEW_H

#include <gtkmm.h>
#include "Game.h"
#include "GameController.h"
#include "Observer.h"

class TopMenuView : public Gtk::HBox, public Observer {
public:                                               // PUBLIC
  TopMenuView(Gtk::Window&, Game*, GameController*);    // Constructor
  virtual ~TopMenuView();                               // Destructor
  virtual void update();                                // Update the view
private:                                              // PRIVATE
  void quitButtonClicked();                             // Quit button handler
  void seedButtonClicked();                             // Seed button handler
  Gtk::Window &parent_;                                 // GameWindowView reference
  Gtk::Button seedButton;                               // Start game with new seed button
  Gtk::Entry seedEntry;                                 // Text entry for new seed
  Gtk::Button quitButton;                               // Quit button
  Game* game_;                                          // Pointer to the model
  GameController* controller_;                          // Pointer to the controller
};

#endif
