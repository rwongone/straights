#include "RoundSummaryView.h"

RoundSummaryView::RoundSummaryView(Gtk::Window &parent, Game* game, GameController* controller) :
  // Initialization List
  parent_(parent),
  game_(game),
  controller_(controller){

}

RoundSummaryView::~RoundSummaryView() {}
