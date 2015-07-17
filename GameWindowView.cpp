#include "GameWindowView.h"
#include <sstream>

// Constructor
GameWindowView::GameWindowView(const std::string title, Game* game, GameController* controller) :
  // Initialization List
  topMenu(*this, game, controller),
  cardTable(*this, game, controller),
  playerList(*this, game, controller),
  handCards(*this, game, controller),
  game_(game),
  controller_(controller) {

  // Start observing the Facade
  game->subscribe(this);

  set_title(title);

  // Prompt user for player type
  for(int i = 0; i < 4; i++){
    std::ostringstream message;
    message << "What type of player is Player " << i + 1 << "?";
    PlayerPickerView picker(*this, message.str(), i);
  }

  // Fill the 4 sections of the view
  add(mainVBox);
  mainVBox.pack_start(topMenu);
  mainVBox.pack_start(cardTable);
  mainVBox.pack_start(playerList);
  mainVBox.pack_start(handCards);

  mainVBox.show();
  topMenu.show();
  cardTable.show();
  playerList.show();
  handCards.show();

  controller_->resetGame();
}

// Destructor
GameWindowView::~GameWindowView() {}

// Update the game window using model data
void GameWindowView::update() {
  // If the round is over, display a summary dialog
  if(game_->getRoundOver() && game_->getGameOver() == false){
    std::ostringstream message;
    for(int i = 0; i < 4; i++){
      message << "Player " << (i + 1) << "'s discards:";
      message << game_->getDiscardsAsString(i);
      message << "Player " << (i + 1) << "'s score: ";
      int oldScore = game_->getPlayerScore(i);
      int discardPoints = game_->getPlayerDiscardPoints(i);
      message << oldScore << " + ";
      message << discardPoints << " = ";
      message << oldScore + discardPoints << "\n";
    }

    RoundSummaryView summary(*this, message.str());
    controller_->updateScores();
  // If the game is over, display the winner dialog
  } else if(game_->getGameOver()){
    RoundSummaryView winners(*this, controller_->winners());
    controller_->resetGame();
  }
}

// Calls the controller to set whether a player is a human or computer
void GameWindowView::assignPlayerType(std::string playerType, int whichPlayer){
  controller_->setPlayer(whichPlayer, playerType);
}
