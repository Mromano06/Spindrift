#include "Gameboard.h"
#include <stdio.h>

// Matthew Romano - March 26th, 2025 - Project Spindrift
// Implementation of the game board and its functions

// Gameboard setup
Gameboard createGameboard() {
	// The gameboard is a 2d array of ints that will hold values coresponding to the gampieces
	Gameboard newBoard;
	// sets all values of the array to 0 to start
	for (int i = 0; i < BOARD_LENGTH; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++)
			newBoard.board[i][j] = 0;	
	}

	return newBoard;
}

// Sets the gameBoard to hold the gamepiece's ID at a position
Gameboard putPiece(Gameboard* currentBoard, int ID, int x, int y) {
	// Sets the ID to a certain position
	if (currentBoard->board[x][y] == 0) 
		currentBoard->board[x][y] = ID;
	else
		printf("Piece cannot be put here.");

	return *currentBoard;
}

// Removes specific piece from the board at certain position
Gameboard removePiece(Gameboard* currentBoard, int ID, int x, int y) {
	// Searches the board to find the id of the piece and removes it
	if (currentBoard->board[x][y] == ID)
		currentBoard->board[x][y] = 0;
	else
		printf("Unable to remove piece.");

	return *currentBoard;
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