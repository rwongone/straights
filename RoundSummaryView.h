#ifndef ROUND_SUMMARY_VIEW_H
#define ROUND_SUMMARY_VIEW_H

#include <gtkmm.h>
#include <string>
#include "Game.h"
#include "GameController.h"

class RoundSummaryView: public Gtk::MessageDialog {
public:                                       // PUBLIC
  RoundSummaryView(Gtk::Window&, std::string);  // Constructor
  ~RoundSummaryView();                          // Destructor
private:                                      // PRIVATE
  Gtk::Window &parent_;                         // Reference to GameWindowView
};

#endif
