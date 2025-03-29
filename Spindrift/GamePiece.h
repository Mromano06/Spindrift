#pragma once
#include <stdbool.h>

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
	// ID for players pieces (11-21), enemies pieces (0-10)
	int ID;

} GamePiece;

// New pieces stats will be decided based on the piece type
GamePiece createGamePiece(int pieceType);

// Displays game piece for testing (and other cases)
void displayGamePiece(GamePiece toDisplay);

// When a piece attacks another
GamePiece attack(GamePiece* attackedPiece, int damageDealt);

// Compares two pieces
bool comparePieces(GamePiece lhs, GamePiece rhs);
