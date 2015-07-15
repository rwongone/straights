#include "Player.h"

// Constructor
Player::Player(): score_(0) {

}

// Destructor
Player::~Player(){
}

// Copy Constructor
Player::Player(const Player& player){
  score_ = player.score_;
  hand_ = player.hand_;
  discardPile_ = player.discardPile_;
}

// Accessor - Return's the player's score
int Player::score() const {
  return score_;
}

// Mutator - Updates the player's score and returns how much it increased by
int Player::addScore() {
  int accumulator = 0;
  for (auto it = discardPile_.begin(); it != discardPile_.end(); ++it) {
    accumulator += (**it).getRank() + 1;
  }
  score_ += accumulator;
  return accumulator;
}

// Mutator - Gives a player a vector of cards for their hand
void Player::setHand(std::vector<Card*> hand){
  hand_ = hand;
}

// Accessor - Returns the player's hand
std::vector<Card*> Player::getHand() const{
  return hand_;
}

// Returns true if the player's hand contains the 7S
bool Player::hasStartCard() const {
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    if((*it)->isStartCard()){
      return true;
    }
  }
  return false;
}

// Mutator - Removes card from hand
void Player::playCard(Card* card){
  hand_.erase(find(hand_.begin(), hand_.end(), card));
}

// Mutator - Removes card from hand and adds to discard pile
void Player::discardCard(Card card){
  // Find the card to discard from hand
  Card* cardToDiscard;
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    if(**it == card){
      cardToDiscard = *it;
    }
  }

  // Add card to discard pile
  discardPile_.push_back(cardToDiscard);

  // Remove card from hand
  hand_.erase(find(hand_.begin(), hand_.end(), cardToDiscard));
}

// Mutator - Empties the discard pile
void Player::reset() {
  discardPile_.clear();
}

// Prints the player's hand
void Player::printHand() const {
  std::cout << "Your hand:";
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    std::cout << " " <<  **it;
  }
  std::cout << std::endl;
}

// Prints the player's legal moves
void Player::printLegalMoves(Table* table) const {
  std::cout << "Legal plays:";
  // Determine legal plays
  for (auto it = hand_.begin(); it != hand_.end(); ++it) {
    if (table->isLegalCard(*it)) {
      std::cout << " " << **it;
    }
  }
  std::cout << std::endl << ">";
}

// Prints a summary of a player's discarded cards at the end of the round
void Player::printSummary() const {
  for (auto it = discardPile_.begin(); it != discardPile_.end(); ++it) {
    std::cout << " " << **it;
  }
  std::cout << std::endl;
}

// Returns true when hand is empty
bool Player::noMoreMoves() const {
  return hand_.size() == 0;
}

int Player::getNumberOfDiscards(){
  return discardPile_.size();
}
