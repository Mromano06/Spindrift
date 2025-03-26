#pragma once

// Matthew Romano - March 26th, 2025 - Project Spindrift\
// Declaration for the game pice struct/functions

// has all the attributes required for a game piece
typedef struct {
	int health;
	int range;
	int baseDamage;
	int defence;
	int movement;
	int range;
	// 0 = rig, 1 = tugboat, 2 = speedboat, 3 = cargo ship
	int pieceType;

} GamePiece;

// For now I just need to create and show the pieces

// New pieces stats will be decided based on the piece type
GamePiece createGamePiece(int pieceType);

// Displays game piece for testing (and other cases)
void displayGamePiece(GamePiece toDisplay);

// Probably only used for testing
GamePiece updateGamePiece(GamePiece* toUpdate);