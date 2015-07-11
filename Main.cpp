#include <gtkmm.h>
#include "GameWindowView.h"

int main(int argc, char* argv[]) {
  Gtk::Main kit(argc, argv);
  GameWindowView window("Straights");
  Gtk::Main::run(window);
  return 0;
}
