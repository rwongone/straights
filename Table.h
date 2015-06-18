#ifndef _TABLE_
#define _TABLE_

#include "Card.h"
#include <set>
#include <vector>

class Table{
public:
  Table();
  ~Table();
  void playCard(Card*);
  friend std::ostream& operator<<(std::ostream&, Table&);
  bool isLegalCard(Card*) const;
private:
  std::set<Card*> *cardsPlayed_;
};

#endif
