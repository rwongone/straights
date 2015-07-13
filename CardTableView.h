#ifndef CARD_TABLE_VIEW_H
#define CARD_TABLE_VIEW_H

#include <gtkmm.h>
#include <sstream>
#include <iostream>
#include <string>
#include "Card.h"

class CardTableView: public Gtk::Frame {
public:
  CardTableView(Gtk::Window&);
  ~CardTableView();
private:
  Gtk::Window &parent_;
  Gtk::Table cards_;
  Gtk::Image images_[13][4];
  std::string toImageFile(const int, const int) const;
  void setCard(const int, const int, const bool);
  void setCard(const Card, const bool);
};

#endif
