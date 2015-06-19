#include "View.h"

// Constructor
View::View(Game* game, GameController* controller) : game_(game), controller_(controller) {
  createPlayers();

  while (!game_->shouldQuit()) {
    controller_->startGame();
    controller_->dealCards();
    controller_->cleanTable();
    std::cout << "A new round begins. It's player " << (controller_->findStartingPlayerIndex()+1) << "'s turn to play." << std::endl;
    playGame();
  }

  if (game_->isGameDone()) {
    std::vector<int> winners = controller_->winners();
    for (auto it = winners.begin(); it != winners.end(); ++it) {
      std::cout << "Player " << *it << " wins!" << std::endl;
    }
  }
}

// Destructor
View::~View() {}

// Determine the type of each player and adds to the game
void View::createPlayers() {
  for(int i = 0; i < 4; i++){
    std::cout << "Is player " << (i + 1) << " a human(h) or a computer(c)?" << std::endl << ">";
    std::string playerType;
    std::cin >> playerType;
    assert(playerType == "h" || playerType == "c");
    controller_->setPlayer(i, playerType);
  }
}

// Game Phase
void View::playGame() {
  currentPlayerIndex_ = controller_->findStartingPlayerIndex();

  while (!game_->isGameDone() && !game_->shouldQuit()) {
    controller_->updateCurrentPlayer(currentPlayerIndex_);
    if (game_->getPlayer(currentPlayerIndex_)->isHuman()) {
      humanPrompt();
    } else {
      controller_->playTurn(currentPlayerIndex_);
    }
    currentPlayerIndex_ += 1;
    currentPlayerIndex_ %= 4;
  }

  if (!game_->shouldQuit()) {
    controller_->printSummary();
  }
}

// Prompt human for command
void View::humanPrompt() {
  int currentIndex = game_->getCurrentPlayer();
  Player* thePlayer = game_->getPlayer(currentIndex);
  if (thePlayer->noMoreMoves()) {
    game_->setGameOver();
    return;
  }

  Table* theTable = game_->getTable();
  std::cout << *theTable;

  // Print out hand
  controller_->printHand(currentIndex);

  // Print out valid moves
  controller_->printLegalMoves(currentIndex);

  bool done = false;

  while (!done) {
    Command c;
    std::cin >> c;
    if (c.type == PLAY) {
      try {
        controller_->playCard(currentIndex, c.card);
        done = true;
      } catch (GameController::GameControllerException ex){
        if(ex.code() == "Illegal Play"){
          std::cout << "This is not a legal play." << std::endl;
        }
      }
    } else if (c.type == DISCARD) {
      try {
        controller_->discardCard(currentIndex, c.card);
        done = true;
      } catch (GameController::GameControllerException ex){
        if(ex.code() == "Legal Moves Exist"){
          std::cout << "You have a legal play. You may not discard." << std::endl;
        }
      }
    } else if (c.type == DECK) {
      std::cout << *game_->getDeck();
    } else if (c.type == QUIT) {
      controller_->quit();
      done = true;
    } else if (c.type == RAGEQUIT) {
      // change human player to computer player
      std::cout << "Player " << (currentIndex+1) << " ragequits. A computer will now take over." << std::endl;
      controller_->rageQuit(currentIndex);
      controller_->playTurn(currentIndex);
      done = true;
    }
  }
}

