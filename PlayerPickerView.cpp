#include "PlayerPickerView.h"

PlayerPickerView::PlayerPickerView(GameWindowView &parent, std::string title, int whichPlayer) :
  // Initialization List
  Dialog(title, parent, true, true),
  parent_(parent),
  whichPlayer_(whichPlayer) {

  set_default_size(400, 150);
  std::vector<std::string> options;
  options.push_back("Human Player");
  options.push_back("Computer Player");

  Gtk::VBox* contentArea = this->get_vbox();

  for(unsigned int i = 0; i < options.size(); i++){
    buttons.push_back(Gtk::manage(new Gtk::RadioButton(group, options[i])));
    contentArea->add(*buttons[i]);
  }

  add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
  show_all_children();

  int result = run();

  switch(result) {
    case Gtk::RESPONSE_OK:
      for(unsigned int i =0; i < options.size(); i++){
        if(buttons[i]->get_active()){
          parent.assignPlayerType(options[i], whichPlayer_);
          break;
        }
      }
      break;
  }
}

PlayerPickerView::~PlayerPickerView() {
  for (unsigned int i = 0; i < buttons.size(); i++ ){
    delete buttons[i];
  }
  buttons.clear();
}
