#ifndef PLAYER_PICKER_VIEW_H
#define PLAYER_PICKER_VIEW_H

#include <gtkmm.h>
#include <string>
#include <vector>
#include "GameWindowView.h"

class GameWindowView;

class PlayerPickerView : Gtk::Dialog {
public:
  PlayerPickerView(GameWindowView&, std::string);
  virtual ~PlayerPickerView();
private:
  GameWindowView &parent_;
  Gtk::RadioButton::Group group;
  std::vector<Gtk::RadioButton*> buttons;
};

#endif
