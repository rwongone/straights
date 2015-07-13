#include "PlayerListView.h"
#include <string>
#include <sstream>

namespace {
  std::string stringify(int i, std::string str){
    std::ostringstream returnString;
    returnString << i << " " << str;
    return returnString.str();
  }
};

PlayerListView::PlayerListView(Gtk::Window &parent): parent_(parent) {
  for(int i = 0; i < 4; i++){
    // Add the "Player i" title to the frame
    std::ostringstream frameTitle;
    frameTitle << "Player " << i;
    frames_[i].set_label(frameTitle.str());

    // Add the frame to the HBox
    pack_start(frames_[i]);

    // Add a VBox within each frame to contain: ragequit, points, discard
    frames_[i].add(playerStats_[i]);

    // Add the ragequit button
    rageQuit_[i].set_label("Rage!");
    rageQuit_[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &PlayerListView::rageQuitButtonClicked), i));

    playerStats_[i].pack_start(rageQuit_[i]);

    // Add the points
    points_[i].set_text(stringify(0, "points"));
    playerStats_[i].pack_start(points_[i]);

    // Add the number of discards
    discards_[i].set_text(stringify(0, "discards"));
    playerStats_[i].pack_start(discards_[i]);

    // Show everything
    frames_[i].show();
    playerStats_[i].show();
    rageQuit_[i].show();
    points_[i].show();
    discards_[i].show();
  }
}

void PlayerListView::rageQuitButtonClicked(const int i) {

}

PlayerListView::~PlayerListView() {}
