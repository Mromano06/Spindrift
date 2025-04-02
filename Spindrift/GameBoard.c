#include "Gameboard.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - March 26th, 2025 - Project Spindrift
// Implementation of the game board and its functions

// Gameboard setup
Gameboard* createGameboard() {
	Gameboard* newBoard = (Gameboard*)malloc(sizeof(Gameboard));

	if (newBoard == NULL) {
		printf("Error allocating memory for gameboard.\n");
		exit(EXIT_FAILURE);
	}

	// sets all values of the array to 0 to start
	for (int i = 0; i < BOARD_LENGTH; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++)
			newBoard->board[i][j] = 0;	
	}

	return newBoard;
}

// Sets the gameBoard to hold the gamepiece's ID at a position
Gameboard* placePiece(Gameboard* currentBoard, GamePiece toPlace) {
	if (currentBoard->board[toPlace.coords.x][toPlace.coords.y] == 0)
		currentBoard->board[toPlace.coords.x][toPlace.coords.y] = toPlace.ID;
	else
		printf("\n\nPiece cannot be put here.");

	return currentBoard;
}

// Removes specific piece from the board at certain position
Gameboard* removePiece(Gameboard* currentBoard, GamePiece toPlace) {
	// Searches the board to find the id of the piece and removes it
	if (currentBoard->board[toPlace.coords.x][toPlace.coords.y] == toPlace.ID)
		currentBoard->board[toPlace.coords.x][toPlace.coords.y] = 0;
	else
		printf("\n\nUnable to remove piece.");

	return currentBoard;
}

// Takes a coordinate and the gameboard to compare
bool isSpotFree(Gameboard* gameboard, Coordinates toCheck) {
	if (gameboard->board[toCheck.x][toCheck.y] == 0)
		return true;

	return false;
}

// Checks if the coordinates are valid starting locations for the player
bool isValidStartingPlacement(Coordinates inputCoords) {
	// Compares x and y coordinates to the upper and lower limits allowed
	if (inputCoords.x >= P_START_X_LOW_LIMIT && inputCoords.x <= P_START_X_UP_LIMIT) {
		if (inputCoords.y >= P_START_Y_LOW_LIMIT && inputCoords.y <= P_START_Y_UP_LIMIT)
			return true;
	}
	
	return false;
}

// Compares sent coordinate to the upper/lower limits of the valid start area
bool isValidEnemyStartingPlacement(Coordinates inputCoords) {
	if (inputCoords.x >= E_START_X_LOW_LIMIT && inputCoords.x <= E_START_X_UP_LIMIT) {
		if (inputCoords.y >= E_START_Y_LOW_LIMIT && inputCoords.y <=E_START_Y_UP_LIMIT)
			return true;
	}

	return false;
}

// Prints out the game board's elements
void displayGameboard(Gameboard toDisplay) {
	for (int i = 0; i < BOARD_LENGTH*3; i++)
		printf("~");

	printf("\n");
	for (int i = 0; i < BOARD_LENGTH; i++) {
		printf("|");
		for (int j = 0; j < BOARD_WIDTH; j++) {
			printf("%d", toDisplay.board[i][j]);
			if (j == BOARD_WIDTH - 1)
				printf("|");
			else
				printf("  ");
		}
			printf("\n");
	}

	for (int i = 0; i < BOARD_LENGTH * 3; i++)
		printf("~");
	
}

// Finds pieces x coordinate
int getXofPiece(Gameboard* currentBoard, int ID) {
	int x;

	// Searches the board to find the x of a piece
	for (int i = 0; i < BOARD_LENGTH; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++)
			if (currentBoard->board[i][j] == ID)
				return (x = i);	
	}

	return -1; // no x is found
}

// Finds pieces x coordinate
int getYofPiece(Gameboard* currentBoard, int ID) {
	int y;

	// Searches the board to find the y of a piece
	for (int i = 0; i < BOARD_LENGTH; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++)
			if (currentBoard->board[i][j] == ID)
				return (y = j);
	}

	return -1; // no x is found
}