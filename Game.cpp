#include "Game.h"

// Constructor
Game::Game(int seed = 0): gameOver_(false), round_(new Round(this, seed)){
  // while(!gameOver_){
  //   round_->reset();
  // }
  // gameEnd();
}

void Game::setPlayer(int index, Player* player) {
  players_[index] = player;
}

Player* Game::getPlayer(int index){
  // Assert valid index
  return players_[index];
}

void Game::setGameOver(){
  gameOver_ = true;
}

void Game::gameEnd(){
  // clean up
}
