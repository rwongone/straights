#ifndef _PLAYER_
#define _PLAYER_

#include "Card.h"
#include "Table.h"
#include "Deck.h"
#include <vector>
#include <iostream>

class Player{
public:
  Player();
  ~Player();
  int score();
  virtual bool makeMove(Table*, Deck*) = 0; // probably want to make this virtual
  void printHand() const; // move into Human Player?
  void printLegalMoves(Table*) const; // move into Human Player?
  void setHand(std::vector<Card*>);
  bool hasStartCard() const;
private:
  std::vector<Card*> hand_;
  std::vector<Card*> discardPile_;
};

#endif
