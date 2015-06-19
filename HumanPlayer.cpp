#include "HumanPlayer.h"
#include "Command.h"

HumanPlayer::HumanPlayer(): Player() {}

bool HumanPlayer::isHuman() {
  return true;
}
