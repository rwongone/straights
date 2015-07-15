#include "HandCardsView.h"

HandCardsView::HandCardsView(Gtk::Window &parent, Game* game, GameController* controller) :
  // Initialization List
  parent_(parent),
  cards_(1, 13, false),
  game_(game),
  controller_(controller) {

  // Start observing the Facade
  game_->subscribe(this);

  set_label("Your Hand");

  for (int i = 0; i < 13; i++) {
    images_[i].set("img/nothing.png");
    clickableImages_[i].set_image(images_[i]);
    cards_.attach(clickableImages_[i], i, i + 1, 0, 1);
  }

  cards_.set_col_spacings(2);
  add(cards_);
  show_all();
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
  std::cerr << "Updating hand for player " << game_->getCurrentPlayer() + 1 << std::endl;
  currentPlayer_ = game_->getPlayer(game_->getCurrentPlayer());
  setHand(currentPlayer_->getHand());
}

void HandCardsView::setHand(std::vector<Card*> hand) {
  for (unsigned int i=0; i<hand.size(); i++) {
    int currentPlayerIndex = game_->getCurrentPlayer();
    Card theCard = *hand[i];

    images_[i].set(toImageFile(theCard));
    clickableImages_[i].signal_clicked().connect(sigc::bind<int, Card>(sigc::mem_fun(*this, &HandCardsView::cardInHandClicked), currentPlayerIndex, theCard));
  }
  for (int i=hand.size(); i<13; i++) {
    images_[i].set("img/nothing.png");
  }

  for (int i=0; i<13; i++) {
    clickableImages_[i].set_image(images_[i]);
  }
}

void HandCardsView::cardInHandClicked(const int index, Card theCard) {
  controller_->playCard(index, theCard);
}
