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

class Game {
public:
  Game(int);
  ~Game();
  Player* getPlayer(int);
  Deck* getDeck();
  Table* getTable();
  void setQuit();
  void setGameOver();
  bool isGameDone();
  void setPlayer(int, Player*);
  void setStartingPlayer(int);
  void setCurrentPlayer(int);
  int getCurrentPlayer();
  void setPlayerHand(int, std::vector<Card*>);
  bool shouldQuit();
  std::vector<Card*> getLegalMoves(int);
  void createTable();
  void startGame();
private:
  Deck* deck_;
  Table* table_;
  Player* players_[4]; // Turn this into a constant
  Player* startingPlayer_;
  int currentPlayer_;
  void setupPlayers();
  bool gameOver_;
  bool shouldQuit_;
};

#endif
