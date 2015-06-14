#ifndef _TABLE_
#define _TABLE_

#include "Card.h"
#include <set>

class Table{
public:
  Table();
  ~Table();
  std::set<Card*> getCardsPlayed();
private:
  std::set<Card*> cardsPlayed_;
};

#endif
