#ifndef _CARD_
#define _CARD_

#include <ostream>
#include <istream>

enum Suit { CLUB, DIAMOND, HEART, SPADE, SUIT_COUNT };
enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
      EIGHT, NINE, TEN, JACK, QUEEN, KING, RANK_COUNT };

class Card{
  friend std::istream &operator>>(std::istream &, Card &);

public:
  const static int NUM_SUITS = SUIT_COUNT;
  const static int NUM_FACES = RANK_COUNT;
  const static int MAX_CARDS = NUM_SUITS * NUM_FACES;
  Card(int);
  Card(Suit, Rank);
  Suit getSuit() const;
  Rank getRank() const;
  bool isStartCard() const;
private:
  Suit suit_;
  Rank rank_;
  void init(Suit, Rank);
};

bool operator==(const Card &, const Card &);

//output/input Card in the format <rank><suit>
std::ostream &operator<<(std::ostream &, const Card &);
std::istream &operator>>(std::istream &, Card &);

#endif
