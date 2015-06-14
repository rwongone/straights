#include "Player.h"
#include <iostream>

Player::Player(std::vector<Card*> hand) : hand_(hand) {

}

void Player::printHand() const {
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    std::cout << **it << std::endl;
  }
}
