#include "TopMenuView.h"
#include <stdlib.h>

TopMenuView::TopMenuView(Gtk::Window &parent, Game* game, GameController* controller):
  // Initialization List
  parent_(parent),
  seedButton("Start new game with seed:"),
  quitButton("QUIT"),
  game_(game),
  controller_(controller) {

  // Start observing the Facade
  game->subscribe(this);

  pack_start(seedButton);
  pack_start(seedEntry);
  pack_start(quitButton);

  quitButton.signal_clicked().connect(sigc::mem_fun(*this, &TopMenuView::quitButtonClicked));
  seedButton.signal_clicked().connect(sigc::mem_fun(*this, &TopMenuView::seedButtonClicked));

  seedEntry.set_text("0");

  seedButton.show();
  seedEntry.show();
  quitButton.show();
}

TopMenuView::~TopMenuView() {}

void TopMenuView::quitButtonClicked() {
  parent_.hide();
}

void TopMenuView::seedButtonClicked() {
  controller_->resetGame(atoi(seedEntry.get_text().c_str()));
}

void TopMenuView::update(){}
