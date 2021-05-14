//
// Created by rsturza on 5/14/2021.
//

#include "card.h"
using namespace std;

/********************* faceValue Struct ********************/
faceValue::faceValue() {}

faceValue::faceValue(string face, string suit) : face(face), suit(suit) {}




Card::Card(string face, string suit) {
    this->cardDetails = {face, suit};
}

string Card::getFace() const{
    return cardDetails.face;
}

string Card::getSuit() const {
    return cardDetails.suit;
}

string Card::toString() {
    return cardDetails.face + " " + cardDetails.suit;
}
