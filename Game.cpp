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
