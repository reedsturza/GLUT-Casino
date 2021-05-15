//
// Created by rsturza on 5/14/2021.
// Deal is used to deal a Deck of cards into two separate vectors (player_hand and dealer_hand)
// from there the Deal class has a number of methods that are called upon to help run the games in the casino
// Deal is neither a component nor Parent/Child class
//

#include "deal.h"
#include <bits/stdc++.h>
using namespace std;

Deal::Deal() {

}

//draws the cards like a real game of black jack
void Deal::dealCards21() {
    cards.drawCard(playerHand);
    cards.drawCard(dealerHand);
    cards.drawCard(playerHand);
    cards.drawCard(dealerHand);
}

//draws a card to put into players hand
void Deal::dealPlayer() {
    cards.drawCard(playerHand);
}

//draws a card to put into players hand
void Deal::dealDealer() {
    cards.drawCard(dealerHand);
}

//return the score of the players hand
void Deal::getPlayersScore(int &score11, int &score1) {
    //if theres an ace it can either be 11 or 1
    bool ace = false;
    //reset the score values to zero each time so the score don't add when you draw another card
    score11 = 0;
    score1 = 0;
    for (int i = 0; i < playerHand.size(); i++) {
        string cardFace = playerHand[i].getFace();
        //find the index where a space is in the card string
        string::size_type pos = cardFace.find(' ');
        //stores the face into a string so if the card is 10 S, card_face = 10
        cardFace = cardFace.substr(0, pos);
        if (cardFace == "A") {
            ace = true;
            score11 += 11;
            score1 += 1;
        }
        else if (cardFace == "K") {
            score11 += 10;
            score1 += 10;
        }
        else if (cardFace == "Q") {
            score11 += 10;
            score1 += 10;
        }
        else if (cardFace == "J") {
            score11 += 10;
            score1 += 10;
        }
        else {
            score11 += stoi(cardFace);
            score1 += stoi(cardFace);
        }
    }
    //reset the score1 value to 0 just so we have a default score variable
    if (!ace) {
        score1 = 0;
    }
}

//return the score of the dealers hand
void Deal::getDealerScore(int &score11, int &score1) {
    //if theres an ace it can either be 11 or 1
    bool ace = false;
    //reset the score values to zero each time so the score don't add when the dealer draws another card
    score11 = 0;
    score1 = 0;
    for (int i = 0; i < dealerHand.size(); i++) {
        string cardFace = dealerHand[i].getFace();
        //find the index where a space is in the card string
        string::size_type pos = cardFace.find(' ');
        //stores the face into a string so if the card is 10 S, card_face = 10
        cardFace = cardFace.substr(0, pos);
        if (cardFace == "A") {
            ace = true;
            score11 += 11;
            score1 += 1;
        }
        else if (cardFace == "K") {
            score11 += 10;
            score1 += 10;
        }
        else if (cardFace == "Q") {
            score11 += 10;
            score1 += 10;
        }
        else if (cardFace == "J") {
            score11 += 10;
            score1 += 10;
        }
        else {
            score11 += stoi(cardFace);
            score1 += stoi(cardFace);
        }
    }
    //reset the score1 value to 0 just so we have a default score variable
    if (!ace) {
        score1 = 0;
    }
}

//returns the dealer's hand
vector<Card> Deal::getDealerHand() {
    return dealerHand;
}

//returns the players hand
vector<Card> Deal::getPlayerHand() {
    return playerHand;
}

void Deal::reset() {
    playerHand.clear();
    dealerHand.clear();
}


