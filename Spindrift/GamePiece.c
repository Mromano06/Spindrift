#include "GamePiece.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Matthew Romano - March 26th, 2025 - Project Spindrift
// Implementation of game pieces functions

// New pieces stats will be decided based on the piece type
GamePiece createGamePiece(PieceType pieceType) {
	GamePiece newGamePiece = { 0 };
	newGamePiece.coords = setupCoordinates(-1, -1); // -1 is default
	newGamePiece.pieceType = pieceType;
	newGamePiece.ID = -1; // default ID value 

	// TODO: Needs a lot of testing/balancing
	switch (newGamePiece.pieceType) {

	case OIL_RIG:
		newGamePiece.health = 10;
		newGamePiece.range = 1;
		newGamePiece.baseDamage = 1;
		newGamePiece.defence =1;
		newGamePiece.movement = 0;
		break;

	case SPEEDBOAT:
		newGamePiece.health = 5;
		newGamePiece.range = 1;
		newGamePiece.baseDamage = 2;
		newGamePiece.defence = 2;
		newGamePiece.movement = 2;
		break;

	case TUGBOAT:
		newGamePiece.health = 3;
		newGamePiece.range = 3;
		newGamePiece.baseDamage = 4;
		newGamePiece.defence = 1;
		newGamePiece.movement = 3;
		break;

	case CONTAINER_SHIP:
		newGamePiece.health = 8;
		newGamePiece.range = 2;
		newGamePiece.baseDamage = 1;
		newGamePiece.defence = 3;
		newGamePiece.movement = 1;
		break;
	// if improper type is sent
	default:
		printf("Error creating game piece");
		exit(EXIT_FAILURE);
	}

	return newGamePiece;
}

// Displays game piece for testing (and other cases)
void displayGamePiece(GamePiece toDisplay) {
	if (toDisplay.pieceType == OIL_RIG)
		printf("Oil Rig\nHealth: %d\nDamage: %d\nDefence: %d\nRange: %d\nMovement: %d",
			toDisplay.health, toDisplay.baseDamage, toDisplay.defence, toDisplay.range,
			toDisplay.movement);

	else if (toDisplay.pieceType == SPEEDBOAT)
		printf("Tugboat\nHealth: %d\nDamage: %d\nDefence: %d\nRange: %d\nMovement: %d",
			toDisplay.health, toDisplay.baseDamage, toDisplay.defence, toDisplay.range,
			toDisplay.movement);

	else if (toDisplay.pieceType == TUGBOAT)
		printf("Speedboat\nHealth: %d\nDamage: %d\nDefence: %d\nRange: %d\nMovement: %d",
			toDisplay.health, toDisplay.baseDamage, toDisplay.defence, toDisplay.range,
			toDisplay.movement);

	else if (toDisplay.pieceType == CONTAINER_SHIP)
		printf("Container Ship\nHealth: %d\nDamage: %d\nDefence: %d\nRange: %d\nMovement: %d",
			toDisplay.health, toDisplay.baseDamage, toDisplay.defence, toDisplay.range,
			toDisplay.movement);
}

// TODO: determine if this is better here or a seperate combat function
// will take the health off of a piece that is attacked
GamePiece attack(GamePiece* attackedPiece, int damageDealt) {
	attackedPiece->health -= damageDealt;

	return *attackedPiece;
}

// Checks to see if two pieces are the same based on ID
bool comparePieces(GamePiece lhs, GamePiece rhs) {
	if (lhs.ID == rhs.ID)
		return true;

	return false;
}