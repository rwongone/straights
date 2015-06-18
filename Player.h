#ifndef _PLAYER_
#define _PLAYER_

#include "Card.h"
#include "Table.h"
#include "Deck.h"
#include <vector>
#include <iostream>

class Player {
public:
  Player();
  ~Player();
  int score();
  virtual void playTurn() = 0; // probably want to make this virtual
  virtual bool isHuman() = 0;
  void setHand(std::vector<Card*>);
  bool hasStartCard() const;
  void printHand() const;
  void printLegalMoves(Table*) const;
private:
  std::vector<Card*> hand_;
  std::vector<Card*> discardPile_;
};

#endif
