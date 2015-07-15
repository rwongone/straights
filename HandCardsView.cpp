#include "HandCardsView.h"

HandCardsView::HandCardsView(Gtk::Window &parent, Game* game, GameController* controller) :
  // Initialization List
  parent_(parent),
  cards_(1, 13, false),
  game_(game),
  controller_(controller) {

  // Start observing the Facade
  game->subscribe(this);

  set_label("Your Hand");

  for (int i = 0; i < 13; i++) {
    images_[i].set("img/nothing.png");
    cards_.attach(images_[i], i, i + 1, 0, 1);
    images_[i].show();
  }

  cards_.set_col_spacings(2);
  add(cards_);
  cards_.show();
}

HandCardsView::~HandCardsView() {}

std::string HandCardsView::toImageFile(const int i, const int j) const {
  std::ostringstream returnValue;
  returnValue << "img/" << i << "_" << j << ".png";
  return returnValue.str();
}

std::string HandCardsView::toImageFile(const Card& c) const {
  return toImageFile(c.getSuit(), c.getRank());
}

void HandCardsView::update() {
  currentPlayer_ = game_->getPlayer(game_->getCurrentPlayer());
  setHand(currentPlayer_->getHand());

  for (int i=0; i<13; i++) {
    cards_.attach(images_[i], i, i+1, 0, 1);
  }
}

void HandCardsView::setHand(std::vector<Card*> hand) {
  int i = 0;
  for (; i<hand.size(); i++) {
    images_[i].set(toImageFile(*(hand[i])));
  }
  for (; i<13; i++) {
    images_[i].set("img/nothing.png");
  }
}
