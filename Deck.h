#ifndef _DECK_
#define _DECK_

#include "Card.h"

class Deck{
public:
  Deck(int);
  ~Deck();
  friend std::ostream &operator<<(std::ostream &, const Deck &);
private:
  void shuffle(int);
  Card* cards_[Card::MAX_CARDS]; // need to make this an array
};

#endif
