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
  virtual void playTurn() = 0; // probably want to make this virtual
  void setHand(std::vector<Card*>);
  bool hasStartCard() const;
  void printHand() const;
  void printLegalMoves(Table*) const;
  std::vector<Card*> getHand();
  void discardCard(Card);
private:
  std::vector<Card*> hand_;
  std::vector<Card*> discardPile_;
};

#endif
