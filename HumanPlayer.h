#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include "Player.h"
#include "Table.h"

class HumanPlayer : public Player {
public:
  HumanPlayer();
  ~HumanPlayer();
  void makeMove(Table*);
private:
};

#endif
