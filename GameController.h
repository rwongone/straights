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
  void discardCard(Card*);
  void rageQuit(Player*);
  void quit();
  void deck();
  void setPlayer(int, Player*);
private:
  Game* game_;
};

#endif
