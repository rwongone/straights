#include "GameController.h"

GameController::GameController(Game* game): game_(game), numComputerPlayers_(0) {}

GameController::~GameController() {}

void GameController::setPlayer(int index, std::string playerType) {
  assert(playerType == "h" || playerType == "c");
  if (playerType == "h"){
    game_->setPlayer(index, new HumanPlayer());
  } else {
    game_->setPlayer(index, new ComputerPlayer());
    numComputerPlayers_++;
  }
}

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

void GameController::setPlayerHand(int index, std::vector<Card*> hand) {
    game_->setPlayerHand(index, hand);
}

void GameController::updateCurrentPlayer(int index){
  game_->setCurrentPlayer(index);
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

void GameController::playTurn(int index) {
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

void GameController::quit() {
  game_->setGameOver();
  game_->setQuit();
}

bool GameController::shouldQuit() {
  return game_->shouldQuit() || numComputerPlayers_ == 4;
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

bool GameController::playCard(int index, Card card) {
  std::cout << "Player " << (index+1) << " plays " << card << "." << std::endl;
  Card* cardToPlay = NULL;
  std::vector<Card*> legalMoves = game_->getLegalMoves(index);
  for(auto it = legalMoves.begin(); it != legalMoves.end(); ++it){
    if(**it == card){
      cardToPlay = *it;
    }
  }

  // This is not a legal play
  if(cardToPlay == NULL){
    return false;
  }

  // Add card to table
  Table* table = game_->getTable();
  table->playCard(cardToPlay);

  Player* player = game_->getPlayer(index);
  // Remove card from player's hand
  player->playCard(cardToPlay);
  return true;
}

void GameController::rageQuit(int index) {
  // convert the player[index] to a computer player
  Player* humanToConvert = game_->getPlayer(index);
  game_->setPlayer(index, new ComputerPlayer(*humanToConvert));
  delete humanToConvert;
  numComputerPlayers_++;
}

bool GameController::discardCard(int index, Card card){
  std::cout << "Player " << (index+1) << " discards " << card << "." << std::endl;
  // Assert that there are no legal moves available
  std::vector<Card*> legalMoves = game_->getLegalMoves(index);
  if(legalMoves.size() > 0){
    return false;
  }

  Player* player = game_->getPlayer(index);
  player->discardCard(card);
  return true;
}

void GameController::printSummary() {
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

void GameController::startGame() {
  for (int i=0; i<4; i++) {
    game_->getPlayer(i)->reset();
  }
  game_->startGame();
}

void GameController::cleanTable() {
  game_->getTable()->clean();
}
