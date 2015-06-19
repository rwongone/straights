#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

#include "Player.h"
#include "Card.h"
#include "Game.h"

class GameController{
public:
  GameController(Game*);
  ~GameController();
  bool playCard(int, Card);
  bool discardCard(int, Card);
  void rageQuit(int);
  void quit();
  void deck();
  void setPlayer(int, std::string);
  void dealCards();
  void setPlayerHand(int, std::vector<Card*>);
  void updateCurrentPlayer(int);
  void playTurn(int);
  void printHand(int) const;
  void printLegalMoves(int) const;
  bool isGameDone();
  bool shouldQuit();
  int findStartingPlayer();
  void printSummary();
  void cleanUp();
  int winningPlayer() const;
  void startGame();
  void cleanTable();
private:
  Game* game_;
  int numComputerPlayers_;
};

#endif
