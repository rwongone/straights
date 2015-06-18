#include "Game.h"
#include "View.h"
#include "GameController.h"
#include <stdlib.h>

int main(int argc, char* argv[]) {
  int seed = 0;

  if(argc > 1){
    seed = strtol(argv[1], NULL, 10);
  }

  Game* game = new Game(seed);
  GameController* gameController = new GameController(game);
  View* gameView = new View(game, gameController);
  return 0;
}
