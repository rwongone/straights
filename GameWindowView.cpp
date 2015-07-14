#include "GameWindowView.h"

GameWindowView::GameWindowView(const std::string title): Gtk::Window(), mainVBox(), topMenu(*this), cardTable(*this), playerList(*this), handCards(*this) {
  set_title(title);

  for(int i = 0; i < 4; i++){
    PlayerPickerView picker(*this, "What type of player are you?");
  }

  add(mainVBox);
  mainVBox.pack_start(topMenu);
  mainVBox.pack_start(cardTable);
  mainVBox.pack_start(playerList);
  mainVBox.pack_start(handCards);

  mainVBox.show();
  topMenu.show();
  cardTable.show();
  playerList.show();
  handCards.show();
}

GameWindowView::~GameWindowView() {}

