#include "CardTableView.h"

namespace {
  const std::string NOTHING_CARD = "img/nothing.png";
}

CardTableView::CardTableView(Gtk::Window &parent, Game* game, GameController* controller) :
  // Initialization List
  parent_(parent),
  cards_(4, 13, false),
  game_(game),
  controller_(controller) {

  // Start observing the Facade
  game->subscribe(this);

  set_label("Cards on the table");

  for (int i=0; i<13; i++) {
    for (int j=0; j<4; j++) {
      images_[i][j].set(toImageFile(j, i));
      cards_.attach(images_[i][j], i, i+1, j, j+1);
    }
  }

  cards_.set_row_spacings(5);
  cards_.set_col_spacings(2);
  add(cards_);
  show_all();
}

CardTableView::~CardTableView() {}

void CardTableView::setCard(const int suitIndex, const int rankIndex, const bool onTable) {
  if (onTable) {
    images_[rankIndex][suitIndex].set(toImageFile(suitIndex, rankIndex));
  } else {
    images_[rankIndex][suitIndex].set(NOTHING_CARD);
  }
}

void CardTableView::setCard(const Card c, const bool onTable) {
  setCard(c.getSuit(), c.getRank(), onTable);
}

std::string CardTableView::toImageFile(const int i, const int j) const {
  std::ostringstream returnValue;
  returnValue << "img/" << i << "_" << j << ".png";
  return returnValue.str();
}

void CardTableView::update(){}
