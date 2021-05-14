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
    //either red or black
    color cardColor;
public:
    /* Constructors */
    Card(string face, string suit);
    Card(string face, string suit, color fill, dimensions size);

    /* Getters */
    string getFace() const; //returns the number as a string
    string getSuit() const; //returns the suit of the card
    bool getCardColor() const; //returns either red or black based on the cards suit

    /* There's no setters because you can't change the values of the cards in the deck or that's cheating */

    /* Takes the two faceValue parameters and converts them to one string */
    string toString();

    /* Draw */
    void draw() const override;
};

#endif //FINAL_PROJECT_RSTURZA_CARD_H
