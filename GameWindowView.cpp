#include "GameWindowView.h"
#include <iostream>
#include <sstream>

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

  controller_->resetGame();
}

GameWindowView::~GameWindowView() {}

void GameWindowView::update() {
  if(game_->getRoundOver() && game_->getGameOver() == false){
    std::ostringstream message;
    for(int i = 0; i < 4; i++){
      message << "Player " << (i + 1) << "'s discards:";
      message << game_->getDiscardsAsString(i);
      message << "Player " << (i + 1) << "'s score: ";
      int oldScore = game_->getPlayerScore(i);
      int discardPoints = game_->getPlayerDiscardPoints(i);
      message << oldScore << " + ";
      message << discardPoints << " = ";
      message << oldScore + discardPoints << "\n";
    }
    RoundSummaryView summary(*this, message.str());
    controller_->updateScores();
  } else if(game_->getGameOver()){

    RoundSummaryView winners(*this, controller_->winners());
    controller_->resetGame();
  }
}

void GameWindowView::assignPlayerType(std::string playerType, int whichPlayer){
  // Parse Human Player or Computer Player
  controller_->setPlayer(whichPlayer, playerType);
  // std::cerr << whichPlayer << " " << playerType << std::endl;
}
