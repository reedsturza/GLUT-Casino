//
// Created by rsturza on 5/14/2021.
// Generates a deck of cards and stores it in to a vector (full deck)
// can also shuffle the cards and draw a card from the deck
// this class is also a component class of Deal
//

#ifndef FINAL_PROJECT_RSTURZA_DECK_H
#define FINAL_PROJECT_RSTURZA_DECK_H

#include <vector>
#include "Card.h"
#include <iostream>
using namespace std;

class Deck {
private:
    //all the possible face values for a card in a deck
    vector<string> face = {"A", "K",  "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
    // all the possible suit values for a deck
    vector<string> suit = {"S", "H", "C", "D"};
    //the full deck is a vector of class Card
    vector<Card> fullDeck;
public:
    /*
     * Default constructor
     * Requires: nothing
     * Modifies: nothing
     * Effects: generates the two cards in your deck
     */
    Deck();

    /*
     * Shuffles the cards in the deck
     * Requires: nothing
     * Modifies: the positions each card is in the deck vector
     * effects: makes it so the cards are in different positions for each draw of a deck
     */
    void shuffle();


    /*
     * Draws one card from the deck and places it into the deck vector
     * Requires: nothing
     * Modifies: removes the first string in the deck and moves the rest to fill in like when you draw cards from the top of the deck
     * Effects: add card to the deck vector
     */
    void drawCard(vector<Card> &given_hand);

};

#endif //FINAL_PROJECT_RSTURZA_DECK_H
