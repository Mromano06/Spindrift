#include "PieceSelection.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Menus.h"

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Implementation of the piece selection

// Player will chose there pieces here
ListOfPieces* pieceSelection(ListOfPieces* playersPieces) {
	int currentID = PLAYER_PIECE_ID_MODIFIER;
	int currentBudget = PIECE_BUDGET;
	int arrowPos = 1; // Starts at top of the menu
	GamePiece temp; // Needed to set ID

	// Creates the oil rigs before anything else
	for (int i = 0; i < MAX_RIGS; i++) {
		temp = createGamePiece(1); // 1 for rig
		temp.ID = PLAYER_RIG_ID_MODIFIER + i;
		playersPieces = addPieceToList(temp);
	}

	system("cls");
	pieceSelectionMenu(arrowPos, currentBudget);

	// 1 = rig, 2 = tugboat, 3 = speedboat, 4 = container ship
	while (1) {
		int keyPressed = getch(); // takes input
		switch (keyPressed) {

		case 13: // enter key
			if (arrowPos == 1 && currentBudget >= SPEEDBOAT_COST) {
				temp = createGamePiece(SPEEDBOAT);
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
				temp = createGamePiece(TUGBOAT);
				temp.ID = currentID;
				playersPieces = addPieceToList(temp);
				currentBudget -= TUGBOAT_COST;
				currentID++;
				printf("\n\nTugboat selected");
				Sleep(750);
			}
			else if (arrowPos == 2 && currentBudget < TUGBOAT_COST) {
				printf("\n\nYou cannot afford this piece");
				Sleep(750);
			}

			if (arrowPos == 3 && currentBudget >= CONTAINER_SHIP_COST) {
				temp = createGamePiece(CONTAINER_SHIP);
				temp.ID = currentID;
				playersPieces = addPieceToList(temp);
				currentBudget -= CONTAINER_SHIP_COST;
				currentID++;
				printf("\n\nContainer ship selected");
				Sleep(750);
			}
			else if (arrowPos == 3 && currentBudget < CONTAINER_SHIP_COST) {
				printf("\n\nYou cannot afford this piece");
				Sleep(750);
			}

			if (arrowPos == 4) {
				if (currentBudget == PIECE_BUDGET) { // Makes sure 1 piece is selected
					printf("\n\nPlease select at least 1 piece");
					Sleep(750);
				}
				else {
					printf("\n\nPiece selection confirmed");
					Sleep(750);
					return playersPieces;
				}
			}

			pieceSelectionMenu(arrowPos, currentBudget);
			break;

		case 27: // escape key quits
			if (currentBudget == PIECE_BUDGET) { // Makes sure 1 piece is selected
				printf("\n\nPlease select at least 1 piece");
				Sleep(750);
				pieceSelectionMenu(arrowPos, currentBudget);
				break;
			}
			else {
				printf("Piece selection confirmed");
				Sleep(750);
				return playersPieces;
				break;
			}

		case 72: // up arrow
			if (arrowPos == 1)						// loops back around
				arrowPos = SELECTION_MENU_OPTIONS + 1;
			pieceSelectionMenu(--arrowPos, currentBudget);
			break;

		case 80: // down arrow
			if (arrowPos == SELECTION_MENU_OPTIONS) // ditto ^
				arrowPos = 0;
			pieceSelectionMenu(++arrowPos, currentBudget);
			break;

		}

	}

	return NULL; // Dont need this but just in case
}

// Random AI piece selection
ListOfPieces* randomEnemyPieceSelection(ListOfPieces* enemiesPieces) {
	int currentID = ENEMY_PIECE_ID_MODIFIER;
	int currentBudget = PIECE_BUDGET;
	int selection = 0;
	GamePiece temp; // So ID can be incremented

	// Creates the oil rigs before anything else
	for (int i = 0; i < MAX_RIGS; i++) {
		temp = createGamePiece(OIL_RIG);
		temp.ID = ENEMY_RIG_ID_MODIFIER + i;
		enemiesPieces = addPieceToList(temp);
	}

	while (currentBudget > 0) {
		selection = (rand() % (NUMBER_OF_PIECES)) + 2;

		if (selection == SPEEDBOAT && currentBudget >= SPEEDBOAT_COST) {
			temp = createGamePiece(SPEEDBOAT);
			temp.ID = currentID;
			enemiesPieces = addPieceToList(temp);
			currentBudget -= SPEEDBOAT_COST;
			currentID++;
		}

		if (selection == TUGBOAT && currentBudget >= TUGBOAT_COST) {
			temp = createGamePiece(TUGBOAT);
			temp.ID = currentID;
			enemiesPieces = addPieceToList(temp);
			currentBudget -= TUGBOAT_COST;
			currentID++;
		}

		if (selection == CONTAINER_SHIP && currentBudget >= CONTAINER_SHIP_COST) {
			temp = createGamePiece(CONTAINER_SHIP);
			temp.ID = currentID;
			enemiesPieces = addPieceToList(temp);
			currentBudget -= CONTAINER_SHIP_COST;
			currentID++;
		}
	}

	return enemiesPieces;
}