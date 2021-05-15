//
// Created by rsturza on 5/10/2021.
//

#include "graphics.h"
#include "shape.h"
#include "Rect.h"
#include "Card.h"
#include "deal.h"
#include "casino.h"
#include <iostream>
#include <vector>
using namespace std;

string checkFinalScores(int player11Score, int player1Score, int dealer11Score, int dealer1Score, int &gameResult);
string checkPlayer21(Deal &game,
              int &player11Score, int &player1Score,
              bool &gameOver,
              bool &acePlayer,
              bool &playerStillDrawing, bool &dealerDraw, int &gameResult, bool &noFinalCheck, bool &noDealerCheck);
string checkDealer21(Deal &game,
                     int &dealer11Score, int &dealer1Score, bool &gameOver,
                     bool &aceDealer,
                     bool &dealerDraw, int &gameResult, bool &noFinalCheck);

const color white(1, 1, 1);
const color red(1, 0, 0);
const color black(0, 0, 0);
const color orange(1, 163/255.0, 22/255.0);

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
//rect for the deck of cards in the middle
Rect centerDeck;
Rect centerDeckOutline;
//rect for the hold button
Rect holdButton;
//creates a deal object for the game of 21
Deal game;
//boolean to decide if the users clicks the middle deck to start the game of 21 or draw a card
bool clickToStart21 = true;
//game result determines how much money you win or lose (1 = win, 2 = lose, 3 = tie)
int gameResult = 0;
//string that is printed when 21 is checked
string playerCheckPoint;
string finalCheckPoint;
//determines if there is a final check
bool noFinalCheck = false;
//determines if there is a dealer check
bool noDealerCheck = false;

////Variables for the check_21 function
//default score if there is no aces, will keep track of when there is aces and the player wants ace to be 11
int player11Score = 0;
int dealer11Score = 0;
//will keep track of when there is aces and the player wants ace to be 1
int player1Score = 0;
int dealer1Score = 0;
//decides when the game ends
bool gameOver = false;
//bool so the code knows if someone has an ace
bool acePlayer = false;
bool aceDealer = false;
bool playerStillDrawing = true;
bool dealerDraw = true;


void initHoldButton() {
    holdButton.setSize(50,25);
    holdButton.setCenter(300,360);
    holdButton.setColor(orange);
}

void initCenterDeck() {
    centerDeckOutline.setColor(white);
    centerDeck.setColor(0,0,1,1);
    centerDeckOutline.setSize(75,100);
    centerDeck.setSize(65,90);
    centerDeckOutline.setCenter(250,250);
    centerDeck.setCenter(250,250);
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
        centerDeckOutline.draw();
        centerDeck.draw();


        playersHand = game.getPlayerHand();

        for (int i = 0; i < playersHand.size(); i++) {
            playersHand[i].setCenter(175+(i*80), 450);
            playersHand[i].setSize(75,100);
            playersHand[i].setColor(white);
            playersHand[i].draw();
            if (playersHand[i].getCardColor()) {
                glColor3f(1,0,0);
            }
            else {
                glColor3f(0,0,0);
            }
            glRasterPos2i(165+(i*80),450);
            for (const char &letter : playersHand[i].toString()) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
            }
        }

        dealersHand = game.getDealerHand();

        for (int i = 0; i < dealersHand.size(); i++) {
            dealersHand[i].setCenter(175+(i*80), 50);
            dealersHand[i].setSize(75,100);
            dealersHand[i].setColor(white);
            dealersHand[i].draw();
            if (dealersHand[i].getCardColor()) {
                glColor3f(1,0,0);
            }
            else {
                glColor3f(0,0,0);
            }
            glRasterPos2i(165+(i*80),50);
            for (const char &letter : dealersHand[i].toString()) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
            }
        }

        if (!clickToStart21 && playerStillDrawing && !gameOver) {
            holdButton.draw();
            glColor3f(0, 0, 0);
            glRasterPos2i(285, 363);
            for (const char &letter : "Hold") {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
            }
            playerCheckPoint = checkPlayer21(game, player11Score, player1Score, gameOver, acePlayer,
                                  playerStillDrawing, dealerDraw, gameResult, noFinalCheck, noDealerCheck);
            //tells the player what they can do or if they lost
            glColor3f(1, 1, 1);
            glRasterPos2i(10, 350);
            for (const char &letter : playerCheckPoint) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
            }
        }

        //the dealer draws cards
        if (dealerDraw && !playerStillDrawing && !gameOver && !noDealerCheck) {
            finalCheckPoint = checkDealer21(game, dealer11Score, dealer1Score, gameOver, aceDealer, dealerDraw, gameResult, noFinalCheck);
        }

        //if the player and the dealer are done drawing plus the game isn't over yet
        if (!dealerDraw && !playerStillDrawing && !gameOver && !noFinalCheck) {
            finalCheckPoint = checkFinalScores(player11Score, player1Score, dealer11Score, dealer1Score, gameResult);
        }

        if (clickToStart21) {
            glColor3f(1, 1, 1);
            glRasterPos2i(10, 365);
            for (const char &letter : finalCheckPoint) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
            }
        }

        //resets everything for the game to start over
        if (gameResult == 1) {
            money += 50;
            player11Score = 0;
            dealer11Score = 0;
            player1Score = 0;
            dealer1Score = 0;
            gameOver = false;
            acePlayer = false;
            aceDealer = false;
            playerStillDrawing = true;
            dealerDraw = true;
            noFinalCheck = false;
            gameResult = 0;
            clickToStart21 = true;
        }
        else if (gameResult == 2) {
            money -= 50;
            player11Score = 0;
            dealer11Score = 0;
            player1Score = 0;
            dealer1Score = 0;
            gameOver = false;
            acePlayer = false;
            aceDealer = false;
            playerStillDrawing = true;
            dealerDraw = true;
            noFinalCheck = false;
            gameResult = 0;
            clickToStart21 = true;
        }
        else if (gameResult == 3) {
            player11Score = 0;
            dealer11Score = 0;
            player1Score = 0;
            dealer1Score = 0;
            gameOver = false;
            acePlayer = false;
            aceDealer = false;
            playerStillDrawing = true;
            dealerDraw = true;
            noFinalCheck = false;
            gameResult = 0;
            clickToStart21 = true;
        }

    }
    //the user wants to play slots
    else {

    }


    //puts the users total points on the screen and updates after each correct pattern
    glColor3f(1,1,1);
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
    //if the user chooses to play 21
    if (gameChosen) {

        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && centerDeck.isOverlapping(x,y) && playerStillDrawing) {
            if (clickToStart21) {
                game.reset();
                game.dealCards21();
                clickToStart21 = false;
            }
            else {
                //when the user clicks on the deck of cards during the game it will add a card to the user's hand
                game.dealPlayer();
            }
        }

        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && holdButton.isOverlapping(x,y) && playerStillDrawing) {
            playerStillDrawing = false;
        }

    }
    else {

    }
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

    initHoldButton();

    initCenterDeck();

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

/* checks the final scores for 21 */
string checkFinalScores(int player11Score, int player1Score, int dealer11Score, int dealer1Score, int &gameResult) {
    //finds the highest of the players hands in case they have an ace
    int player_higher;
    if (player11Score > player1Score && player11Score <= 21) {
        player_higher = player11Score;
    }
    else {
        player_higher = player1Score;
    }

    //finds the highest of the dealers hands in case they have an ace
    int dealer_higher;
    if (dealer11Score > dealer1Score && dealer11Score <= 21) {
        dealer_higher = dealer11Score;
    }
    else {
        dealer_higher = dealer1Score;
    }

    //these if statements decides the winner
    if (player_higher > dealer_higher) {
        gameResult = 1;
        return "You win! You beat the dealer +$50";
    }
    if (player_higher < dealer_higher) {
        gameResult = 2;
        return "You Lose... the dealer scored higher -$50";
    }
    if (player_higher == dealer_higher) {
        gameResult = 3;
        return "You Tied the dealer +$0";
    }
    return "";
}

/* runs the game of 21 */
string checkPlayer21(Deal &game,
              int &player11Score, int &player1Score,
              bool &gameOver,
              bool &acePlayer,
              bool &playerStillDrawing, bool &dealerDraw, int &gameResult, bool &noFinalCheck, bool &noDealerCheck) {
    /*
     * Player specific if, because in black jack the player draws till completion
     */

    if (playerStillDrawing) {
        game.getDealerScore(dealer11Score, dealer1Score);
        game.getPlayersScore(player11Score, player1Score);

        if (player11Score == 21) {
            playerStillDrawing = false;
        }

        //when the player doesn't have and ace and exceeds 21
        if ((player11Score > 21) && (player1Score == 0)) {
            playerStillDrawing = false;
            dealerDraw = false;
            gameResult = 2;
            gameOver = true;
            noFinalCheck = true;
            noDealerCheck = true;
            return "You Lose... you exceeded 21 -$50";
        }
        //when the player has an ace but exceeds 21 with A = 11 it set the ace_player to true so A = 1 is played
        if ((player11Score > 21) && (player1Score != 0)) {
            acePlayer = true;
        }
            //when the player exceeds 21 with A = 11 and A = 1
            if (player1Score > 21) {
                playerStillDrawing = false;
                dealerDraw = false;
                gameResult = 2;
                gameOver = true;
                noFinalCheck = true;
                noDealerCheck = true;
                return "You Lose... you exceeded 21 -$50";
            }
        return "You Can either Hold or Draw";
    }

    return "";
}

string checkDealer21(Deal &game,
                     int &dealer11Score, int &dealer1Score, bool &gameOver,
                     bool &aceDealer,
                     bool &dealerDraw, int &gameResult) {

    /*
     * Dealer specific if, only runs when player is holds
     */

    if (dealerDraw) {
        cout << endl;
        game.getDealerScore(dealer11Score, dealer1Score);
        game.getPlayersScore(player11Score, player1Score);

        if (dealer11Score == 21) {
            dealerDraw = false;
        }
        //in black jack is a dealer is 16 and below they must hit
        if (dealer11Score <= 16) {
            game.dealDealer();
        }
        //is a dealer is 17 and above they have to stay
        if (dealer11Score >= 17) {
            dealerDraw = false;
        }
        //when the dealer doesn't have and ace and they exceed 21
        if ((dealer11Score > 21) && (dealer1Score == 0)) {
            dealerDraw = false;
            gameResult = 1;
            gameOver = true;
            noFinalCheck = true;
            return "You Win! Dealer exceeded 21 +$50";
        }
        //when the dealer exceeds 21 but has an ace so they play A = 1
        if ((dealer11Score > 21) && (dealer1Score != 0)) {
            aceDealer = true;
        }
        //When the dealer has A = 1 and has to draw more cards
        if (aceDealer) {
            if (dealer1Score == 21) {
                dealerDraw = false;
            }
            if (dealer1Score <= 16) {
                game.dealDealer();
            }
            if (dealer1Score >= 17) {
                dealerDraw = false;
            }
            //When the dealer exceeds 21 with A = 11 and A = 1
            if (dealer1Score > 21) {
                gameResult = 1;
                gameOver = true;
                noFinalCheck = true;
                return "You win... the dealer exceeded 21 +$50";
            }
        }
    }

    return "";
}