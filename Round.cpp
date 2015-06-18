#include "Round.h"

Round::Round(Game* game, int seed) : game_(game), deck_(new Deck(seed)), table_(new Table()) {

}

// Might not be needed
Table* Round::getTable() const {
  return table_;
}

void Round::findStartingPlayer(){
  int startingPlayer = -1;
  for(int i = 0; i < 4; i++){
    if(game_->getPlayer(i)->hasStartCard()){
      startingPlayer = i;
    }
  }
  // assert startingPlayer != -1 (7S) exists
  startingPlayer_ = startingPlayer;
}

void Round::reset(){
  deck_->shuffle();
  distributeCards();
  findStartingPlayer();
  std::cout << "A new round begins. It's player " << (startingPlayer_ + 1) << "'s turn to play." << std::endl;
  gamePlay();
  endPhase();
}

void Round::distributeCards(){
  for (int i=0; i<4; i++){ // Use constants
    std::vector<Card*> playerHand;
    for(int j = 0; j < 13; j++){ // Use constants
      playerHand.push_back(deck_->getCard(13*i+j)); // Use constants
    }
    game_->getPlayer(i)->setHand(playerHand);
  }
}

void Round::gamePlay(){
  for(int i = 0; i < 13; i++){ // Use constant. Also, each round lasts up to 13 cards since we go
    for(int j = startingPlayer_; j < startingPlayer_ + 4; j++){
      int currentPlayer = j % 4; // Get the current player index. Wrap if past 4.
      game_->getPlayer(currentPlayer)->makeMove(table_);
    }
  }
}

void Round::endPhase(){
  // Tally up points. see if game is over
  if(true){
    game_->setGameOver();
  }
}
