#pragma once
#include "GamePiece.h"

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Function declarations for the gameplay

// Linked list to hold every piece
typedef struct ListOfPieces {
	GamePiece pieceData;
	struct ListOfPieces* next;
} ListOfPieces;

// Add a piece to the list
ListOfPieces* addPieceToList(GamePiece toAdd);

// Removes a piece from the list
void removePieceFromList(ListOfPieces** head, GamePiece toRemove);

// Returns the number of pieces
int getNumberOfPieces(ListOfPieces* head);

// Prints out all pieces
void showPiecesInList(ListOfPieces* head, GamePiece toFind);