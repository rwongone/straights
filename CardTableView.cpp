#include "CardTableView.h"

CardTableView::CardTableView(Gtk::Window &parent) : Gtk::Frame(), parent_(parent), cards_(13, 4, true) {
  set_label("Cards on the table");

  for (int i=0; i<13; i++) {
    for (int j=0; j<4; j++) {
      images_[i][j].set(toImageFile(j, i));
      cards_.attach(images_[i][j], i, i+1, j, j+1);
      images_[i][j].show();
    }
  }

  add(cards_);
  cards_.show();
}

CardTableView::~CardTableView() {}


std::string CardTableView::toImageFile(const int i, const int j) const {
  std::ostringstream returnValue;
  returnValue << "img/" << i << "_" << j << ".png";
  return returnValue.str();
}