#include "Player.h"
#include <iostream>

Player::Player() {

}

void Player::setHand(std::vector<Card*> hand){
  hand_ = hand;
}

void Player::makeMove(){ // probably should be virtual

}

void Player::printHand() const {
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    std::cout << **it << std::endl;
  }
}

bool Player::hasStartCard(){
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    if((*it)->isStartCard()){
      return true;
    }
  }
  return false;
}
