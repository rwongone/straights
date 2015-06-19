#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(): Player() {}

ComputerPlayer::ComputerPlayer(const Player& player): Player(player){}

bool ComputerPlayer::isHuman() {
  return false;
}
