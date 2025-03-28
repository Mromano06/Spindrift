#pragma once
#include "Gameboard.h"
#include "GamePiece.h"

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Function declarations for the gameplay

// Linked list to hold every piece
typedef struct {
	GamePiece pieceData;
	ListOfPieces* next;
}ListOfPieces;

// Add a piece to the list
ListOfPieces* addPieceToList(GamePiece toAdd);

// Finds a specific piece
ListOfPieces* findPiece(ListOfPieces* head, GamePiece toFind);

// Sets up the game
void startGame();