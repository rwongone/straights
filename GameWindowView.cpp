#include "GameWindowView.h"

GameWindowView::GameWindowView(const std::string title, Game* game, GameController* controller): Gtk::Window(), mainVBox(), game_(game), gameController_(controller), topMenu(*this, game, controller), cardTable(*this, game, controller), playerList(*this, game, controller), handList(*this, game, controller) {
  set_title(title);

  for(int i = 0; i < 4; i++){
    PlayerPickerView picker(*this, "What type of player are you?");
  }

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

