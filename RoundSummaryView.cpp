#include "RoundSummaryView.h"

RoundSummaryView::RoundSummaryView(Gtk::Window &parent, Game* game, GameController* controller) :
  // Initialization List
  Dialog("Round Summary", parent, true, true),
  parent_(parent),
  game_(game),
  controller_(controller){

  set_default_size(300, 150);
  show_all_children();
  // int result = run();
}

RoundSummaryView::~RoundSummaryView() {}
