#ifndef _VIEW_
#define _VIEW_

#include "Game.h"
#include "GameController.h"

class View {
public:
  View(Game*, GameController*);
  ~View();
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
