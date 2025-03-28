#include "Gameplay.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Implementation of the gameplay

// Add a piece to the list
ListOfPieces* addPieceToList(GamePiece toAdd) {
	ListOfPieces* newPiece = (ListOfPieces*)malloc(sizeof(ListOfPieces));
	newPiece->pieceData = toAdd;
	newPiece->next = NULL;
	return newPiece;
}

// Finds a spcific piece in the array
ListOfPieces* findPiece(ListOfPieces* head, GamePiece toFind) {
	ListOfPieces* current = head;
	
	while (current != NULL) {
		if (comparePieces(current->pieceData, toFind))
			return current;

		current = current->next;
	}

	return NULL; // if piece is not found
}

// Handles game setup
// TODO: Add difficulty and game length
// TODO: Either decide the amount of each piece, make a linked list to store them
void startGame() {
	Gameboard gameboard = createGameboard();
	// 1 = rig, 2 = tugboat, 3 = speedboat, 4 = container ship
}