#ifndef _GAME_
#define _GAME_

#include "Player.h"
#include "Deck.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <vector>
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
  void setQuit();
  // Mutator - Sets the round to done. (52 cards have been played)
  void setGameOver();
  // Accessor - Returns whether the game should quit
  bool shouldQuit() const;
  // Accessor - Returns whether the round is done
  bool isGameDone() const;
  // Mutator - Sets the player at the given index
  void setPlayer(const int, Player*);
  // Mutator - Saves the index of the current player
  void setCurrentPlayer(const int);
  // Accessor - Gets the index of the current player
  int getCurrentPlayer() const;
  // Mutator - Gives the player a set of cards
  void setPlayerHand(const int, std::vector<Card*>);
  // Accessor - Returns a set of a player's legal moves
  std::vector<Card*> getLegalMoves(int);
  void setupGame();
  void cleanTable();
  void playCardToTable(Card*);
  int addPlayerScore(const int);
  void playPlayerCard(const int, Card*);
  void discardPlayerCard(const int, Card*);
  void resetPlayer(const int);
  std::set<Card*> getCardsOnTable() const;
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
  bool shouldQuit_;
  // Determines whether the round is over
  bool gameOver_;
};

#endif
