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
  Deck* theDeck = game_->getDeck();
  for (int i=0; i<4; i++){ // Use constants
    std::vector<Card*> playerHand;
    for(int j = 0; j < 13; j++){ // Use constants
      playerHand.push_back(theDeck->getCard(13*i+j)); // Use constants
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
      game_->setStartingPlayer(i);
      return i;
    }
  }
  assert(false);
}

bool GameController::playTurn(int index) {
  game_->getPlayer(index)->playTurn();

  return isGameDone();
}

void GameController::quit() {
  game_->setGameOver();
}

bool GameController::isGameDone() {
  return game_->isGameDone();
}

void GameController::printHand(int index) const {
  game_->getPlayer(index)->printHand();
}

void GameController::printLegalMoves(int index) const {
  game_->getPlayer(index)->printLegalMoves(game_->getTable());
}
