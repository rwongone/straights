#ifndef CARD_TABLE_VIEW_H
#define CARD_TABLE_VIEW_H

#include <gtkmm.h>
#include <string>
#include <set>
#include "Card.h"
#include "Game.h"
#include "GameController.h"
#include "Observer.h"

class CardTableView: public Gtk::Frame, public Observer {
public:                                                // PUBLIC
  CardTableView(Gtk::Window&, Game*, GameController*);   // Constructor
  ~CardTableView();                                      // Destructor
  virtual void update();                                 // Update the view with model data
private:                                               // PRIVATE
  Gtk::Window &parent_;                                  // Reference to the GameWindowView
  Gtk::Table cards_;                                     // Table containing the played cards
  Gtk::Image images_[13][4];                             // 2D array containing the images of played cards
  Table* table_;                                         // The game's table
  std::set<Card*>* cardsOnTable_;                        // Set of cards on the table
  Game* game_;                                           // Pointer to the model
  GameController* controller_;                           // Pointer to the controller
  void setCard(const Card, const bool);                  // Helper to add card to view
  void setCard(const int, const int, const bool);        // Helper to add card to view
};

#endif
