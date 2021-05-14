//
// Created by rsturza on 5/14/2021.
// Deal is used to deal a Deck of cards into two separate vectors (player_hand and dealer_hand)
// from there the Deal class has a number of methods that are called upon to help run the games in the casino
// Deal is neither a component nor Parent/Child class
//

#ifndef FINAL_PROJECT_RSTURZA_DEAL_H
#define FINAL_PROJECT_RSTURZA_DEAL_H

#include "deck.h"
#include "card.h"
#include <iostream>
#include <vector>
#include <string>

class Deal {
private:
    Deck cards;
    vector<Card> playerHand;
    vector<Card> dealerHand;
public:
    /*
     * Default constructor
     * Requires: nothing
     * Modifies: nothing
     * Effects: starts the game
     */
    Deal();

    /*
     * deals the cards for 21
     * Requires: nothing
     * Modifies: dealerHand, playerHand
     * Effects: adds two cards to the dealer deck and player_hand
     */
    void dealCards21();


    /*
     * gives the player a card
     * Requires: nothing
     * Modifies: playerHand
     * Effects: adds one card to the players deck
     */
    void dealPlayer();

    /*
     * gives the dealer a card
     * Requires: nothing
     * Modifies: dealerHand
     * Effects: adds one card to the dealers deck
     */
    void dealDealer();


    /*
    * getter
    * Requires: nothing
    * Modifies: nothing
    * Effects: changes the score11 and score1 totals depending on the cards
    */
    void getPlayersScore(int &score11, int &score1);

    /*
    * getter
    * Requires: nothing
    * Modifies: nothing
    * Effects: changes the score11 and score1 totals depending on the cards
    */
    void getDealerScore(int &score11, int &score1);

    /*
    * getter
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns a vector for dealer deck
    */
    vector<Card> getDealerHand();

    /*
    * getter
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns a vector for your deck
    */
    vector<Card> getPlayerHand();

    /*
    * prints the dealers cards
    * Requires: nothing
    * Modifies: nothing
    * Effects: prints the dealer's hand
    */
    void printDealerHand();

    /*
    * prints the players cards
    * Requires: nothing
    * Modifies: nothing
    * Effects: prints the player's hand
    */
    void printPlayerHand();

};

#endif //FINAL_PROJECT_RSTURZA_DEAL_H
