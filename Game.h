#ifndef _GAME_
#define _GAME_

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Round.h"
#include "Observer.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <string>

class Round;

class Game {
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
  void setCurrentPlayer(int);
  int getCurrentPlayer();
  void setPlayerHand(int, std::vector<Card*>);
  void subscribe(Observer*);
  bool playerIsHuman(int);
  std::vector<Card*> getLegalMoves(int);
private:
  Deck* deck_;
  Table* table_;
  Player* players_[4]; // Turn this into a constant
  Player* startingPlayer_;
  int currentPlayer_;
  void setupPlayers();
  void gameEnd();
  bool gameOver_;
};

#endif
