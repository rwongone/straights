#ifndef TOP_MENU_VIEW_H
#define TOP_MENU_VIEW_H

#include <gtkmm.h>
#include "Game.h"
#include "GameController.h"

class TopMenuView : public Gtk::HBox {
public:
  TopMenuView(Gtk::Window&, Game*, GameController*);
  virtual ~TopMenuView();
private:
  void quitButtonClicked();
  Gtk::Window &parent_;
  Gtk::Button seedButton;
  Gtk::Entry seedEntry;
  Gtk::Button quitButton;
};

#endif
