#ifndef _GAME_
#define _GAME_

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Round.h"
#include "Subject.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <string>

class Round;
class View;

class Game : public Subject {
public:
  Game(int);
  ~Game();
  Player* getPlayer(int);
  Deck* getDeck();
  Table* getTable();
  void setGameOver();
  bool isGameDone();
  void setPlayer(int, Player*);
  void setStartingPlayer(int);
  void setPlayerHand(int, std::vector<Card*>);
  void notify();
  bool playerIsHuman(int);
private:
  Deck* deck_;
  Table* table_;
  Player* players_[4]; // Turn this into a constant
  Player* currentPlayer_;
  void setupPlayers();
  void gameEnd();
  bool gameOver_;
};

#endif
