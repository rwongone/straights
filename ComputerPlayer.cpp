#include "ComputerPlayer.h"

// Constructor
ComputerPlayer::ComputerPlayer(): Player() {}

// Destructor
ComputerPlayer::~ComputerPlayer(){}

// Copy Constructor
ComputerPlayer::ComputerPlayer(const Player& player): Player(player){}

// Returns false since this is a computer
bool ComputerPlayer::isHuman() const{
  return false;
}
