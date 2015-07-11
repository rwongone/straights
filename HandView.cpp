#include "HandView.h"
#include <string>
#include <sstream>

namespace {
  std::string stringify(int i, std::string str){
    std::ostringstream returnString;
    returnString << i << " " << str;
    return returnString.str();
  }
};

HandView::HandView(Gtk::Window &parent): parent_(parent) {
  set_label("Your Hand");
  add(cardHBox);
}

HandView::~HandView() {}
