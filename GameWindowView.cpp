#include "GameWindowView.h"

GameWindowView::GameWindowView(const std::string title): Gtk::Window(), mainVBox(), topMenu(*this) {
  set_title(title);

  add(mainVBox);
  mainVBox.pack_end(topMenu);

  mainVBox.show();
  topMenu.show();
}

GameWindowView::~GameWindowView() {}

