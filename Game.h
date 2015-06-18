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
  Deck* getDeck();
  void setGameOver();
  void setPlayer(int, Player*);
  void setCurrentPlayer(int);
  void setPlayerHand(int, std::vector<Card*>);
private:
  void notify();
  Deck* deck_;
  Table* table_;
  Player* players_[4]; // Turn this into a constant
  Player* currentPlayer_;
  void setupPlayers();
  void gameEnd();
  bool gameOver_;
};

#endif
