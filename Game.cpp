#include "Game.h"

// Constructor - Takes an int which is used as a seed to shuffle the deck
Game::Game(int seed = 0): deck_(new Deck(seed)), table_(new Table()), shouldQuit_(false), gameOver_(false) {}

// Destructor - Delete the table and players
Game::~Game() {
  delete deck_;
  delete table_;
  for (int i=0; i<4; i++) {
    delete players_[i];
  }
}

// Accessor - Returns the player at the given index
Player* Game::getPlayer(int index){
  // Assert valid index
  return players_[index];
}

// Accessor - Returns the deck
Deck* Game::getDeck() {
  return deck_;
}

// Accessor - Returns the table
Table* Game::getTable() {
  return table_;
}

// Mutator - Sets the game to quit mode: (The program should shut down)
void Game::setQuit() {
  shouldQuit_ = true;
}

// Mutator - Sets the round to done. (52 cards have been played)
void Game::setGameOver(){
  gameOver_ = true;
}

// Accessor - Returns whether the game should quit
bool Game::shouldQuit() const{
  return shouldQuit_;
}

// Accessor - Returns whether the round is done
bool Game::isGameDone() const{
  return gameOver_;
}

// Mutator - Sets the player at the given index
void Game::setPlayer(const int index, Player* player) {
  players_[index] = player;
}

// Mutator - Sets the starting player
void Game::setStartingPlayer(const int index) {
  assert(0 <= index && index < NUMBER_OF_PLAYERS);
  startingPlayer_ = players_[index];
}

// Mutator - Saves the index of the current player
void Game::setCurrentPlayer(const int index){
  currentPlayer_ = index;
}

// Accessor - Gets the index of the current player
int Game::getCurrentPlayer() const{
  return currentPlayer_;
}

// Mutator - Gives the player a set of cards
void Game::setPlayerHand(const int index, std::vector<Card*> hand) {
  players_[index]->setHand(hand);
}

// Accessor - Returns a set of a player's legal moves
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

void Game::startGame() {
  gameOver_ = false;
}
