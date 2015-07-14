#ifndef PLAYER_LIST_VIEW_H
#define PLAYER_LIST_VIEW_H

#include <gtkmm.h>
#include <iostream>

class PlayerListView : public Gtk::HBox {
public:
  PlayerListView(Gtk::Window&);
  virtual ~PlayerListView();
private:
  Gtk::Window &parent_;
  Gtk::Frame frames_[4];
  Gtk::VBox playerStats_[4];
  Gtk::Button rageQuit_[4];
  Gtk::Label points_[4];
  Gtk::Label discards_[4];
  void rageQuitButtonClicked(const int);
};

#endif
