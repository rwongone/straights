#ifndef _GAMECONTROLLER_
#define _GAMECONTROLLER_

#include "Player.h"
#include "Card.h"
#include "Game.h"
#include <vector>
#include <string>
#include <sstream>

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
  void togglePlayerType(const int);
  // Creates a new player based on type
  void setPlayer(const int, const std::string);
  // Returns the winner(s) of the game
  std::string winners() const;
  // Reset the game with default seed 0.
  void resetGame();
  // Reset the game with specified seed.
  void resetGame(int);
  // Update player scores.
  void updateScores();

  // ---------------Debugging Functions ------------
  // // Prints the player specified by index's hand
  // void printHand(const int) const;
  // // Prints the legal moves for a player specified by index
  // void printLegalMoves(const int) const;
  // // Prints a summary of discards and scores at the end of a round
  // void printSummary() const;
private:
  // The game facade.
  Game* game_;
  // Counter that denotes how many computer players there are
  int numComputerPlayers_;
  // Play the next turn.
  void nextTurn();
  // End a sequence of modifications.
  void endTransaction() const;
  // Reset player state.
  void resetPlayers();
  // Reset round state.
  void resetRound();
  // Shuffle deck and deal cards.
  void dealCards();
  // Clear the table of cards.
  void cleanTable();
  // Set the starting player.
  void determineStartingPlayer();
  // Play the game until current player is human.
  void playUntilHuman();
  // Flag roundOver.
  void roundOver();
};

#endif
