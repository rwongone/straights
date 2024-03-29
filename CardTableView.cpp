#include "CardTableView.h"
#include <sstream>

namespace {
  // Helper to format image file name
  std::string toImageFile(int i, int j) {
    std::ostringstream returnValue;
    returnValue << "img/" << i << "_" << j << ".png";
    return returnValue.str();
  }
  const std::string NOTHING_CARD = "img/nothing.png";
}

// Constructor
CardTableView::CardTableView(Gtk::Window &parent, Game* game, GameController* controller) :
  // Initialization List
  parent_(parent),
  cards_(4, 13, false),
  game_(game),
  table_(game_->getTable()),
  controller_(controller) {

  // Start observing the Facade
  game->subscribe(this);

  // Initialize table with empty cards
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

// Destructor
CardTableView::~CardTableView() {}

// Helper to add card to table
void CardTableView::setCard(const int suitIndex, const int rankIndex, const bool onTable) {
  if (onTable) {
    images_[rankIndex][suitIndex].set(toImageFile(suitIndex, rankIndex));
  } else {
    images_[rankIndex][suitIndex].set(NOTHING_CARD);
  }
}

// Helper to add card to table
void CardTableView::setCard(const Card c, const bool onTable) {
  setCard(c.getSuit(), c.getRank(), onTable);
}

// Update the view by fetching the cards from the model
void CardTableView::update(){
  cardsOnTable_ = game_->getCardsOnTable();

  for (int i=0; i<4; i++) {
    for (int j=0; j<13; j++) {
      setCard(i, j, false);
    }
    for(auto it=cardsOnTable_[i].begin(); it!=cardsOnTable_[i].end(); ++it) {
      setCard(**it, true);
    }
  }
}
