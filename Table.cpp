#include "Table.h"
#include "Card.h"
#include <string>

// Constructor
Table::Table() {
  cardsPlayed_ = new std::set<Card*>[SUIT_COUNT];
}

// Destructor
Table::~Table() {
  delete[] cardsPlayed_;
}

// Mutator - Add a card to cardsPlayed
void Table::playCard(Card* theCard) {
  cardsPlayed_[theCard->getSuit()].insert(theCard);
}

// Returns True if the passed in card is a legal move for the given table
bool Table::isLegalCard(Card* theCard) const {
  if (cardsPlayed_[3].size() == 0){
    // If it is the first turn, the only legal card is the 7S.
    if (theCard->getRank() == SEVEN && theCard->getSuit() == SPADE){
      return true;
    } else {
      return false;
    }
  }

  // All 7's are legal at any point besides the first turn
  if (theCard->getRank() == SEVEN) return true;

  // Determine whether the +1/-1 of the card has been played
  auto theSet = cardsPlayed_[theCard->getSuit()];
  for (auto it = theSet.begin(); it != theSet.end(); ++it) {
    if ((*it)->getRank() == theCard->getRank() + 1 || (*it)->getRank() == theCard->getRank() - 1) {
      return true;
    }
  }
  return false;
}

void Table::clean() {
  for (int i=0; i<SUIT_COUNT; i++) {
    cardsPlayed_[i].clear();
  }
}

std::set<Card*> Table::getCards() const {
  return *cardsPlayed_;
}

// Insertion Operator - Insert Table into output stream
std::ostream& operator<<(std::ostream& sout, Table& table) {
  std::string suits[SUIT_COUNT] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  std::string ranks[RANK_COUNT] = {"A", "2", "3", "4", "5", "6",
    "7", "8", "9", "10", "J", "Q", "K"};

  sout << "Cards on the table:" << std::endl; // we may need to omit space after colon
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
