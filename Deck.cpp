#include "Deck.h"
#include <random>
#include "Card.h"
#include <iostream>
#include <cassert>

Deck::Deck(int seed = 0){
  for(int i = 0; i < Card::MAX_CARDS; i++){
    cards_[i] = new Card(i);
  }
  shuffle(seed);
}

void Deck::shuffle(int seed){
  static std::mt19937 rng(seed);

  int n = Card::MAX_CARDS;

  while ( n > 1 ) {
    int k = (int) (rng() % n);
    --n;
    Card *c = cards_[n];
    cards_[n] = cards_[k];
    cards_[k] = c;
  }
}

Card* Deck::getCard(int index){
  assert(0 <= index && index < Card::MAX_CARDS);
  return cards_[index];
}

std::ostream &operator<<(std::ostream &sout, const Deck &deck){
  for(int i = 0; i < Card::NUM_SUITS; i++){
    for(int j = 0; j < Card::NUM_FACES; j++) {
      sout << *deck.cards_[Card::NUM_FACES*i+j] << " ";
    }
    sout << std::endl;
  }
  return sout;
}
