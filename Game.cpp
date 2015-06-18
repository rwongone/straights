#include "Game.h"

// Constructor
Game::Game(int seed = 0): deck_(new Deck(seed)), table_(new Table()) {}

Game::~Game() {
  delete table_;
  for (int i=0; i<4; i++) {
    delete players_[i];
  }
}

void Game::setStartingPlayer(int index) {
  assert(0 <= index && index < 4);
  currentPlayer_ = players_[index];
}

void Game::setPlayer(int index, Player* player) {
  players_[index] = player;
}

void Game::setPlayerHand(int index, std::vector<Card*> hand) {
  players_[index]->setHand(hand);
}

std::vector<Card*> Game::getLegalMoves(int index){
  Player* player = getPlayer(index);
  std::vector<Card*> hand = player->getHand();
  std::vector<Card*> legalMoves;
  for (auto it = hand.begin(); it != hand.end(); ++it) {
    if (table_->isLegalCard(*it)) {
      legalMoves.push_back(*it);
    }
  }
  return legalMoves;
}

Deck* Game::getDeck() {
  return deck_;
}

Player* Game::getPlayer(int index){
  // Assert valid index
  return players_[index];
}

Table* Game::getTable() {
  return table_;
}

void Game::setGameOver(){
  gameOver_ = true;
}

void Game::gameEnd(){
  // clean up
}

bool Game::isGameDone() {
  return gameOver_;
}

void Game::notify() {

}
