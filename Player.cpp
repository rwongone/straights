#include "Player.h"
#include <iostream>
#include "Round.h"

Player::Player(Round* round): round_(round) {}

void Player::setHand(std::vector<Card*> hand){
  hand_ = hand;
}

void Player::printHand() const {
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    std::cout << **it << std::endl;
  }
}

bool Player::hasStartCard() const {
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    if((*it)->isStartCard()){
      return true;
    }
  }
  return false;
}
