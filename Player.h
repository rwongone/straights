#ifndef _PLAYER_
#define _PLAYER_

#include "Card.h"
#include <set>

class Player{
public:
  Player();
  ~Player();
  int score();
  void makeMove();
private:
  std::set<Card*> hand_;
  std::set<Card*> discardPile_;
};

#endif
