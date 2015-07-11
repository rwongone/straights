#include "TopMenuView.h"

TopMenuView::TopMenuView(Gtk::Window &parent): parent_(parent), seedButton("SEED"), seedEntry(), quitButton("QUIT") {
  pack_start(seedButton);
  pack_start(seedEntry);
  pack_start(quitButton);

  quitButton.signal_clicked().connect(sigc::mem_fun(*this, &TopMenuView::quitButtonClicked));

  seedButton.show();
  seedEntry.show();
  quitButton.show();
}

TopMenuView::~TopMenuView() {}

void TopMenuView::quitButtonClicked() {
  parent_.hide();
}
