#ifndef _GAME_
#define _GAME_

#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Table.h"

enum Phase { INVITE, SHUFFLE, PLAY };


class Game{
public:
  Game();
  ~Game();
private:
  void reset();
  void notify();
  Phase phase;
};

#endif
