#ifndef _DECK_
#define _DECK_

#include "Card.h"

class Deck{
public:
  Deck();
  ~Deck();
  void print();
private:
  void shuffle();
  Card* cards_[52]; // need to make this an array
};

#endif
