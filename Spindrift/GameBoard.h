#pragma once
#include "GamePiece.h"

// Matthew Romano - March 26th, 2025 - Project Spindrift
// Implementation of the game board and its functions

#define BOARD_LENGTH			20
#define BOARD_WIDTH				20

#define P_START_X_LOW_LIMIT		 0
#define P_START_X_UP_LIMIT		 6
#define P_START_Y_LOW_LIMIT		 4
#define P_START_Y_UP_LIMIT		15

#define E_START_X_LOW_LIMIT		15
#define E_START_X_UP_LIMIT		19
#define E_START_Y_LOW_LIMIT		 4
#define E_START_Y_UP_LIMIT		15

typedef struct {
	// this is to keep track of pieces
	int board[BOARD_LENGTH][BOARD_WIDTH];
} Gameboard;

// Game board setup
Gameboard* createGameboard();

// Adds a piece at a specific position
Gameboard* placePiece(Gameboard* currentBoard, GamePiece toPlace);

// Removes a piece based on its ID
Gameboard* removePiece(Gameboard* currentBoard, GamePiece toPlace);

// Checks to see if a spot on the board is free
bool isSpotFree(Gameboard* gameboard, Coordinates toCheck);

// Checks if the coordinate is a valid start placement
bool isValidStartingPlacement(Coordinates inputCoords);

// Checks to see if enemy piece placement is valid
bool isValidEnemyStartingPlacement(Coordinates inputCoords);

// Shows the gameboard
void displayGameboard(Gameboard toDisplay);

// Shows cursor on gameboard
void displayGameboardWithCursor(Gameboard* gameboard, Coordinates cursorPos);

// Finds the x coordinate of a piece
int getXofPiece(Gameboard* currentBoard, int ID);

// Finds the y coordinate of a piece
int getYofPiece(Gameboard* currentBoard, int ID);

