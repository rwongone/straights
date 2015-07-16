#include "TopMenuView.h"

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

  seedButton.show();
  seedEntry.show();
  quitButton.show();
}

TopMenuView::~TopMenuView() {}

void TopMenuView::quitButtonClicked() {
  parent_.hide();
}

void TopMenuView::seedButtonClicked() {
  std::cerr << "hello there: " << seedEntry.get_text() << std::endl;
  controller_->setupGame();
}

void TopMenuView::update(){}
