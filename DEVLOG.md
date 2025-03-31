# Spindrift Develepment Log

Author: Matthew Romano

### v0.0.0
- Created ReadMe and Rules files
- Added basic rules and a description of the game
- Created Repository for the game itself

### v0.0.1
- Added very basic title screen
- Added basic main menu
- Main menu navigation functional

### v0.0.2
- Credits can now be displayed from the main menu
- Rules can also be displayed from the main menu
- In the rules/credits section the user can hit esc to exit them
- Exit selection in main menu now also exits game
- Basic GamePiece struct added with non-functional behaviours
- Changed file naming convention to have capitols at the start of their names

### v0.0.3
- Behaviours surrounding the game piece strcut have been updated
- Printing, creating, updating, attack functions all created and/or updated
- Game board struct added, along with function declarations for its behaviours
- Moving forward the game board is going to need a lot of work

### v0.0.4
- Gameboard setup is now possible
- You can add and remove pieces to/from the game board
- To do this I added an ID attribute to the game piece structure
- Gameboard can also be displayed but this function is very primiative
- Added functions to find the x and y coordinates of a piece on the board

### v0.0.5
- Getting close to a v0.1.0 but will hold of until more of the front end is complete
- Added linked list for store the pieces dynamically
- Linked list can add node, remove node, and print all nodes (for testing)
- Not sure yet if I will use 1 or two linked lists (for the player and enemies pieces)
- Removed redundant features
- Minor bug fixes

### v0.1.0
- I am confident in making this the 0.1.0 update because the player can now select new/load game
- Selecting new game will allow the player to then select thier ships
- Load game is non-functional for now
- Selecting/buying ships stores them into a linked list to be used later
- Major Bug fix, solution was broken but found bug with the "menus.h" file inclusion
- Cursor is hidden while the game is running

### v0.1.1
- The user must now select at least 1 piece during the piece selection menu
- The AI now select pieces at random (for now this is how that will be handled)
- The players and enemies oil's rigs will now be created during piece setup
- Added definitons for ID modifiers (players rigs, enemies rigs, players pieces, enimies pieces)
- Began development for piece placement at the beginning of the game
- Added feature to count the amount of pieces (may be redundant)
- Minor visual bug fixes

### v0.1.2
- Added enum for piece type instead of using int for readability
- Added coordinates struct that will be used to compare the pieces coordinates
- GamePiece includes this new struct and will store its own coordinates
- ID may now be redundant
- Minor bug fixes

