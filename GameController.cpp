#include "GameController.h"

// Constructor
GameController::GameController(Game* game): game_(game), numComputerPlayers_(0) {}

// Destructor
GameController::~GameController() {}

// GameController Exception Constructor
GameController::GameControllerException::GameControllerException(std::string code) : code_(code){

}

// Accessor - Return GameController Exception
std::string GameController::GameControllerException::code(){
  return code_;
}

// Player specified by index plays a card on the table
void GameController::playCard(const int index, Card card) {
  Card* cardToPlay = NULL;
  std::vector<Card*> legalMoves = game_->getLegalMoves(index);

  // std::cerr << "Player " << (index+1) << " legal moves: ";
  for(auto it = legalMoves.begin(); it != legalMoves.end(); ++it){
    // std::cerr << **it << " ";
    if(**it == card) {
      cardToPlay = *it;
    }
  }
  // std::cerr << std::endl;

  // This is not a legal play
  if(cardToPlay == NULL){
    // std::cerr << card << " is an illegal play." << std::endl;
    // throw GameControllerException("Illegal Play");
  } else {
    // Add card to table
    game_->playCardToTable(cardToPlay);
    game_->playPlayerCard(index, cardToPlay);
    nextTurn();
  }
  endTransaction();
}

// Player specified by index discards a card - Returns true if successful
void GameController::discardCard(const int index, Card card){
  // Assert that there are no legal moves available
  std::vector<Card*> legalMoves = game_->getLegalMoves(index);
  if(legalMoves.size() > 0){
    // std::cerr << "Legal moves exist, cannot discard." << std::endl;
    // throw GameControllerException("Legal Moves Exist");
  } else {
    // std::cout << "Player " << (index+1) << " discards " << card << "." << std::endl;

    Player* player = game_->getPlayer(index);
    player->discardCard(card);
    nextTurn();
  }
  endTransaction();
}

// Player specified by index ragequits and becomes a computer
void GameController::togglePlayerType(const int index) {
  // convert the player[index] to a computer player
  Player* playerToConvert = game_->getPlayer(index);
  if (playerToConvert->isHuman()) {
    game_->setPlayer(index, new ComputerPlayer(*playerToConvert));
    delete playerToConvert;
    numComputerPlayers_++;
    if (game_->getCurrentPlayer() == index) {
      playTurn(index);
    }
  } else {
    game_->setPlayer(index, new HumanPlayer(*playerToConvert));
    delete playerToConvert;
    numComputerPlayers_--;
  }
  endTransaction();
}

// Automove for a player
void GameController::playTurn(const int index) {
  std::vector<Card*> legalMoves = game_->getLegalMoves(index);
  std::vector<Card*> hand = game_->getPlayerHand(index);

  if (legalMoves.size() == 0) {
    Card* theCard = hand.front();
    discardCard(index, *theCard);
  } else {
    Card* theCard = legalMoves.front();
    playCard(index, *theCard);
  }
}

void GameController::playUntilHuman() {
  int currentPlayerIndex = game_->getCurrentPlayer();
  Player* thePlayer = game_->getPlayer(currentPlayerIndex);
  if (!thePlayer->isHuman()) {
    // std::cerr << "this is a computer " << currentPlayerIndex << std::endl;
    playTurn(currentPlayerIndex);
  } else {
    // std::cerr << "this is a human " << currentPlayerIndex << std::endl;
  }

}

void GameController::nextTurn(){
  int currentPlayerIndex = game_->getCurrentPlayer();
  currentPlayerIndex += 1;
  currentPlayerIndex %= 4;
  game_->setCurrentPlayer(currentPlayerIndex);
  std::vector<Card*> hand = game_->getPlayerHand(currentPlayerIndex);
  if (hand.size() == 0) {
    // std::cerr << "No moves available" << std::endl;
    roundOver();
    return;
  }
  playUntilHuman();
}

// Creates a new player based on type
void GameController::setPlayer(const int index, const std::string playerType) {
  assert(playerType == "Human Player" || playerType == "Computer Player");
  if (playerType == "Human Player"){
    game_->setPlayer(index, new HumanPlayer());
  } else {
    game_->setPlayer(index, new ComputerPlayer());
    numComputerPlayers_++;
  }
  // endTransaction();
}

// Tells the model whose turn it is
void GameController::updateCurrentPlayer(int index){
  game_->setCurrentPlayer(index);
  endTransaction();
}

// Prints the player specified by index's hand
void GameController::printHand(const int index) const {
  game_->getPlayer(index)->printHand();
}

// Prints the legal moves for a player specified by index
void GameController::printLegalMoves(const int index) const {
  game_->getPlayer(index)->printLegalMoves(game_->getTable());
}

// Returns true if the program should end
bool GameController::getRoundOver() const{
  return game_->getRoundOver();
}

// Returns true if the round is over
bool GameController::getGameOver() const{
  return game_->getGameOver() || numComputerPlayers_ == 4;
}

// Returns the winner(s) of the game
std::string GameController::winners() const {
  int minScore = 1000;
  std::vector<int> minPlayers;
  std::ostringstream returnValue;

  for (int i=0; i<4; i++) {
    int theScore = game_->getPlayer(i)->score();
    if (theScore == minScore) {
      minPlayers.push_back(i+1);
      minScore = game_->getPlayer(i)->score();
    } else if (theScore < minScore) {
      minPlayers.clear();
      minPlayers.push_back(i+1);
      minScore = game_->getPlayer(i)->score();
    }
  }

  for (auto it = minPlayers.begin(); it != minPlayers.end(); ++it) {
    returnValue << "Player " << *it << " wins!" << std::endl;
  }

  return returnValue.str();
}

void GameController::endTransaction() const {
  game_->notify();
}

void GameController::roundOver(){
  game_->setRoundOver(true);
}

void GameController::updateScores(){
  for(int i = 0; i < 4; i++){
    int oldScore = game_->getPlayerScore(i);
    int discardPoints = game_->getPlayerDiscardPoints(i);
    game_->setPlayerScore(i, oldScore + discardPoints);
    if(game_->getPlayerScore(i) >= 80){
      game_->setGameOver(true);
    }
  }
  if (game_->getGameOver()) {
    endTransaction();
  } else {
    resetRound();
  }
}

//--------------setup helpers----------------------
void GameController::resetGame(int seed){
  game_->setSeed(seed);
  resetGame();
}

void GameController::resetGame(){
  for(int i = 0; i < 4; i++){
    game_->setPlayerScore(i, 0);
  }

  game_->setGameOver(false);
  resetRound();
}

void GameController::resetRound(){
  resetPlayers();
  game_->setRoundOver(false);
  dealCards();
  cleanTable();
  determineStartingPlayer();
  playUntilHuman();
  endTransaction();
}

void GameController::resetPlayers(){
  for(int i = 0; i< 4; i++){
    game_->resetPlayer(i);
  }
}

void GameController::dealCards(){
  game_->shuffleDeck();
  for(int i = 0; i < 4; i++){
    std::vector<Card*> playerHand;
    for(int j = 0; j < 13; j++){
      playerHand.push_back(game_->getCardFromDeck(13 * i + j));
    }
    game_->setPlayerHand(i, playerHand);
  }
}

void GameController::cleanTable(){
  game_->cleanTable();
}

void GameController::determineStartingPlayer(){
  int startingPlayerIndex = game_->getStartingPlayerIndex();
  game_->setCurrentPlayer(startingPlayerIndex);
  // std::cerr << "A new round begins. It's player " << startingPlayerIndex + 1 << "'s turn to play." << std::endl;
}

//-------------end of setup helpers---------------
