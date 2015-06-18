#include "HumanPlayer.h"
#include "Command.h"

HumanPlayer::HumanPlayer(): Player() {}

void HumanPlayer::playTurn() {
  notify();
}
