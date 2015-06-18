#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include "Player.h"
#include "Table.h"

class HumanPlayer : public Player {
public:
  HumanPlayer();
  ~HumanPlayer();
  void playTurn();
  void printHand() const; // move into Human Player?
  void printLegalMoves(Table*) const; // move into Human Player?
private:
};

#endif
