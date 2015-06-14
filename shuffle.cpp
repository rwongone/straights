/* To ensure that the your cards are ordered the same way as
the given program, use this shuffling algorithm.

CARD_COUNT is the constant 52
cards_ is an array of pointers to cards
*/

#include <random>

int seed = 0;
const int CARD_COUNT = 52;

void shuffle(){
    static std::mt19937 rng(seed);

  int n = CARD_COUNT;

  while ( n > 1 ) {
    int k = (int) (rng() % n);
    --n;
    Card *c = cards_[n];
    cards_[n] = cards_[k];
    cards_[k] = c;
  }
}
