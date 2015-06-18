#include "Game.h"

// Constructor
Game::Game(int seed = 0): gameOver_(false), round_(new Round(this, seed)){
  setupPlayers();
  while(!gameOver_){
    round_->reset();
  }
  gameEnd();
}

Player* Game::getPlayer(int index){
  // Assert valid index
  return players_[index];
}

void Game::setupPlayers(){
  for(int i = 0; i < 4; i++){
    std::cout << "Is player " << (i + 1) << " a human(h) or a computer(c)?" << std::endl;
    std::string playerType;
    std::cin >> playerType;
    assert(playerType == "h" || playerType == "c");

    if(playerType == "h"){
      players_[i] = new HumanPlayer();
    } else {
      players_[i] = new ComputerPlayer();
    }
  }
}

void Game::setGameOver(){
  gameOver_ = true;
}

void Game::gameEnd(){

}
