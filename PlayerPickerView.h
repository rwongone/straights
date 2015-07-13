#ifndef PLAYER_PICKER_VIEW_H
#define PLAYER_PICKER_VIEW_H

#include <gtkmm.h>
#include <string>
#include <vector>

class PlayerPickerView : Gtk::Dialog {
public:
  PlayerPickerView(Gtk::Window&, std::string);
  virtual ~PlayerPickerView();
private:
  Gtk::RadioButton::Group group;
  std::vector<Gtk::RadioButton*> buttons;
};

#endif
