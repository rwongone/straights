#ifndef _GAME_
#define _GAME_

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Round.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <string>

class Round;

class Game{
public:
  Game(int);
  ~Game();
  Player* getPlayer(int);
  void setGameOver();
private:
  void notify();
  Round* round_;
  Player* players_[4]; // Turn this into a constant
  void setupPlayers();
  void gameEnd();
  bool gameOver_;
};

#endif
