#ifndef _DECK_
#define _DECK_

#include "Card.h"
#include <random>
#include <iostream>
#include <cassert>

class Deck {
public:
  // Constructor - Takes in a seed for shuffling
  Deck(int);
  // Destructor
  ~Deck();
  // Accessor - Return the card at the given index
  Card* getCard(const int) const;
  // Mutator - Shuffle the order of the deck's card
  void shuffle();
  // Set the RNG seed.
  void setSeed(int);
  // Insertion Operator - Insert Deck into output stream
  friend std::ostream &operator<<(std::ostream &, const Deck &);
private:
  // Array of cards in the deck
  Card* cards_[Card::MAX_CARDS];
  // Seed used for shuffling algorithm
  int seed_;
};

#endif
