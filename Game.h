#ifndef _GAME_
#define _GAME_

#include "Player.h"
#include "Deck.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Subject.h"
#include <vector>
#include <string>
#include <sstream>

// Facade Class
class Game : public Subject {
public:
  static const int NUMBER_OF_PLAYERS = 4;
  // Constructor - Takes an int which is used as a seed to shuffle the deck
  Game(int);
  // Destructor
  virtual ~Game();


  // -----Game Related Functions-----

  // Mutator - Set the game state
  void setGameOver(bool);
  // Accessor - Returns the game state
  bool getGameOver() const;
  // Mutator - Set the round state
  void setRoundOver(bool);
  // Accessor - Returns the round state
  bool getRoundOver() const;
  // Mutator - Sets the player at the given index
  void setPlayer(const int, Player*);
  // Mutator - Saves the index of the current player
  void setCurrentPlayer(const int);
  // Accessor - Returns the index of the current player
  int getCurrentPlayer() const;


  // -----Table Related Functions-----

  // Accessor - Returns the table
  Table* getTable();
  // Mutator - Clears the played cards
  void cleanTable();
  // Mutator - Adds card to table
  void playCardToTable(Card*);
  // Accessor - Return the cards that have been played
  std::set<Card*>* getCardsOnTable() const;


  // -----Player Related Functions-----

  // Accessor - Returns the player at the given index
  Player* getPlayer(int);
  // Mutator - Play a card
  void playPlayerCard(const int, Card*);
  // Mutator - Discard a card
  void discardPlayerCard(const int, Card*);
  // Mutator - Empty Discard pile
  void resetPlayer(const int);
  // Accessor - Returns the index of the player with the seven of spades
  int getStartingPlayerIndex();
  // Accessor - Returns the player's hand
  std::vector<Card*> getPlayerHand(int);
  // Accessor - Returns a set of a player's legal moves
  std::vector<Card*> getLegalMoves(int);
  // Mutator - Gives the player a set of cards
  void setPlayerHand(const int, std::vector<Card*>);
  // Accessor - Return the number of discarded cards for a player
  int getNumberOfDiscards(const int);
  // Mutator - Set the player score
  void setPlayerScore(int, int);
  // Accessor - Return the player score
  int  getPlayerScore(const int);
  // Accessor - Get the point total of discarded cards
  int getPlayerDiscardPoints(const int);
  // Accessor - Return the discarded cards encoded as a string
  std::string getDiscardsAsString(const int);
  // Accessor - Return true if player is human controlled
  bool isPlayerHuman(const int);


  // -----Deck Related Functions-----

  // Mutator - Set the seed for the shuffle algorithm
  void setSeed(int);
  // Mutator - Shuffle the deck
  void shuffleDeck();
  // Accessor - Returns card from deck
  Card* getCardFromDeck(int);
private:
  // Deck
  Deck* deck_;
  // Table
  Table* table_;
  // Array of 4 players
  Player* players_[NUMBER_OF_PLAYERS];
  // The player whose turn it is right now
  int currentPlayer_;
  // Determines whether the program should quit
  bool gameOver_;
  // Determines whether the round is over
  bool roundOver_;
};

#endif
