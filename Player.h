#ifndef _PLAYER_
#define _PLAYER_

#include "Card.h"
#include <vector>

class Player{
public:
  Player();
  ~Player();
  int score();
  void makeMove(); // probably want to make this virtual
  void printHand() const;
  void setHand(std::vector<Card*>);
  bool hasStartCard();
private:
  std::vector<Card*> hand_;
  std::vector<Card*> discardPile_;
};

#endif
