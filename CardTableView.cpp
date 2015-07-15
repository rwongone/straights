#include "CardTableView.h"

namespace {
  const std::string NOTHING_CARD = "img/nothing.png";
}

CardTableView::CardTableView(Gtk::Window &parent, Game* game, GameController* controller) :
  // Initialization List
  parent_(parent),
  cards_(4, 13, false),
  game_(game),
  controller_(controller),
  table_(game_->getTable()) {

  // Start observing the Facade
  std::cerr << "CardTableView is subscribed to game facade." << std::endl;
  game->subscribe(this);

  set_label("Cards on the table");

  for (int i=0; i<13; i++) {
    for (int j=0; j<4; j++) {
      setCard(j, i, false);
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

void CardTableView::update(){
  std::cerr << "Table is updating." << std::endl;
  cardsOnTable_ = game_->getCardsOnTable();
  for(auto it=cardsOnTable_.begin(); it!=cardsOnTable_.end(); ++it) {
    int s = (*it)->getSuit();
    int r = (*it)->getRank();

    setCard(**it, true);
    cards_.attach(images_[s][r], s, s+1, r, r+1);
  }
}
