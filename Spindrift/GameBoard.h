#pragma once
#include "GamePiece.h"

// Matthew Romano - March 26th, 2025 - Project Spindrift
// Implementation of the game board and its functions

#define BOARD_LENGTH	20
#define BOARD_WIDTH		20

typedef struct {
	// this is to keep track of pieces
	int board[BOARD_LENGTH][BOARD_WIDTH];

} Gameboard;

// Game board setup
Gameboard createGameboard();

// Adds a piece at a specific position
Gameboard* placePiece(Gameboard* currentBoard, int ID, int x, int y);

// Removes a piece based on its ID
Gameboard* removePiece(Gameboard* currentBoard, int ID, int x, int y);

// Checks to see if a spot on the board is free
bool isSpotFree(Gameboard gameboard, Coordinates toCheck);

// Shows the gameboard
void displayGameboard(Gameboard toDisplay);

// Finds the x coordinate of a piece
int getXofPiece(Gameboard* currentBoard, int ID);

// Finds the y coordinate of a piece
int getYofPiece(Gameboard* currentBoard, int ID);

