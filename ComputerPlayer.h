#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

#include "Player.h"

class ComputerPlayer : public Player {
public:
  ComputerPlayer();
  ~ComputerPlayer();
  bool isHuman();
  void makeMove();
private:
};

#endif
