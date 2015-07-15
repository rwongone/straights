#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include "Game.h"
#include "GameController.h"

class GameObserver {
private:
  Game* game_;
  GameController* controller_;
};

#endif
