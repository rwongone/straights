#include "View.h"
#include "Player.h"

View::View(Game* game, GameController* controller) : game_(game), controller_(controller) {
  initPlayers();
}
View::~View() {}

void View::initPlayers() {
  for(int i = 0; i < 4; i++){
    std::cout << "Is player " << (i + 1) << " a human(h) or a computer(c)?" << std::endl;
    std::string playerType;
    std::cin >> playerType;
    assert(playerType == "h" || playerType == "c");

    if(playerType == "h"){
      controller_->setPlayer(i, new HumanPlayer());
    } else {
      controller_->setPlayer(i, new ComputerPlayer());
    }
  }
}

void View::update() {

}
