#include "GameWindowView.h"
#include <iostream>

GameWindowView::GameWindowView(const std::string title, Game* game, GameController* controller) :
  // Initialization List
  topMenu(*this, game, controller),
  cardTable(*this, game, controller),
  playerList(*this, game, controller),
  handCards(*this, game, controller),
  game_(game),
  controller_(controller) {

  // Start observing the Facade
  game->subscribe(this);

  set_title(title);

  for(int i = 0; i < 4; i++){
    PlayerPickerView picker(*this, "What type of player are you?", i);
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

  while (!game_->shouldQuit()) {
    controller_->startGame();
    controller_->dealCards();
    controller_->cleanTable();
    std::cerr << *(game_->getDeck()) << std::endl;
    std::cerr << "A new round begins. It's player " << (controller_->findStartingPlayerIndex()+1) << "'s turn to play." << std::endl;
    handCards.update();
    break;
  }

  // // Declare winners
  // if (game_->isGameDone()) {
  //   std::vector<int> winners = controller_->winners();
  //   for (auto it = winners.begin(); it != winners.end(); ++it) {
  //     // std::cout << "Player " << *it << " wins!" << std::endl;
  //   }
  // }
}

GameWindowView::~GameWindowView() {}

void GameWindowView::update(){}

void GameWindowView::assignPlayerType(std::string playerType, int whichPlayer){
  // Parse Human Player or Computer Player
  controller_->setPlayer(whichPlayer, playerType);
  std::cerr << whichPlayer << " " << playerType << std::endl;
}
