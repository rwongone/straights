#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include "Player.h"
#include "Table.h"
#include "Card.h"
#include <vector>

class HumanPlayer : public Player {
public:
  HumanPlayer();
  ~HumanPlayer();
  void printHand() const; // move into Human Player?
  void printLegalMoves(Table*) const; // move into Human Player?
  bool isHuman();
private:
};

#endif
