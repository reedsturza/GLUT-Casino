//
// Created by rsturza on 5/10/2021.
// Casino is the parent class of both Play_21 and Play_War
// Casino uses override methods to run the games of black jack or war
//

#ifndef M4OEP_GRAPHICS2_RSTURZA_CASINO_H
#define M4OEP_GRAPHICS2_RSTURZA_CASINO_H

#include <string>
using namespace std;

class casino {
private:
    //the amount of money the player still has
    double money;
    string gameChosen;
public:
    /*
     * Default constructor
     * Requires: nothing
     * Modifies: nothing
     * Effects: runs the casino
     */
    casino();

    /*
     * asks the player what game they want to play
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns a boolean either b for black jack or s for slots
     */
    string askPlayer();

    /*
     * returns the game chosen as a boolean
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns a boolean either true for black jack and false for slots
     */
    bool getGameChosen();

};

#endif //M4OEP_GRAPHICS2_RSTURZA_CASINO_H
