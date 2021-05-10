//
// Created by rsturza on 5/10/2021.
// Casino is the parent class of both Play_21 and Play_War
// Casino uses override methods to run the games of black jack or war
//

#include "casino.h"
#include "unistd.h"
#include <iostream>
using namespace std;

casino::casino() {
    gameChosen = askPlayer();
}

/* asks the player if they want to play 21 or war */
string casino::askPlayer() {
    bool validInput = false;
    string gameChoice;
    cout << "Do you want to play: " << endl << "1. Black Jack (b)" << endl << "2. Slot Machine (w)" << endl << "Enter b or s:";
    cin >> gameChoice;
    while (!validInput) {
        if (gameChoice == "b" || gameChoice == "s") {
            validInput = true;
        }
        else {
            cout << "Invalid answer. b or s: " << endl;
            cin >> gameChoice;
        }
    }
    return gameChoice;
}

/* returns the game_chosen value as a boolean */
bool casino::getGameChosen() {
    if (gameChosen == "b") {
        return true;
    }
    else {
        return false;
    }
}