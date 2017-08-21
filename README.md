# Tic-Tac-Toe-project-repository

This project relates to a device for playing tic-tac-toe using an arduino and some basic materials. The project is based on 2 similar projects found on instructables.com, 1 2 player game by leQuack and a game against an AI by redsox70. The version found here allows the user to play either agains that AI or a friend in a one player or two player mode.

Here is a picture, you can find other angles in the /img folder:

![Project Image](/img/IMG_0228.JPG)

# Materials:
- 1 Arduino Uno.
- A large enough bread board/collection of breadboards of fit the project. (I found 2 long narrow ones did me well, but you could try more if you want to do something imressive)
- 20 LEDs, 10 each of 2 colors.
- 19 330 ohm Resistors.
- 6 680 ohm Resistors I instead had to use 6 120 ohm resistors and 6 6 ohm resistors, but it worked).
- 18 push buttons.
- A large amount of wire. Prepare some long stuff too, it may have to reach from the arduino across your board.

# Build instructions:

The hardware design for the tic-tac-toe game is identical to the design of leQuack's tic-tac-toe game. For this reason, it might be for the best to first look at these 2 diagrams from that project's page, and then go over them in detail.

![Light Diagram](/img/FKJG65ZIY0FURS2_MEDIUM.jpg )

![Button Diagram](/img/FZ15E1KIY0FURQC_MEDIUM.jpg  )

A few things to take notice of when making this project:
- in all cases where 2 lights are right next to each other, you are ment to put the negative ends in each whichever strip is shared between them, as they have different high points, but the same ground.
- ports 0, 1, and 2 connect to the positive ends of the leftmost lights in each cloumn through a resistor while poarts 3, 4, and 5 connect to the rightmost lights in each column through a resistor, from right to left in each case.
- ports 6, 7, and 8 meanwhile, are connected to the negative ends of all lights in each row, from top to bottom.
- The left and right set of buttons mirror each other, with exception for the wires, connected to the Arduino. For this reason, only the left set will be discussed.
- On the leftmost column, each of the top points connects to the bottom point of the button bolow it in the middle column, looping back for the bottom left button.
- The bottom points of each of the leftmost buttons goes to ground through a 680 ohm resistor (though the project described here used 560 ohm resistors and 120 ohm resistors in srial to the same effect).
- On the rightmost column, each of the top points connects to it's mirror point on the other side, while each of the bottom points connect to the top point of the middle button below it, looping back for the bottom right one.

# Software instilation:

This is just a simple upload into the arduino, made convinient by the fact that the arduino's port for upleading sketches faces away from the huge mess that is the breadboards. Just keep in mind, you will need the headerfiles in the same foalder as the arduino file.

All the files are found in the /src foulder. 

# Usage:

In order to play the
game, the user must first select the mode they want to use, which they do by
using one of the two buttons panels on the end of the device. Pushing a button
on the yellow side starts a two player game, with the red side going first,
while pushing one of the red side’s buttons starts a game against an AI that
plays red. None of the lights are on at this first stage, but there are no
errors occurring.

In the 2 player game, each side alternates between
selecting one unused light until some conclusion is reached. In the event of a
tie, with all spots on the grid used up, the game will reset with the player
who last played going second. If either side gets 3 spots in a row, they will
win as in typical tic-tac-toe, and there will be a quick animation with the
status lights alternating before resetting the game the same way as in the
event of a tie. Since the game resets to the same state every time a conclusion
is reached, the user must reset the device in order to switch between modes.

The AI mode is different due to the presence of an AI
opponent that takes over for one of the players. On the AI’s turn, it will
randomly select any unused spot on the grid and tell the button processing code
that it has pushed that button. Currently, the AI goes first in the first game,
but a user with access to the code can easily change that by switching the
value of a Boolean element at the top of the sketch. Otherwise, this mode is
very similar to the two player mode, with regards to how each game ends and the
necessity to reset the device to switch game modes.

# credits:

The 2 player source game is by leQuack on instructables.com.

the 1 player source game is by redsox70 on instructables.com.
