#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

#include "Player.h"
#include "Round.h"

class ComputerPlayer : public Player {
public:
  ComputerPlayer(Round*);
  ~ComputerPlayer();
  void makeMove();
private:
};

#endif
