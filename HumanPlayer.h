#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include "Player.h"
#include "Card.h"
#include <vector>

class HumanPlayer : public Player {
public:
  HumanPlayer(std::vector<Card*>);
  ~HumanPlayer();
private:
};

#endif
