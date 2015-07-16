#ifndef ROUND_SUMMARY_VIEW_H
#define ROUND_SUMMARY_VIEW_H

#include <gtkmm.h>
#include "Game.h"
#include "GameController.h"

class RoundSummaryView: public Gtk::Dialog {
public:
  RoundSummaryView(Gtk::Window&, Game*, GameController*);
  ~RoundSummaryView();
private:
  Gtk::Window &parent_;
  Game* game_;
  GameController* controller_;
};

#endif
