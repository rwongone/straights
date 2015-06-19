#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

#include "Player.h"

class ComputerPlayer : public Player {
public:
  // Constructor
  ComputerPlayer();
  // Destructor
  ~ComputerPlayer();
  // Copy Constructor
  ComputerPlayer(const Player&);
  // Returns false since this is a computer
  bool isHuman() const;
};

#endif
