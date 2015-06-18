#include "GameController.h"

GameController::GameController(Game* game): game_(game) {}

void GameController::setPlayer(int index, std::string playerType) {
  assert(playerType == "h" || playerType == "c");
  if (playerType == "h"){
    game_->setPlayer(index, new HumanPlayer());
  } else {
    game_->setPlayer(index, new ComputerPlayer());
  }
}

void GameController::dealCards() {
  for (int i=0; i<4; i++){ // Use constants
    std::vector<Card*> playerHand;
    for(int j = 0; j < 13; j++){ // Use constants
      playerHand.push_back(game_->getDeck()->getCard(13*i+j)); // Use constants
    }
    game_->setPlayerHand(i, playerHand);
  }
}

void GameController::setPlayerHand(int index, std::vector<Card*> hand) {
    game_->setPlayerHand(index, hand);
}

// Pre: The 7S card must be in one player's hand.
int GameController::findStartingPlayer() {
  for(int i = 0; i < 4; i++){
    if(game_->getPlayer(i)->hasStartCard()){
      game_->setCurrentPlayer(i);
      return i;
    }
  }
  assert(false);
}

// return false if game continues
bool GameController::playTurn(int index) {
  return false;
}
