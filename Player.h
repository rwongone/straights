#ifndef _PLAYER_
#define _PLAYER_

#include "Card.h"
#include "Table.h"
#include "Round.h"
#include <vector>

class Player{
public:
  Player(Round*);
  ~Player();
  int score();
  virtual void makeMove() = 0; // probably want to make this virtual
  void printHand() const;
  void setHand(std::vector<Card*>);
  bool hasStartCard() const;
private:
  std::vector<Card*> hand_;
  std::vector<Card*> discardPile_;
  Round* round_;
};

#endif
