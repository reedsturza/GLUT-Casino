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
        string card_face = playerHand[i];
        //find the index where a space is in the card string
        string::size_type pos = card_face.find(' ');
        //stores the face into a string so if the card is 10 S, card_face = 10
        card_face = card_face.substr(0, pos);
        if (card_face == "A") {
            ace = true;
            score11 += 11;
            score1 += 1;
        }
        else if (card_face == "K") {
            score11 += 10;
            score1 += 10;
        }
        else if (card_face == "Q") {
            score11 += 10;
            score1 += 10;
        }
        else if (card_face == "J") {
            score11 += 10;
            score1 += 10;
        }
        else {
            score11 += stoi(card_face);
            score1 += stoi(card_face);
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
        string card_face = dealerHand[i];
        //find the index where a space is in the card string
        string::size_type pos = card_face.find(' ');
        //stores the face into a string so if the card is 10 S, card_face = 10
        card_face = card_face.substr(0, pos);
        if (card_face == "A") {
            ace = true;
            score11 += 11;
            score1 += 1;
        }
        else if (card_face == "K") {
            score11 += 10;
            score1 += 10;
        }
        else if (card_face == "Q") {
            score11 += 10;
            score1 += 10;
        }
        else if (card_face == "J") {
            score11 += 10;
            score1 += 10;
        }
        else {
            score11 += stoi(card_face);
            score1 += stoi(card_face);
        }
    }
    //reset the score1 value to 0 just so we have a default score variable
    if (!ace) {
        score1 = 0;
    }
}

//returns the dealer's hand
vector<string> Deal::getDealerHand() {
    return dealerHand;
}

//returns the players hand
vector<string> Deal::getPlayerHand() {
    return playerHand;
}

//converts dealers deck to a string and print
void Deal::printDealerHand() {
    string string_dealer;
    for (int i = 0; i < dealerHand.size(); i++) {
        if (i == (dealerHand.size()-1)) {
            string_dealer += dealerHand[i];
        }
        else {
            string_dealer += dealerHand[i] + ", ";
        }
    }
    cout << "Dealer's Hand: " << string_dealer << endl;
}

//converts players deck to a string and prints
void Deal::printPlayerHand() {
    string string_player;
    for (int i = 0; i < playerHand.size(); i++) {
        if (i == (playerHand.size()-1)) {
            string_player += playerHand[i];
        }
        else {
            string_player += playerHand[i] + ", ";
        }
    }
    cout << "Player's Hand: " << string_player << endl;
}


