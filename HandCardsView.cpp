#include "HandCardsView.h"
#include <sstream>

HandCardsView::HandCardsView(Gtk::Window &parent, Game* game, GameController* controller) :
  // Initialization List
  parent_(parent),
  cards_(2, 13, false),
  game_(game),
  controller_(controller) {

  // Start observing the Facade
  game_->subscribe(this);

  for (int i = 0; i < 13; i++) {
    images_[i].set("img/nothing.png");
    discardIcons_[i].set("img/delete.png");
    clickableImages_[i].set_image(images_[i]);
    cards_.attach(clickableImages_[i], i, i + 1, 0, 1);
    cards_.attach(discardIcons_[i], i, i + 1, 1, 2);
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
  std::ostringstream label;
  int currentPlayerIndex = game_->getCurrentPlayer();
  label << "Player " << currentPlayerIndex + 1 << "'s hand" << std::endl;
  set_label(label.str());
  currentPlayer_ = game_->getPlayer(currentPlayerIndex);

  std::vector<Card*> hand = currentPlayer_->getHand();
  setHand(currentPlayerIndex, hand);
  std::vector<Card*> legalMoves = game_->getLegalMoves(currentPlayerIndex);

  if (legalMoves.size() > 0) {
    for (unsigned int i=0; i<hand.size(); i++) {
      discardIcons_[i].clear();
      for (auto it=legalMoves.begin(); it!=legalMoves.end(); ++it) {
        if (*hand[i] == **it) {
          discardIcons_[i].set("img/up.png");
          break;
        }
      }
    }
  }
}

void HandCardsView::setHand(const int index, std::vector<Card*> hand) {
  bool canPlay = game_->getLegalMoves(index).size() > 0;

  for (int i=0; i<13; i++) {
    clickableImagesHandlers_[i].disconnect();
  }

  for (unsigned int i=0; i<hand.size(); i++) {
    Card theCard = *hand[i];
    images_[i].set(toImageFile(theCard));
    discardIcons_[i].set("img/delete.png");
    if (canPlay) {
      clickableImagesHandlers_[i] = clickableImages_[i].signal_clicked().connect(sigc::bind<int, Card>(sigc::mem_fun(*this, &HandCardsView::cardInHandClicked), index, theCard));
    } else {
      clickableImagesHandlers_[i] = clickableImages_[i].signal_clicked().connect(sigc::bind<int, Card>(sigc::mem_fun(*this, &HandCardsView::discardButtonClicked), index, theCard));
    }
  }
  for (int i=hand.size(); i<13; i++) {
    images_[i].set("img/nothing.png");
    discardIcons_[i].clear();
  }

  for (int i=0; i<13; i++) {
    clickableImages_[i].set_image(images_[i]);
  }
}

void HandCardsView::cardInHandClicked(const int index, Card theCard) {
  controller_->playCard(index, theCard);
}

void HandCardsView::discardButtonClicked(const int index, Card theCard) {
  controller_->discardCard(index, theCard);
}

// no operation
void HandCardsView::NOOP() const {
  return;
}
