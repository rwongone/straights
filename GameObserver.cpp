#include "GameObserver.h"

GameObserver::GameObserver(Game* game, GameController* controller): game_(game), controller(controller_) {}

GameObserver::~GameObserver() {}
