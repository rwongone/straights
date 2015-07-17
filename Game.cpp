#include "Game.h"

// Constructor - Takes an int which is used as a seed to shuffle the deck
Game::Game(int seed = 0): deck_(new Deck(seed)), table_(new Table()), gameOver_(false), roundOver_(false) {}

// Destructor - Delete the table and players
Game::~Game() {
  delete deck_;
  delete table_;
  for (int i=0; i<4; i++) {
    delete players_[i];
  }
}

// ------Game Related Functions-----

// Mutator - Set the game state
void Game::setGameOver(bool isGameOver) {
  gameOver_ = isGameOver;
}

// Accessor - Returns the game state
bool Game::getGameOver() const{
  return gameOver_;
}

// Accessor - Returns the round state
void Game::setRoundOver(bool isRoundOver){
  roundOver_ = isRoundOver;
}

// Accessor - Returns whether the round is done
bool Game::getRoundOver() const{
  return roundOver_;
}

// Mutator - Sets the player at the given index
void Game::setPlayer(const int index, Player* player) {
  players_[index] = player;
}

// Mutator - Saves the index of the current player
void Game::setCurrentPlayer(const int index){
  currentPlayer_ = index;
}

// Accessor - Gets the index of the current player
int Game::getCurrentPlayer() const{
  return currentPlayer_;
}

// -----Table Related Functions

// Accessor - Returns the table
Table* Game::getTable() {
  return table_;
}

// Mutator - Clears the played cards
void Game::cleanTable() {
  table_->clean();
}

// Mutator - Adds card to table
void Game::playCardToTable(Card* theCard) {
  table_->playCard(theCard);
}

// Accessor - Return the cards that have been played
std::set<Card*>* Game::getCardsOnTable() const {
  return table_->getCards();
}

// -----Player Related Functions-----

// Accessor - Returns the player at the given index
Player* Game::getPlayer(int index){
  return players_[index];
}

// Mutator - Play a card
void Game::playPlayerCard(const int index, Card* card) {
  players_[index]->playCard(card);
}

// Mutator - Discard a card
void Game::discardPlayerCard(const int index, Card* card) {
  players_[index]->discardCard(*card);
}

// Mutator - Empty Discard pile
void Game::resetPlayer(const int index) {
  players_[index]->reset();
}

// Accessor - Returns the index of the player with the seven of spades
int Game::getStartingPlayerIndex(){
  for(int i = 0; i < 4; i++){
    if(players_[i]->hasStartCard()){
      return i;
    }
  }
  return -1;
}

// Accessor - Returns the player's hand
std::vector<Card*> Game::getPlayerHand(int index){
  return players_[index]->getHand();
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

// Mutator - Gives the player a set of cards
void Game::setPlayerHand(const int index, std::vector<Card*> hand) {
  players_[index]->setHand(hand);
}

// Accessor - Return the number of discarded cards for a player
int Game::getNumberOfDiscards(const int index) {
  return getPlayer(index)->getDiscards().size();
}

// Mutator - Set the player score
void Game::setPlayerScore(int index, int newScore){
  getPlayer(index)->setScore(newScore);
}

// Accessor - Return the player score
int Game::getPlayerScore(const int index){
  return getPlayer(index)->score();
}

// Accessor - Get the point total of discarded cards
int Game::getPlayerDiscardPoints(const int index){
  return getPlayer(index)->getDiscardPoints();
}

// Accessor - Return the discarded cards encoded as a string
std::string Game::getDiscardsAsString(const int index){
  std::vector<Card*> discards = getPlayer(index)->getDiscards();

  std::ostringstream message;
  for (auto it = discards.begin(); it != discards.end(); ++it) {
    message << " " << **it;
  }
  message << "\n";
  return message.str();
}

// Accessor - Return true if player is human controlled
bool Game::isPlayerHuman(const int index){
  return getPlayer(index)->isHuman();
}

// -----Deck Related Functions-----

// Mutator - Set the seed for the shuffle algorithm
void Game::setSeed(int seed){
  deck_->setSeed(seed);
}

// Mutator - Shuffle the deck
void Game::shuffleDeck(){
  deck_->shuffle();
}

// Accessor - Returns card from deck
Card* Game::getCardFromDeck(int index){
  return deck_->getCard(index);
}

