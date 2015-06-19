#ifndef _PLAYER_
#define _PLAYER_

#include "Card.h"
#include "Table.h"
#include "Deck.h"
#include "Subject.h"
#include <vector>
#include <iostream>
#include <algorithm>

class Player : public Subject {
public:
  Player();
  ~Player();
  int score();
  void setHand(std::vector<Card*>);
  bool hasStartCard() const;
  void printHand() const;
  void printLegalMoves(Table*) const;
  std::vector<Card*> getHand();
  virtual bool isHuman() = 0;
  void discardCard(Card);
private:
  std::vector<Card*> hand_;
  std::vector<Card*> discardPile_;
};

#endif
