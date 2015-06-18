#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(){

}

void HumanPlayer::makeMove(Table* table){
  // Print out cards on table; the HumanPlayer object (at least)
  // needs to be able to access the Table's << operator.
  std::cout << *table << std::endl;

  // Print out hand

  // Print out valid moves
}
