#ifndef _PLAYER_
#define _PLAYER_

#include "Card.h"
#include "Table.h"
#include "Subject.h"
#include <vector>
#include <iostream>
#include <algorithm>

class Player: public Subject {
public:
  // Constructor
  Player();
  // Destructor
  virtual ~Player();
  // Copy Constructor
  Player(const Player&);
  // Accessor - Return's the player's score
  int score() const;
  int getDiscardPoints();
  void setScore(int);
  // Mutator - Gives a player a vector of cards for their hand
  void setHand(std::vector<Card*>);
  // Accessor - Returns the player's hand
  std::vector<Card*> getHand() const;
  // Returns true if the player's hand contains the 7S
  bool hasStartCard() const;
  // Returns true if the player is a human
  virtual bool isHuman() const = 0;
  // Mutator - Removes card from hand
  void playCard(Card*);
  // Mutator - Removes card from hand and adds to discard pile
  void discardCard(Card);
  // Mutator - Empties the discard pile
  void reset();
  // Prints the player's hand
  void printHand() const;
  // Prints the player's legal moves
  void printLegalMoves(Table*) const;
  // Prints a summary of a player's discarded cards at the end of the round
  void printSummary() const;
  // Returns true when hand is empty
  bool noMoreMoves() const;
  std::vector<Card*> getDiscards();
private:
  // A player's hand of cards
  std::vector<Card*> hand_;
  // A player's discard pile of cards
  std::vector<Card*> discardPile_;
  // A player's score for the game
  int score_;
};

#endif
