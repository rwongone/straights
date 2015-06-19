#ifndef _PLAYER_
#define _PLAYER_

#include "Card.h"
#include "Table.h"
#include "Deck.h"
#include <vector>
#include <iostream>
#include <algorithm>

class Player {
public:
  // Constructor
  Player();
  // Destructor
  ~Player();
  // Copy Constructor
  Player(const Player&);
  // Accessor - Return's the player's score
  int score() const;
  int addScore();
  void setHand(std::vector<Card*>);
  bool hasStartCard() const;
  void printHand() const;
  void printLegalMoves(Table*) const;
  void printSummary() const;
  std::vector<Card*> getHand();
  virtual bool isHuman() = 0;
  void discardCard(Card);
  void playCard(Card*);
  void reset();
private:
  std::vector<Card*> hand_;
  std::vector<Card*> discardPile_;
  int score_;
};

#endif
