//
// Created by rsturza on 5/10/2021.
//

#include "graphics.h"
#include "shape.h"
#include "Rect.h"
#include "Card.h"
#include "casino.h"
#include <iostream>
#include <vector>
using namespace std;

const color white(1, 1, 1);

GLdouble width, height;
int wd;
//boolean to decide if the user wants to play black Jack or the slot machine (true is black Jack | false is slot machines)
bool gameChosen;
//double for the amount of money a user wants to start out with
int money = 0;
//vector for the user's cards
vector<Card> playersHand;
//vector for the dealer's hand
vector<Card> dealersHand;
//shape for the deck of cards in the middle
Rect deck;

void initDeck() {
    deck.setColor(white);
    deck.setSize(75,100);
    deck.setCenter(250,250);
}

void init() {
    width = 500;
    height = 500;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    if (gameChosen) {
        glClearColor(0.00, 0.3, 0.05, 1.0); // casino table green
    }
    else {
        glClearColor(0.75, 0.75, 0.75, 1.0); //light grey
    }
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you're on a Mac running Catalina)

    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

    /*
     * Draw here
     */

    //the user wants to play blackjack
    if (gameChosen) {

        //draw the deck in the middle for the user to click on when they want to play or draw a card
        deck.draw();

    }
    //the user wants to play slots
    else {

    }


    //puts the users total points on the screen and updates after each correct pattern
    glRasterPos2i(10,490);
    for (const char &letter : to_string(money)) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:

            break;
        case GLUT_KEY_RIGHT:

            break;
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    glutPostRedisplay();
}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    //make a new casino and set gameChose to the game that was chosen by the user
    casino casinoRoyal;
    gameChosen = casinoRoyal.getGameChosen();
    money = casinoRoyal.getMoney();

    initDeck();

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Casino Royal" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}