#include "PlayerListView.h"
#include <string>
#include <sstream>

namespace {
  // Helper to combine int and string
  std::string stringify(int i, std::string str){
    std::ostringstream returnString;
    returnString << i << " " << str;
    return returnString.str();
  }
};

// Constructor
PlayerListView::PlayerListView(Gtk::Window &parent, Game* game, GameController* controller) :
  // Initialization List
  parent_(parent),
  game_(game),
  controller_(controller) {

  // Start observing the Facade
  game->subscribe(this);

  for(int i = 0; i < 4; i++){
    // Add the "Player i" title to the frame
    std::ostringstream frameTitle;
    frameTitle << "Player " << i + 1;
    frames_[i].set_label(frameTitle.str());

    // Add the frame to the HBox
    pack_start(frames_[i]);

    // Add a VBox within each frame to contain: ragequit, points, discard
    frames_[i].add(playerStats_[i]);

    // Add the toggle player type buttons
    togglePlayerType_[i].set_label("Toggle AI");
    togglePlayerType_[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &PlayerListView::togglePlayerTypeButtonClicked), i));

    playerStats_[i].pack_start(togglePlayerType_[i]);

    // Add the points
    points_[i].set_text(stringify(0, "points"));
    playerStats_[i].pack_start(points_[i]);

    // Add the number of discards
    discards_[i].set_text(stringify(0, "discards"));
    playerStats_[i].pack_start(discards_[i]);

    // Show everything
    frames_[i].show();
    playerStats_[i].show();
    togglePlayerType_[i].show();
    points_[i].show();
    discards_[i].show();
  }
}

// Destructor
PlayerListView::~PlayerListView() {}

// Toggle Player Type button handler
void PlayerListView::togglePlayerTypeButtonClicked(const int i) {
  controller_->togglePlayerType(i);
}

// Update view with player information from model
void PlayerListView::update(){
  for(int i = 0; i < 4; i ++){

    // Player Name (type)
    std::ostringstream playerName;
    playerName << "Player " << i + 1 << " - ";
    if(game_->isPlayerHuman(i)){
      playerName << "Human";
    } else {
      playerName << "Computer";
    }
    if(game_->getCurrentPlayer() == i){
      playerName << " (*)";
    }
    frames_[i].set_label(playerName.str());

    // Number of discards
    discards_[i].set_text(stringify(game_->getNumberOfDiscards(i), "discards"));

    // Points
    points_[i].set_text(stringify(game_->getPlayerScore(i), "points"));
  }
}
