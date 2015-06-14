#ifndef _GAME_
#define _GAME_

#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Table.h"
#include <set>

enum Phase { INVITE, SHUFFLE, PLAY };


class Game{
public:
  Game();
  ~Game();
private:
  void reset();
  void notify();
  Phase phase;
  Player* players_[4];
  std::set<Card*> cards_;
  Deck* deck_;
  Table* table_;
  Player* whoseTurn_;
};

#endif
