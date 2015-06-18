#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

#include "Player.h"
#include "Card.h"
#include "Game.h"

class GameController{
public:
  GameController(Game*);
  ~GameController();
  void playCard(Card*);
  void discardCard(int, Card);
  void rageQuit(Player*);
  void quit();
  void deck();
  void setPlayer(int, std::string);
  void dealCards();
  void setPlayerHand(int, std::vector<Card*>);
  bool playTurn(int);
  void printHand(int) const;
  void printLegalMoves(int) const;
  bool isGameDone();
  int findStartingPlayer();
private:
  Game* game_;
};

#endif
