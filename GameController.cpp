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
  for(auto it = legalMoves.begin(); it != legalMoves.end(); ++it){
    if(**it == card){
      cardToPlay = *it;
    }
  }

  // This is not a legal play
  if(cardToPlay == NULL){
    throw GameControllerException("Illegal Play");
  }

  std::cout << "Player " << (index+1) << " plays " << card << "." << std::endl;

  // Add card to table
  Table* table = game_->getTable();
  table->playCard(cardToPlay);

  Player* player = game_->getPlayer(index);
  // Remove card from player's hand
  player->playCard(cardToPlay);
}

// Player specified by index discards a card - Returns true if successful
void GameController::discardCard(const int index, Card card){
  // Assert that there are no legal moves available
  std::vector<Card*> legalMoves = game_->getLegalMoves(index);
  if(legalMoves.size() > 0){
    throw GameControllerException("Legal Moves Exist");
  }

  std::cout << "Player " << (index+1) << " discards " << card << "." << std::endl;

  Player* player = game_->getPlayer(index);
  player->discardCard(card);
}

// Automove for a player
void GameController::playTurn(const int index) {
  Player* player = game_->getPlayer(index);
  std::vector<Card*> legalMoves = game_->getLegalMoves(index);
  std::vector<Card*> hand = player->getHand();

  if (legalMoves.size() == 0) {
    if (hand.size() == 0) {
      game_->setGameOver();
      return;
    }
    Card* theCard = hand.front();
    discardCard(index, *theCard);
  } else {
    Card* theCard = legalMoves.front();
    playCard(index, *theCard);
  }
}

// Player specified by index ragequits and becomes a computer
void GameController::rageQuit(const int index) {
  // convert the player[index] to a computer player
  Player* humanToConvert = game_->getPlayer(index);
  game_->setPlayer(index, new ComputerPlayer(*humanToConvert));
  delete humanToConvert;
  numComputerPlayers_++;
}

// Ends the program
void GameController::quit() const{
  game_->setQuit();
}

// Creates a new player based on type
void GameController::setPlayer(const int index, const std::string playerType) {
  assert(playerType == "h" || playerType == "c");
  if (playerType == "h"){
    game_->setPlayer(index, new HumanPlayer());
  } else {
    game_->setPlayer(index, new ComputerPlayer());
    numComputerPlayers_++;
  }
}

// Shuffles the deck and gives each player a hand
void GameController::dealCards() {;
  Deck* theDeck = game_->getDeck();
  theDeck->shuffle();
  for (int i=0; i<4; i++){ // Use constants
    std::vector<Card*> playerHand;
    for(int j = 0; j < 13; j++){ // Use constants
      playerHand.push_back(theDeck->getCard(13*i+j)); // Use constants
    }
    game_->setPlayerHand(i, playerHand);
  }
}

// Gives player a hand
void GameController::setPlayerHand(const int index, std::vector<Card*> hand) {
    game_->setPlayerHand(index, hand);
}

// Tells the model whose turn it is
void GameController::updateCurrentPlayer(int index){
  game_->setCurrentPlayer(index);
}

// Determines the index of the starting player
// Pre: The 7S card must be in one player's hand.
int GameController::findStartingPlayerIndex() {
  for(int i = 0; i < 4; i++){
    if(game_->getPlayer(i)->hasStartCard()){
      game_->setStartingPlayer(i);
      return i;
    }
  }
  assert(false);
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
      game_->setGameOver();
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

// Resets players and starts the game
void GameController::startGame() {
  for (int i=0; i<4; i++) {
    game_->getPlayer(i)->reset();
  }
  game_->startGame();
}

// Clears the played cards on the table
void GameController::cleanTable() {
  game_->getTable()->clean();
}
