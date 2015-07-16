#ifndef _GAME_
#define _GAME_

#include "Player.h"
#include "Deck.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include "Subject.h"

class Game : public Subject {
public:
  static const int NUMBER_OF_PLAYERS = 4;
  // Constructor - Takes an int which is used as a seed to shuffle the deck
  Game(int);
  // Destructor
  virtual ~Game();
  // Accessor - Returns the player at the given index
  Player* getPlayer(int);
  // Accessor - Returns the deck
  Deck* getDeck();
  // Accessor - Returns the table
  Table* getTable();
  // Mutator - Sets the game to quit mode: (The program should shut down)
  void setGameOver(bool);
  void setRoundOver(bool);
  // Accessor - Returns whether the game should quit
  bool getGameOver() const;
  // Accessor - Returns whether the round is done
  bool getRoundOver() const;
  // Mutator - Sets the player at the given index
  void setPlayer(const int, Player*);
  // Mutator - Saves the index of the current player
  void setCurrentPlayer(const int);
  // Accessor - Gets the index of the current player
  int getCurrentPlayer() const;

  // Table Functions
  void cleanTable();
  void playCardToTable(Card*);
  std::set<Card*>* getCardsOnTable() const;

  // Player Functions
  void playPlayerCard(const int, Card*);
  void discardPlayerCard(const int, Card*);
  void resetPlayer(const int);
  int getStartingPlayerIndex();
  std::vector<Card*> getPlayerHand(int);
  std::vector<Card*> getLegalMoves(int);
  void setPlayerHand(const int, std::vector<Card*>);
  int getNumberOfDiscards(const int);
  bool isPlayerHuman(const int);
  int  getPlayerScore(const int);
  void setPlayerScore(int, int);
  int getPlayerDiscardPoints(const int);
  std::string getDiscardsAsString(const int);

  // Deck Functions
  void setSeed(int);
  void shuffleDeck();
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
