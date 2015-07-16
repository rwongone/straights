#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include "Player.h"

class HumanPlayer : public Player {
public:
  // Constructor
  HumanPlayer();
  // Destructor
  ~HumanPlayer();
  // Copy Constructor
  HumanPlayer(const Player&);
  // Returns true since this is a human
  bool isHuman() const;
};

#endif
