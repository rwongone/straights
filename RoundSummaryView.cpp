#include "RoundSummaryView.h"

RoundSummaryView::RoundSummaryView(Gtk::Window &parent, std::string message) :
  // Initialization List
  MessageDialog(parent, message),
  parent_(parent){

  set_default_size(300, 150);
  show_all_children();
  int result = run();
}

RoundSummaryView::~RoundSummaryView() {}
