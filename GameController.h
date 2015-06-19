#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

#include "Player.h"
#include "Card.h"
#include "Game.h"
#include <vector>
#include <string>

class GameController{
public:
  // Constructor
  GameController(Game*);
  // Destructor
  ~GameController();
  // GameController Exception
  class GameControllerException{
    public:
      // GameController Exception Constructor
      GameControllerException(std::string);
      // Accessor - Return GameController Exception
      std::string code();
    private:
      // Exception Code
      std::string code_;
  };
  // Player specified by index plays a card on the table - Throws exception if illegal play
  void playCard(const int, Card);
  // Player specified by index discards a card - Throws exception if there is a legal play
  void discardCard(const int, Card);
  // Automove for a player
  void playTurn(const int);
  // Player specified by index ragequits and becomes a computer
  void rageQuit(const int);
  // Ends the game
  void quit() const;
  // Creates a new player based on type
  void setPlayer(const int, const std::string);
  // Shuffles the deck and gives each player a hand
  void dealCards();
  // Gives player a hand
  void setPlayerHand(const int, std::vector<Card*>);
  // Tells the model whose turn it is
  void updateCurrentPlayer(int);
  // Determines the index of the starting player
  int findStartingPlayerIndex();
  // Prints the player specified by index's hand
  void printHand(const int) const;
  // Prints the legal moves for a player specified by index
  void printLegalMoves(const int) const;
  // Prints a summary of discards and scores at the end of a round
  void printSummary() const;
  // Returns true if the round is over
  bool isGameDone() const;
  // Returns true if the program should end
  bool shouldQuit() const;
  // Returns the winner(s) of the game
  std::vector<int> winners() const;
  // Resets players and starts the game
  void startGame();
  // Clears the played cards on the table
  void cleanTable();
private:
  // The game
  Game* game_;
  // Counter that denotes how many computer players there are
  int numComputerPlayers_;
};

#endif
