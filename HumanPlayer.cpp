#include "HumanPlayer.h"
#include "Command.h"

HumanPlayer::HumanPlayer(){

}

// Return false if game must end
void HumanPlayer::makeMove(Table* table, Deck* deck){
  // Print out cards on table; the HumanPlayer object (at least)
  // needs to be able to access the Table's << operator.
  std::cout << *table;

  // Print out hand
  printHand();

  // Print out valid moves
  printLegalMoves(table);

  bool done = false;

  while (!done) {
    Command c;
    std::cin >> c;
    if (c.type == PLAY) {
      // if play is valid, do it and set done = true

    } else if (c.type == DISCARD) {
      // if discard is valid, do it and set done = true

    } else if (c.type == DECK) {
      std::cout << *deck;
    } else if (c.type == QUIT) {
    } else if (c.type == RAGEQUIT) {
      // change human player to computer player
      done = true;
    }
  }
}
