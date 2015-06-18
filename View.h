#ifndef _VIEW_
#define _VIEW_

#include "Game.h"
#include "GameController.h"

class View{
public:
  View(Game*, GameController*);
  ~View();
  void update();
private:
  void initPlayers();
  Game* game_;
  GameController* controller_;
};

#endif
