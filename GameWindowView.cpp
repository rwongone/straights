#include "GameWindowView.h"

GameWindowView::GameWindowView(const std::string title): Gtk::Window(), mainVBox(),
  topMenu(*this), cardTable(*this) {

  set_title(title);

  add(mainVBox);
  mainVBox.pack_start(topMenu);
  mainVBox.pack_start(cardTable);

  mainVBox.show();
  topMenu.show();
  cardTable.show();
}

GameWindowView::~GameWindowView() {}

