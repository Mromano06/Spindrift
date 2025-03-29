#include "Gameplay.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Implementation of the gameplay

// Player will chose there pieces here
ListOfPieces* pieceSelection(ListOfPieces* playersPieces) {
	int arrowPos = 1;
	int currentID = 11;
	// 1 = rig, 2 = tugboat, 3 = speedboat, 4 = container ship
	while (1) {
		int keyPressed = getch(); // takes input
		switch (keyPressed) {

		case 13: // enter key allows for selection
			if (arrowPos == 1)
				return arrowPos; // 1 for new game
			if (arrowPos == 2)
				return arrowPos; // 2 for load game
			if (arrowPos == 3)
				rules();
			if (arrowPos == 4)
				credits();
			if (arrowPos == 5)
				exit(EXIT_SUCCESS);
			mainMenu(arrowPos);
			break;

		case 27: // escape key quits
			exit(EXIT_SUCCESS);
			break;

		case 72: // up arrow
			if (arrowPos == 1) // loops back around
				arrowPos = SELECTION_MENU_OPTIONS + 1;
			mainMenu(--arrowPos);
			break;

		case 80: // down arrow
			if (arrowPos == SELECTION_MENU_OPTIONS) // loops back around
				arrowPos = 0;
			mainMenu(++arrowPos);
			break;

		}
	}

	return playersPieces;
}

// Handles game setup
// TODO: Add difficulty and game length
void startGame() {
	Gameboard gameboard = createGameboard(); 
	ListOfPieces *playersPieces, *enemiesPieces;

	// Returns 0 for new game and 1 for load game
	if (mainMenuStart() == 1) {
		playerPieceSelection(playersPieces);
		// enemyPieceSelection(playersPieces);
	}
	else {
		// loadGameSetup(); 
	}

}