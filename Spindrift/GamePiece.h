#pragma once

// Matthew Romano - March 26th, 2025 - Project Spindrift\
// Declaration for the game pice struct/functions

#define NUMBER_OF_PIECES	4

// has all the attributes required for a game piece
typedef struct {
	int health;
	int range;
	int baseDamage;
	int defence;
	int movement;
	// 1 = rig, 2 = tugboat, 3 = speedboat, 4 = container ship
	int pieceType;
	// So that the gameboard knows what piece is what
	int ID;

} GamePiece;

// For now I just need to create and show the pieces

// New pieces stats will be decided based on the piece type
GamePiece createGamePiece(int pieceType);

// Displays game piece for testing (and other cases)
void displayGamePiece(GamePiece toDisplay);

// Probably only used for testing
GamePiece updateGamePiece(int hp, int rg, int bd, int df, int mv, int pt, int ID);

// When a piece attacks another
GamePiece attack(GamePiece* attackedPiece, int damageDealt);