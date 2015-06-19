#ifndef _VIEW_
#define _VIEW_

#include "Game.h"
#include "GameController.h"
#include "Player.h"
#include "Command.h"

class View {
public:
  // Constructor
  View(Game*, GameController*);
  // Destructor
  virtual ~View();
private:
  // Determine the type of each player and adds to the game
  void createPlayers();
  // Game Phase
  void playGame();
  // Prompt human for command
  void humanPrompt();
  // The game
  Game* game_;
  // The controller
  GameController* controller_;
  // The index of the current player
  int currentPlayerIndex_;
};

#endif
