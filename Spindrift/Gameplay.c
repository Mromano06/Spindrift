// #include "Gameplay.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Implementation of the gameplay

// Player will chose there pieces here
ListOfPieces* pieceSelection(ListOfPieces* playersPieces) {
	int arrowPos = 1;
	int currentID = 11;
	int currentBudget = PLAYER_BUDGET;
	
	system("cls");
	pieceSelectionMenu(arrowPos, currentBudget);

	// 1 = rig, 2 = tugboat, 3 = speedboat, 4 = container ship
	while (1) {
		int keyPressed = getch(); // takes input
		switch (keyPressed) {

		case 13: // enter key
			if (arrowPos == 1 && currentBudget >= SPEEDBOAT_COST) {
				playersPieces = addPieceToList(createGamePiece(2)); // 2 is for speedboat
				currentBudget -= SPEEDBOAT_COST;
				printf("\n\nSpeedboat selected");
				Sleep(1250);
			}
			else if (arrowPos == 1 && currentBudget < SPEEDBOAT_COST) {
				printf("\n\nYou cannot afford this piece");
				Sleep(1250);
			}

			if (arrowPos == 2 && currentBudget >= TUGBOAT_COST) {
				playersPieces = addPieceToList(createGamePiece(3)); // 3 is for tugboat
				currentBudget -= TUGBOAT_COST;
				printf("\n\nTugboat selected");
				Sleep(1250);
			}
			else if (arrowPos == 2 && currentBudget < TUGBOAT_COST) {
				printf("\n\nYou cannot afford this piece");
				Sleep(1250);
			}

			if (arrowPos == 3 && currentBudget >= CONTAINER_SHIP_COST) {
				playersPieces = addPieceToList(createGamePiece(4)); // 4 is for con ship
				currentBudget -= CONTAINER_SHIP_COST;
				printf("\n\Container ship selected");
				Sleep(1250);
			}
			else if (arrowPos == 3 && currentBudget < CONTAINER_SHIP_COST) {
				printf("\n\nYou cannot afford this piece");
				Sleep(1250);
			}

			if (arrowPos == 4) {
				printf("\n\nPiece selection confirmed");
				Sleep(1250);
				return playersPieces;
			}

			pieceSelectionMenu(arrowPos, currentBudget);
			break;

		case 27: // escape key quits
			printf("\n\nPiece selection confirmed");
			exit(EXIT_SUCCESS);
			break;

		case 72: // up arrow
			if (arrowPos == 1) // loops back around
				arrowPos = SELECTION_MENU_OPTIONS + 1;
			pieceSelectionMenu(--arrowPos, currentBudget);
			break;

		case 80: // down arrow
			if (arrowPos == SELECTION_MENU_OPTIONS) // loops back around
				arrowPos = 0;
			pieceSelectionMenu(++arrowPos, currentBudget);
			break;

		}
	}

	return NULL; // Dont need this but just in case
}

// Handles game setup
// TODO: Add difficulty and game length
void startGame() {
	Gameboard gameboard = createGameboard(); 
	ListOfPieces* playersPieces = (ListOfPieces*)malloc(sizeof(ListOfPieces));
	ListOfPieces* enemiesPieces = (ListOfPieces*)malloc(sizeof(ListOfPieces));

	// Returns 0 for new game and 1 for load game
	if (mainMenuStart() == 1) {
		pieceSelection(playersPieces);
		// enemyPieceSelection(playersPieces);
	}
	else {
		// loadGameSetup(); 
	}

}