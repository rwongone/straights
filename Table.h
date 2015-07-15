#ifndef _TABLE_
#define _TABLE_

#include "Card.h"
#include "Subject.h"
#include <set>
#include <vector>

class Table: public Subject {
public:
  // Constructor
  Table();
  // Destructor
  ~Table();
  // Mutator - Add a card to cardsPlayed
  void playCard(Card*);
  // Returns True if the passed in card is a legal move for the given table
  bool isLegalCard(Card*) const;
  // Insertion Operator - Insert Table into output stream
  friend std::ostream& operator<<(std::ostream&, Table&);
  void clean();
  std::set<Card*> getCards() const;
private:
  // A pointer to a set of cards that have been played.
  std::set<Card*> *cardsPlayed_;
};

#endif
