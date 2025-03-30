#include "Gameplay.h"
#include "Gameboard.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Menus.h"

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Implementation of the gameplay

// Player will chose there pieces here
// TODO: Add a check to make sure the player has at minimum 1 Piece
ListOfPieces* pieceSelection(ListOfPieces* playersPieces) {
	int arrowPos = 1;
	int currentID = 11;
	int currentBudget = PIECE_BUDGET;
	GamePiece temp; // Needed to set ID
	
	system("cls");
	pieceSelectionMenu(arrowPos, currentBudget);

	// 1 = rig, 2 = tugboat, 3 = speedboat, 4 = container ship
	while (1) {
		int keyPressed = getch(); // takes input
		switch (keyPressed) {

		case 13: // enter key
			if (arrowPos == 1 && currentBudget >= SPEEDBOAT_COST) {
				temp = createGamePiece(2); // 2 is for speedboat
				temp.ID = currentID;
				playersPieces = addPieceToList(temp);
				currentBudget -= SPEEDBOAT_COST;
				currentID++; // Increment the ID upon piece creation
				printf("\n\nSpeedboat selected");
				Sleep(750);
			}
			else if (arrowPos == 1 && currentBudget < SPEEDBOAT_COST) {
				printf("\n\nYou cannot afford this piece");
				Sleep(750);
			}

			if (arrowPos == 2 && currentBudget >= TUGBOAT_COST) {
				temp = createGamePiece(3); // 3 is for tugboat
				temp.ID = currentID;
				playersPieces = addPieceToList(temp);
				currentBudget -= TUGBOAT_COST;
				currentID++; // Increment the ID upon piece creation
				printf("\n\nTugboat selected");
				Sleep(750);
			}
			else if (arrowPos == 2 && currentBudget < TUGBOAT_COST) {
				printf("\n\nYou cannot afford this piece");
				Sleep(750);
			}

			if (arrowPos == 3 && currentBudget >= CONTAINER_SHIP_COST) {
				temp = createGamePiece(4);  // 4 is for container ship
				temp.ID = currentID;
				playersPieces = addPieceToList(temp);
				currentBudget -= CONTAINER_SHIP_COST;
				currentID++; // Increment the ID upon piece creation
				printf("\n\nContainer ship selected");
				Sleep(750);
			}
			else if (arrowPos == 3 && currentBudget < CONTAINER_SHIP_COST) {
				printf("\n\nYou cannot afford this piece");
				Sleep(750);
			}

			if (arrowPos == 4) {
				printf("\n\nPiece selection confirmed");
				Sleep(750);
				return playersPieces;
			}

			pieceSelectionMenu(arrowPos, currentBudget);
			break;

		case 27: // escape key quits
			printf("Piece selection confirmed");
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

// AI piece selection
//TODO: Refine the piece selection for the AI 
ListOfPieces* ePieceSelection(ListOfPieces* enemiesPieces) {
	int currentID = 0;
	int currentBudget = PIECE_BUDGET;
	int selection = 0;
	GamePiece temp; // So ID can be incremented

		while (currentBudget > 0) {
			selection = (rand() % (NUMBER_OF_PIECES)) + 1;

			if (selection == 1 && currentBudget >= SPEEDBOAT_COST) {
				temp = createGamePiece(2); // 2 is for speedboat
				temp.ID = currentID;
				enemiesPieces = addPieceToList(temp);
				currentBudget -= SPEEDBOAT_COST;
				currentID++; // Increment the ID upon piece creation
			}

			if (selection == 2 && currentBudget >= TUGBOAT_COST) {
				temp = createGamePiece(3); // 3 is for tugboat
				temp.ID = currentID;
				enemiesPieces = addPieceToList(temp);
				currentBudget -= TUGBOAT_COST;
				currentID++; // Increment the ID upon piece creation
			}

			if (selection == 3 && currentBudget >= CONTAINER_SHIP_COST) {
				temp = createGamePiece(4); // 4 is for container ship
				temp.ID = currentID;
				enemiesPieces = addPieceToList(temp);
				currentBudget -= CONTAINER_SHIP_COST;
				currentID++; // Increment the ID upon piece creation
			}	
		}

	return enemiesPieces;
}


// Handles game setup
// TODO: Add difficulty and game length
void startGame() {
	srand(time(0));
;	Gameboard gameboard = createGameboard(); 
	ListOfPieces* playersPieces = (ListOfPieces*)malloc(sizeof(ListOfPieces));
	ListOfPieces* enemiesPieces = (ListOfPieces*)malloc(sizeof(ListOfPieces));

	// Returns 0 for new game and 1 for load game
	if (mainMenuStart() == 1) {
		pieceSelection(playersPieces);
		// This is where a difficulty could be added
		ePieceSelection(enemiesPieces);
	}
	else {
		// loadGameSetup(); 
	}

}