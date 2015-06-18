#include "View.h"
#include "Player.h"

View::View(Game* game, GameController* controller) : game_(game), controller_(controller) {
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
    done = controller_->playTurn(currentPlayer);
    currentPlayer += 1;
    currentPlayer %= 4;
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

