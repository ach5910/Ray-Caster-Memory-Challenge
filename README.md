# Ray-Caster-Memory-Challenge
- The minilibx library is an OpenGL wrapper library and supports MacOS. Minilibx it written to also be ported to Linux but
  the behavior is undefined.
  
INSTALLATION
- Clone repository
- Run make in root directory
- In root directory run ./wolf executable followed by a player name
- Player name must be a single string of length between 3-10 alpha characters


INSTRUCTIONS
- Find all the pairs of blocks of matching color before the time runs out
- Use the arrow keys to navigate the map
- Once in front of a white block press Space bar to reveal the blocks true color
- On first guess the block will change to it's true color
- On second guess, if the block matches the previous guess the pair will be removed from the map and a time bonus will be added
- If the guess is incorrect the block will remain white and the previous block's color will change back to white

FEATURES
- Timer count down
- Textured walls, floor and ceiling using Bit Manipulation to write each individual pixel
- Time bonus for correct guesses
- Block bonus for finding a correct match
- Multiplier bonus for finding multiple matches in a row
- Top Ten score board that stores best scores and updates every game accoringly
