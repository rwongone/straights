#include "GameController.h"

GameController::GameController(Game* game): game_(game) {}

void GameController::setPlayer(int index, Player* player) {
  game_->setPlayer(index, player);
}
