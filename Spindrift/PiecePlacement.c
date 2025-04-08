#include "PiecePlacement.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: Get coordinates of requested piece placement
// Allows the players to place their pieces
// 75 for left, 77 for right, 72 for up, 80 for down, 27 for esc, 13 for enter
Gameboard* placePlayersPieces(Gameboard* gameboard, ListOfPieces* toPlace) {
	int x = 0, y = 0;
	ListOfPieces* current = toPlace;
	Coordinates inputCoords = setupCoordinates(x, y);

	while (toPlace != NULL) {
		piecePlacementMenu(gameboard, inputCoords);
		if (isSpotFree(gameboard, inputCoords) && isValidStartingPlacement(inputCoords)) {
			current->pieceData.coords = inputCoords;
			gameboard = placePiece(gameboard, current->pieceData);
			current = toPlace->next;
		}
		else
			printf("\n\nThis spot is taken or invalid.");

	}

	return gameboard;
}

// Places the AI's pieces randomly
Gameboard* placeEnemiesPiecesRandomly(Gameboard* gameboard, ListOfPieces* toPlace) {
	int x = -1, y = -1;
	ListOfPieces* current = toPlace;
	Coordinates inputCoords = setupCoordinates(x, y);

	while (toPlace != NULL) {
		// Shouldn't have to check validity of the genoration but more readable this way
		inputCoords.x = rand() % (E_START_X_UP_LIMIT - E_START_X_LOW_LIMIT + 1) + E_START_X_LOW_LIMIT;
		inputCoords.y = rand() % (E_START_Y_UP_LIMIT - E_START_Y_LOW_LIMIT + 1) + E_START_Y_LOW_LIMIT;
		if (isSpotFree(gameboard, inputCoords) && isValidEnemyStartingPlacement(inputCoords)) {
			current->pieceData.coords = inputCoords;
			gameboard = placePiece(gameboard, current->pieceData);
			current = toPlace->next;
		}

	}

	return gameboard;
}
