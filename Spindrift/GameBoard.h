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
Gameboard createGameBoard();

// Adds a piece at a specific position
Gameboard putPiece(Gameboard* currentBoard, int ID, int x, int y);

// Removes a piece from a specific position
Gameboard removePiece(Gameboard* currentBoard, int ID, int x, int y);