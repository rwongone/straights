#include "View.h"
#include "Player.h"
#include "Command.h"

View::View(Game* game, GameController* controller) : game_(game), controller_(controller) {
  game->subscribe(this);
  createPlayers();
  controller_->dealCards();
  playGame();
}

View::~View() {

}

void View::playGame() {
  currentPlayer = controller_->findStartingPlayer();
  bool done = false;

  while (!done) {
    // if (game_->getPlayer(currentPlayer)->isHuman()) {
    //   done = playHumanTurn(currentPlayer);
    // } else {
    //   done = controller_->playTurn(currentPlayer);
    // }

    done = controller_->playTurn(currentPlayer);
    currentPlayer += 1;
    currentPlayer %= 4;
  }
}

void View::humanPrompt(int index) {
  Table* theTable = game_->getTable();
  std::cout << *theTable;

  // Print out hand
  controller_->printHand(index);

  // Print out valid moves
  controller_->printLegalMoves(index);

  bool done = false;

  while (!done) {
    Command c;
    std::cin >> c;
    if (c.type == PLAY) {
      // if play is valid, do it and set done = true

    } else if (c.type == DISCARD) {
      // if discard is valid, do it and set done = true

    } else if (c.type == DECK) {
      std::cout << *game_->getDeck();
    } else if (c.type == QUIT) {
      controller_->quit();
      done = true;
    } else if (c.type == RAGEQUIT) {
      // change human player to computer player
      done = true;
    }
  }
}

void View::createPlayers() {
  for(int i = 0; i < 4; i++){
    std::cout << "Is player " << (i + 1) << " a human(h) or a computer(c)?" << std::endl;
    std::string playerType;
    std::cin >> playerType;
    assert(playerType == "h" || playerType == "c");
    controller_->setPlayer(i, playerType);
  }
}

