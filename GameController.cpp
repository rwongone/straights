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

// Player specified by index plays a card on the table - Returns true if successful
void GameController::playCard(const int index, Card card) {
  Card* cardToPlay = NULL;
  std::vector<Card*> legalMoves = game_->getLegalMoves(index);

  std::cerr << "Player " << (index+1) << " legal moves: ";
  for(auto it = legalMoves.begin(); it != legalMoves.end(); ++it){
    std::cerr << **it << " ";
    if(**it == card) {
      cardToPlay = *it;
    }
  }
  std::cerr << std::endl;

  // This is not a legal play
  if(cardToPlay == NULL){
    std::cerr << card << " is an illegal play." << std::endl;
    // throw GameControllerException("Illegal Play");
  } else {
    // Add card to table
    game_->playCardToTable(cardToPlay);
    game_->playPlayerCard(index, cardToPlay);
    nextTurn();
    endTransaction();
  }
}

// Player specified by index discards a card - Returns true if successful
void GameController::discardCard(const int index, Card card){
  // Assert that there are no legal moves available
  std::vector<Card*> legalMoves = game_->getLegalMoves(index);
  if(legalMoves.size() > 0){
    std::cerr << "Legal moves exist, cannot discard." << std::endl;
    // throw GameControllerException("Legal Moves Exist");
  } else {
    std::cout << "Player " << (index+1) << " discards " << card << "." << std::endl;

    Player* player = game_->getPlayer(index);
    player->discardCard(card);
    nextTurn();
    endTransaction();
  }
}

// Automove for a player
void GameController::playTurn(const int index) {
  Player* player = game_->getPlayer(index);
  std::vector<Card*> legalMoves = game_->getLegalMoves(index);
  std::vector<Card*> hand = player->getHand();

  if (legalMoves.size() == 0) {
    if (hand.size() == 0) {
      game_->setGameOver(true);
      return;
    }
    Card* theCard = hand.front();
    discardCard(index, *theCard);
  } else {
    Card* theCard = legalMoves.front();
    playCard(index, *theCard);
  }
  endTransaction();
}

// Player specified by index ragequits and becomes a computer
void GameController::rageQuit(const int index) {
  // convert the player[index] to a computer player
  Player* humanToConvert = game_->getPlayer(index);
  game_->setPlayer(index, new ComputerPlayer(*humanToConvert));
  delete humanToConvert;
  numComputerPlayers_++;
  endTransaction();
}

// Ends the program
void GameController::quit() const{
  game_->setQuit();
  endTransaction();
}

void GameController::nextTurn(){
  int currentPlayerIndex = game_->getCurrentPlayer();
  currentPlayerIndex += 1;
  currentPlayerIndex %= 4;
  game_->setCurrentPlayer(currentPlayerIndex);
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
  endTransaction();
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

// Prints a summary of discards and scores at the end of a round
void GameController::printSummary() const{
  for (int i=0; i<4; i++) {
    Player *thePlayer = game_->getPlayer(i);
    std::cout << "Player " << (i+1) << "'s discards:";
    thePlayer->printSummary();

    std::cout << "Player " << (i+1) << "'s score: ";
    std::cout << thePlayer->score() << " + ";
    std::cout << thePlayer->addScore() << " = ";
    std::cout << thePlayer->score() << std::endl;

    if (thePlayer->score() >= 80) {
      game_->setGameOver(true);
      game_->setQuit();
    }
  }
}

// Returns true if the program should end
bool GameController::isGameDone() const{
  return game_->isGameDone();
}

// Returns true if the round is over
bool GameController::shouldQuit() const{
  return game_->shouldQuit() || numComputerPlayers_ == 4;
}

// Returns the winner(s) of the game
std::vector<int> GameController::winners() const {
  int minScore = 1000;
  std::vector<int> minPlayers;
  for (int i=0; i<4; i++) {
    int theScore = game_->getPlayer(i)->score();
    if (theScore == minScore) {
      minPlayers.push_back(i+1);
      minScore = game_->getPlayer(i)->score();
    } else if (theScore < minScore) {
      minPlayers.clear();
      minPlayers.push_back(i+1);
      minScore = game_->getPlayer(i)->score();
    } else {
      minPlayers.clear();
    }
  }
  return minPlayers;
}

void GameController::endTransaction() const {
  game_->notify();
}

//--------------setup helpers----------------------
void GameController::setupGame(){
  resetPlayers();
  resetRound();
  dealCards();
  cleanTable();
  determineStartingPlayer();
  endTransaction();
}

void GameController::resetPlayers(){
  for(int i = 0; i< 4; i++){
    game_->resetPlayer(i);
  }
}

void GameController::resetRound(){
  game_->setGameOver(false);
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
  std::cerr << "A new round begins. It's player " << startingPlayerIndex + 1 << "'s turn to play." << std::endl;
}

//-------------end of setup helpers---------------
