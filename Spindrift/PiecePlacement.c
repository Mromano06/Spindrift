#include "PiecePlacement.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Menus.h"

// TODO: Get coordinates of requested piece placement
// Allows the players to place their pieces
Gameboard* placePlayersPieces(Gameboard* gameboard, ListOfPieces* toPlace) {
	ListOfPieces* current = toPlace;
	Coordinates inputCoords = setupCoordinates(0, 0);

	while (toPlace != NULL) {
		Coordinates selectedCoords = piecePlacementMenu(gameboard, inputCoords);
		if (isSpotFree(gameboard, selectedCoords) && isValidStartingPlacement(selectedCoords)) {
			current->pieceData.coords = selectedCoords;
			gameboard = placePiece(gameboard, current->pieceData);
			current = toPlace->next;
		}
		else {
			printf("\n\nThis spot is taken or invalid.");
			Sleep(750);
			printf("\33[2K\r");
		}
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