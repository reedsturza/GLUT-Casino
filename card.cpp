//
// Created by rsturza on 5/14/2021.
//

#include "card.h"
using namespace std;

/********************* faceValue Struct ********************/
faceValue::faceValue() {}

faceValue::faceValue(string number, string suit) : number(number), suit(suit) {}



Card::Card(string number, string suit) {
    this->cardDetails = {number, suit};
}

string Card::getNumber() const{
    return cardDetails.number;
}

string Card::getSuit() const {
    return cardDetails.suit;
}
