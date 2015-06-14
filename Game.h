#ifndef _GAME_
#define _GAME_

#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Table.h"
#include <vector>

enum Phase { INVITE, SHUFFLE, PLAY };


class Game{
public:
  Game(int);
  ~Game();
private:
  void reset();
  void notify();
  Phase phase;
  Player* players_[4];
  std::vector<Card*> cards_;
  Deck* deck_;
  Table* table_;
  Player* whoseTurn_;
};

#endif
