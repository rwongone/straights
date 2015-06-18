#ifndef _DECK_
#define _DECK_

#include "Card.h"

class Deck{
public:
  Deck(int);
  ~Deck();
  friend std::ostream &operator<<(std::ostream &, const Deck &);
  Card* getCard(int);
private:
  void shuffle();
  Card* cards_[Card::MAX_CARDS]; // need to make this an array
  int seed_;
};

#endif
