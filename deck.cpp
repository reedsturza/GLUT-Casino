//
// Created by rsturza on 5/14/2021.
// Generates a deck of cards and stores it in to a vector (full deck)
// can also shuffle the cards and draw a card from the deck
// this class is also a component class of Deal
//

#include "Deck.h"
#include "algorithm"
#include "time.h"
using namespace std;

//default constructor runs the methods to generate a random deck
Deck::Deck() {
    srand(time(NULL));
    //creates the combination for all cards in a deck with face and suit values and then adds them as a card object to the full_deck vector
    for (int y = 0; y < suit.size(); y++) {
        for (unsigned int x = 0; x < face.size(); x++) {
            Card c(face[x], suit[y]);
            fullDeck.push_back(c);
        }

    }
    shuffle();
}

//generates the deck AS-2D then shuffles the deck
void Deck::shuffle() {
    random_shuffle(fullDeck.begin(),fullDeck.end());
}

//draws and card from the deck and removes it from the deck
void Deck::drawCard(vector<Card> &givenHand) {
    givenHand.push_back(fullDeck[0]);
    fullDeck.erase(fullDeck.begin());
}
