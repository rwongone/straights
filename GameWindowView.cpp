#include "GameWindowView.h"

GameWindowView::GameWindowView(const std::string title, Game* game, GameController* controller) :
  // Initialization List
  topMenu(*this, game, controller),
  cardTable(*this, game, controller),
  playerList(*this, game, controller),
  handCards(*this, game, controller),
  game_(game),
  controller_(controller) {

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

void GameWindowView::update(){}
