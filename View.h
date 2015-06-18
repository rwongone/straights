#ifndef _VIEW_
#define _VIEW_

#include "Game.h"
#include "GameController.h"

class View{
public:
  View(Game*, GameController*);
  ~View();
private:
  void createPlayers();
  void playGame();
  Game* game_;
  GameController* controller_;
  int currentPlayer;
};

#endif
