#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include "Player.h"
#include "Round.h"

class HumanPlayer : public Player {
public:
  HumanPlayer(Round*);
  ~HumanPlayer();
  void makeMove();
private:
};

#endif
