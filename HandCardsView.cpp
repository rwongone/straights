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
    images_[i].set(toImageFile(0, i));
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

void HandCardsView::update(){}
