#include "Player.h"
#include <iostream>

Player::Player(){}

void Player::setHand(std::vector<Card*> hand){
  hand_ = hand;
}

void Player::printHand() const {
  std::cout << "Your hand:";
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    std::cout << " " <<  **it;
  }
  std::cout << std::endl;
}

void Player::printLegalMoves(Table* table) const {
  std::cout << "Legal plays:";
  // Determine legal plays
  std::cout << std::endl;
}

bool Player::hasStartCard() const {
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    if((*it)->isStartCard()){
      return true;
    }
  }
  return false;
}
