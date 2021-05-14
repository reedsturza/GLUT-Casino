//
// Created by rsturza on 5/14/2021.
//

#include "card.h"
#include "graphics.h"
using namespace std;

/********************* faceValue Struct ********************/
faceValue::faceValue() {}

faceValue::faceValue(string face, string suit) : face(face), suit(suit) {}




Card::Card(string face, string suit) {
    this->cardDetails = {face, suit};
}

//calls the parent constructor to initialize the size and color of the card
Card::Card(string face, string suit, color fill, dimensions size) : Rect(fill, size) {
    this->cardDetails = {face, suit};
}

string Card::getFace() const{
    return cardDetails.face;
}

string Card::getSuit() const {
    return cardDetails.suit;
}

bool Card::getCardColor() const {
    if (cardDetails.suit == "D" || cardDetails.suit == "H") {
        return true;
    }
    else {
        return false;
    }
}

string Card::toString() {
    return cardDetails.face + " " + cardDetails.suit;
}

/* Draw */
void Card::draw() const {
    // Don't forget to set the color to the fill field
    // Set drawing color to fill color
    glColor3f(fill.red, fill.green, fill.blue);
    // Draw rectangle using Triangle Strip
    glBegin(GL_TRIANGLE_STRIP);
    // Draw center point
    glVertex2i(center.x, center.y);
    //bottom right point
    glVertex2i(center.x + (this->getWidth()/2), center.y + (this->getHeight()/2));
    //bottom left point
    glVertex2i(center.x - (this->getWidth()/2), center.y + (this->getHeight()/2));
    //top right point
    glVertex2i(center.x + (this->getWidth()/2), center.y - (this->getHeight()/2));
    //top left point
    glVertex2i(center.x - (this->getWidth()/2), center.y - (this->getHeight()/2));
    // End Triangle Strip
    glEnd();
}

