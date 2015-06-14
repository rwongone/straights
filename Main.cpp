#include "Game.h"
#include "View.h"
#include "GameController.h"

int main(int argc, char* argv[]) {
  Game* game = new Game();
  GameController* gameController = new GameController();
  View* gameView = new View(game, gameController);
  return 0;
}
