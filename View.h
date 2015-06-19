#ifndef _VIEW_
#define _VIEW_

#include "Game.h"
#include "GameController.h"
#include "Observer.h"

class View: public Observer {
public:
  View(Game*, GameController*);
  virtual ~View();
  virtual void update();
private:
  void createPlayers();
  void playGame();
  bool playHumanTurn(int);
  void humanPrompt();
  Game* game_;
  GameController* controller_;
  int currentPlayer;
};

#endif
