// #include "ListOfPieces.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Implementation of the gameplay

// Add a piece to the list
ListOfPieces* addPieceToList(GamePiece toAdd) {
	ListOfPieces* newPiece = (ListOfPieces*)malloc(sizeof(ListOfPieces));
	newPiece->pieceData = toAdd; // Saves sent data
	newPiece->next = NULL;
	return newPiece;
}

// Removes specific piece from the list
void removePieceFromList(ListOfPieces** head, GamePiece toRemove) {
	if (*head == NULL) {
		printf("No pieces in the list.");
		return;
	}

	// Need both current and previous for removal
	ListOfPieces* current = *head; // head has to be a pointer
	ListOfPieces* previous = NULL;

	while (current != NULL) {
		if (comparePieces(current->pieceData, toRemove)) {
			if (previous = NULL)
				*head = current->next; // If at the start
			else
				previous->next = current->next;

			free(current); // Actually delete the data
			printf("Piece removed"); // For testing
		}

		previous = current;
		current = current->next;
	}

	printf("Piece not found");
}

// Prints the whole list
void showPiecesInList(ListOfPieces* head, GamePiece toFind) {
	ListOfPieces* current = head;

	while (current != NULL) {
		displayGamePiece(current->pieceData); // Prints current piece
		current = current->next;
	}

}