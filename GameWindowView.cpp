#include "GameWindowView.h"

GameWindowView::GameWindowView(const std::string title): Gtk::Window(), mainVBox(), topMenu(*this), cardTable(*this), playerList(*this), handList(*this) {
  set_title(title);

  add(mainVBox);
  mainVBox.pack_start(topMenu);
  mainVBox.pack_start(cardTable);
  mainVBox.pack_start(playerList);
  mainVBox.pack_start(handList);

  mainVBox.show();
  topMenu.show();
  cardTable.show();
  playerList.show();
  handList.show();
}

GameWindowView::~GameWindowView() {}

