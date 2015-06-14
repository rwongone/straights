#ifndef _TABLE_
#define _TABLE_

#include "Card.h"
#include <vector>

class Table{
public:
  Table();
  ~Table();
  std::vector<Card*> getCardsPlayed();
private:
  std::vector<Card*> cardsPlayed_;
};

#endif
