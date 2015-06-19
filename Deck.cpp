#include "Deck.h"

// Constructor - Takes in a seed for shuffling
Deck::Deck(int seed = 0) : seed_(seed){
  for(int i = 0; i < Card::MAX_CARDS; i++){
    cards_[i] = new Card(i);
  }
}

// Destructor
Deck::~Deck() {
  for (int i=0; i<Card::MAX_CARDS; i++) {
    delete cards_[i];
  }
}

// Mutator - Shuffle the order of the deck's card
void Deck::shuffle(){
  static std::mt19937 rng(seed_);

  int n = Card::MAX_CARDS;

  while ( n > 1 ) {
    int k = (int) (rng() % n);
    --n;
    Card *c = cards_[n];
    cards_[n] = cards_[k];
    cards_[k] = c;
  }
}

// Accessor - Return the card at the given index
Card* Deck::getCard(const int index) const{
  assert(0 <= index && index < Card::MAX_CARDS);
  return cards_[index];
}

// Insertion Operator - Insert Deck into output stream
std::ostream &operator<<(std::ostream &sout, const Deck &deck){
  for(int i = 0; i < Card::NUM_SUITS; i++){
    for(int j = 0; j < Card::NUM_FACES; j++) {
      sout << *deck.cards_[Card::NUM_FACES*i+j];
      if (j < Card::NUM_FACES - 1) sout << " ";
    }
    sout << std::endl;
  }
  sout << ">";
  return sout;
}
