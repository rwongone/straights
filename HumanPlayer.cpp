#include "HumanPlayer.h"

// Constructor
HumanPlayer::HumanPlayer(): Player() {}

// Destructor
HumanPlayer::~HumanPlayer(){};

// Copy Constructor
HumanPlayer::HumanPlayer(const Player& player): Player(player){}

// Returns true since this is a human
bool HumanPlayer::isHuman() const{
  return true;
}
