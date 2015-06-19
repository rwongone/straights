#include "Player.h"
#include <iostream>

Player::Player(): score_(0) {}
Player::~Player(){}

void Player::setHand(std::vector<Card*> hand){
  hand_ = hand;
}

std::vector<Card*> Player::getHand(){
  return hand_;
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
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    if (table->isLegalCard(*it)) {
      std::cout << " " << **it;
    }
  }
  std::cout << std::endl;
}

void Player::printSummary() const {
  for (auto it = discardPile_.begin(); it != discardPile_.end(); ++it) {
    std::cout << " " << **it;
  }
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

void Player::playCard(Card* card){
  hand_.erase(find(hand_.begin(), hand_.end(), card));
}

void Player::discardCard(Card card){
  Card* cardToDiscard;
  // Grab the corresponding card from the hand
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    if(**it == card){
      cardToDiscard = *it;
    }
  }

  // Will Crash if it can't find the card in the hand

  // Add card to discard pile
  discardPile_.push_back(cardToDiscard);
  // Remove card from hand
  hand_.erase(find(hand_.begin(), hand_.end(), cardToDiscard));

  // Print Player <x> discards <card>
}

int Player::score() const {
  return score_;
}

int Player::addScore() {
  int accumulator = 0;
  for (auto it = discardPile_.begin(); it != discardPile_.end(); ++it) {
    accumulator += (**it).getRank() + 1;
  }
  score_ += accumulator;
  return accumulator;
}
