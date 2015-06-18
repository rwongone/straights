#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(){

}

void HumanPlayer::makeMove(Table* table){
  // Print out cards on table; the HumanPlayer object (at least)
  // needs to be able to access the Table's << operator.
  std::cout << *table;

  // Print out hand
  printHand();

  // Print out valid moves
  printLegalMoves(table);
}
