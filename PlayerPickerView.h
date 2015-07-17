#ifndef PLAYER_PICKER_VIEW_H
#define PLAYER_PICKER_VIEW_H

#include <gtkmm.h>
#include <string>
#include <vector>
#include "GameWindowView.h"

class GameWindowView;

class PlayerPickerView : Gtk::Dialog {
public:                                                // PUBLIC
  PlayerPickerView(GameWindowView&, std::string, int);   // Constructor
  virtual ~PlayerPickerView();                           // Destructor
private:                                               // PRIVATE
  GameWindowView &parent_;                               // Reference to GameWindowView
  Gtk::RadioButton::Group group;                         // Player type radio button group
  std::vector<Gtk::RadioButton*> buttons;                // Player type radio buttons
  int whichPlayer_;                                      // Index of current player
};

#endif
