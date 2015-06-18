#include "Table.h"
#include "Card.h"
#include <string>

Table::Table() {
  cardsPlayed_ = new std::set<Card*>[SUIT_COUNT];
}

Table::~Table() {
  for (int i = 0; i < SUIT_COUNT; i++) {
    for (auto it = cardsPlayed_[i].begin(); it != cardsPlayed_[i].end(); ++it) {
      delete *it;
    }
  }
}

void Table::playCard(Card* theCard) {
  cardsPlayed_[theCard->getSuit()].insert(theCard);
}

bool Table::isLegalCard(Card* theCard) const {
  if (theCard->getRank() == SEVEN) return true;

  auto theSet = cardsPlayed_[theCard->getSuit()];
  for (auto it = theSet.begin(); it != theSet.end(); ++it) {
    if ((*it)->getRank() == theCard->getRank() + 1 || (*it)->getRank() == theCard->getRank() - 1) {
      return true;
    }
  }
  return false;
}

std::ostream& operator<<(std::ostream& sout, Table& table) {
  std::string suits[SUIT_COUNT] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  std::string ranks[RANK_COUNT] = {"A", "2", "3", "4", "5", "6",
    "7", "8", "9", "10", "J", "Q", "K"};

  sout << "Cards on the table: " << std::endl; // we may need to omit space after colon
  for (int i=0; i<SUIT_COUNT; i++) {
    std::set<Card*> suitSet = table.cardsPlayed_[i];
    sout << suits[i] << ":";
    for (auto it=suitSet.begin(); it != suitSet.end(); ++it) {
      sout << " " << ranks[(*it)->getRank()]; // may have to omit space on last entry
    }
    sout << std::endl;
  }

  return sout;
}
