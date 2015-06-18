#ifndef _ROUND_
#define _ROUND_

#include "Deck.h"
#include "Table.h"
#include "Player.h"
#include "Game.h"
#include <vector>
#include <iostream>

class Game;

class Round{
public:
  Round(Game*, int);
  ~Round();
  void reset();
  Table* getTable() const;
private:
  int startingPlayer_; // The INDEX of the starting player. +1 if printing
  Deck* deck_;
  Table* table_;
  Game* game_;
  void findStartingPlayer();
  void distributeCards();
  void gamePlay();
  void endPhase();
};

#endif
