#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

#include "Player.h"
#include "Card.h"
#include <vector>

class ComputerPlayer : public Player {
public:
  ComputerPlayer();
  ~ComputerPlayer();
  bool isHuman();
private:
};

#endif
