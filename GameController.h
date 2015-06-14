#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

#include "Player.h"
#include "Table.h"
#include "Card.h"

class GameController{
public:
  GameController();
  ~GameController();
  void playCard(Card*);
  void discardCard(Card*);
  void rageQuit(Player*);
  void quit();
  void deck();
private:
  Player* players_;
  Table* table_;
};

#endif
