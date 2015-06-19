#include "HumanPlayer.h"
#include "Command.h"

HumanPlayer::HumanPlayer(): Player() {}

void HumanPlayer::playTurn(){}

bool HumanPlayer::isHuman() {
  return true;
}
