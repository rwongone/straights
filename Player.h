#ifndef _PLAYER_
#define _PLAYER_

#include "Card.h"
#include <vector>

class Player{
public:
  Player(std::vector<Card*>);
  ~Player();
  int score();
  void makeMove();
  void printHand() const;
private:
  std::vector<Card*> hand_;
  std::vector<Card*> discardPile_;
};

#endif
