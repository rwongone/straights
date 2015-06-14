#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cassert>
#include <vector>

// Constructor
Game::Game(int seed = 0): deck_(new Deck(seed)), table_(new Table()){
  for(int i = 0; i < 4; i++){
    std::cout << "Is player " << (i + 1) << " a human(h) or a computer(c)?" << std::endl;
    std::string playerType;
    std::cin >> playerType;
    assert(playerType == "h" || playerType == "c");

    // Hand playerHand = new Hand();
    std::vector<Card*> playerHand;

    for (int j=0; j<13; j++) {
      playerHand.push_back(deck_->getCard(13*i+j));
    }

    if(playerType == "h"){
      players_[i] = new HumanPlayer(playerHand);
    } else {
      players_[i] = new ComputerPlayer(playerHand);
    }
  }
}
