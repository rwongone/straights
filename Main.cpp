#include <gtkmm.h>
#include "GameWindowView.h"
#include "Game.h"
#include "GameController.h"

int main(int argc, char* argv[]) {
  Gtk::Main kit(argc, argv);
  Game* game = new Game(0);
  GameController* controller = new GameController(game);
  GameWindowView window("Straights", game, controller);
  Gtk::Main::run(window);
  return 0;
}
