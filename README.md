# Ray-Caster-Memory-Challenge
Rewriting the 3D raycasting technique used in Wolfenstein 3D using the MLX library and C language. 
This project uses the Ray Casting graphics implementation to create an environment for the user to play the Memory Challenge. The Memory Challenge
aspect of this project is much like the memory card game, in which a player would flip over two cards at a time trying to find a match. When the game is
initialized the user is put in the center of the map and surrouned with 16 white boxes that have been randomly placed in their position. It's a race
against the clock for the user move about the map using the arrow keys trying to find all the pairs of matching boxes. The user does this by
moving in front of a block and pressing the space bar, if this block is the first guess it will change from white to its true hidden color. Then user
has to find the box of the same color on their next guess. If the user guesses wrong, the second block will remain white and the first block will change back
from it's true color to white. If the user guesses correctly both boxes are removed from the map and the player recieves a time bonus on countdown clock. The game
ends when either the user successfully finds all of the matching pairs or when the clock runs out and reaches zero. The player's score depends on
how many pairs of boxes were successfully found along with the remaining time left of the clock when the game ends. To accumalted a higher
score, the player is rewarded with a score multiplier for successfully finding multiple matching in a row without guessing wrong. If the player is able to
gain a large multiplier and finishes the game with time on the clock, they are in the running for reaching the Top Scores list, which is updated everytime 
a player achieves a higher score than another score currently on the list and the Top Scores will continue to carry over to all following games.


