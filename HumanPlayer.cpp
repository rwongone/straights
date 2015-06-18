#include "HumanPlayer.h"
#include "Table.h"
#include "Round.h"

HumanPlayer::HumanPlayer(Round* round) : Player(round) {

}

void HumanPlayer::makeMove(){
  // Print out cards on table; the HumanPlayer object (at least)
  // needs to be able to access the Table's << operator.

  // Print out hand

  // Print out valid moves
}
