#include "HumanPlayer.h"

// Constructor
HumanPlayer::HumanPlayer(): Player() {}

// Destructor
HumanPlayer::~HumanPlayer(){};

// Returns true since this is a human
bool HumanPlayer::isHuman() const{
  return true;
}
