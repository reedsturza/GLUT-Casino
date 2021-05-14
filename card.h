//
// Created by rsturza on 5/14/2021.
//

#ifndef FINAL_PROJECT_RSTURZA_CARD_H
#define FINAL_PROJECT_RSTURZA_CARD_H

#include "rect.h"
using namespace std;

struct faceValue {
    string face;
    string suit;

    /* Constructors */
    faceValue();
    faceValue(string face, string suit);


};

class Card : public Rect {
private:
    faceValue cardDetails;
public:
    /* Constructors */
    Card(string face, string suit);

    /* Getters */
    string getFace() const; //returns the number as a string
    string getSuit() const; //returns the suit of the card

    /* There's no setters because you can't change the values of the cards in the deck or that's cheating */

    /* Takes the two faceValue parameters and converts them to one string */
    string toString();
};

#endif //FINAL_PROJECT_RSTURZA_CARD_H
