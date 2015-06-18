#ifndef _TABLE_
#define _TABLE_

#include "Card.h"
#include <set>
#include <vector>

class Table{
public:
  Table();
  ~Table();
  std::set<Card*>* getCardsPlayed();
  void playCard(Card*);
  friend std::ostream& operator<<(std::ostream&, const Table&);
private:
  std::set<Card*> *cardsPlayed_;
};

#endif
