# Final-Project-rsturza
####Contributors: Reed Sturza

##How To Play
When you first run the program in the Run screen it will prompt the user whether they want to play black Jack or the slot machine. You either enter 'b' for
black jack or 's' for the slot machine. Then the program will ask the user for a int for the amount of money they want to gamble. The reason I ask the user
for the amount of money is because some people might want to start with less to try and gain more over time like a challenge, instead of just starting rich.
Once the inputs are entered and validated the openGl window will appear with the selected game. To switch between games at anytime the user can press 'b'
when in the slots machine game to switch to blackjack or press 's' in black jack to switch to the slots. The way to play the slots machine is pretty self
explanatory, the user just has to press the "Press to Spin" button on the screen and the program will do the rest. The way to Play black jack is a little
more complictated but still easy. To start a game of black jack you press of the deck in the middle of the screen. Then your cards and the dealer's cards will
appear. From there you either can press the deck again to draw a card or press the hold button to hold and see what the dealer ends up with. Once the game
ends the user just has to press the center deck again to restart the game. If at anytime the user's money equals zero or goes below then the openGl window
will close and the user is kicked out of the casino until they return with more money.

##Black Jack
This program is setup to play a game of 1 v 1 black jack. The player is given a hand of two cards and so is the dealer. The Objective is to get as close
to or exactly 21 without going over. The deck class is used to create a deck of 52 playing cards with suits (spades, diamonds, clubs, hearts) and face 
values (K,Q,J,10,9,8,7,6,5,4,3,2,A) and then store them in a vector of cards. The card class is used to link the deck and Rect together so I could draw the
individual cards. When the deck class is called the default constructor calls the shuffle method. Which basically creates the deck 
vector and adds in the card strings (ex. 10 S) using the face and suit vectors. The deck class also has a draw card method that will take the first string
in deck and push it into the given vector, then pop the deck. The deal class is setup to deal two separate hands, players hand and dealers hand. It does
this in th default constructor using the draw card method from deck. When the player or dealer wants to draw and extra card there are methods for that
as well. Next, the get score methods are setup to return the score of your or the dealer's hand. Since Ace and be either one or eleven there need to be
two separate score tallies for each hand. Finally the main function runs game of black jack and decides the winner based on the outcome of the hands. 

##Slot Machine
The slot machine is made using a vector of Rects with set x,y points and colors. The way the program switches the colors is using the vector of colors
and rand. When the user presses the slotMachineButton Rand selects a number in range of the vector of colors and then using that number to change each
slot to a randomly selected color. I've tested the outcome of gold and in 100 spins gold appears about 7-18 times. So the odds of getting a gold are 
about < 18%. 
