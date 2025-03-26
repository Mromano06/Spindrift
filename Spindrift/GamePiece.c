#include "GamePiece.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - March 26th, 2025 - Project Spindrift
// Implementation of game pieces functions

// New pieces stats will be decided based on the piece type
GamePiece createGamePiece(int pieceType) {
	GamePiece newGamePiece = { 0 };
	newGamePiece.pieceType = pieceType;

	// TODO: Needs a lot of testing/balancing
	switch (newGamePiece.pieceType) {
	// oil rig
	case 1:
		newGamePiece.health = 10;
		newGamePiece.range = 1;
		newGamePiece.baseDamage = 1;
		newGamePiece.defence =1;
		newGamePiece.movement = 0;
		break;
	// tugboat
	case 2:
		newGamePiece.health = 5;
		newGamePiece.range = 1;
		newGamePiece.baseDamage = 2;
		newGamePiece.defence = 2;
		newGamePiece.movement = 2;
		break;
	// speedboat
	case 3:
		newGamePiece.health = 3;
		newGamePiece.range = 3;
		newGamePiece.baseDamage = 4;
		newGamePiece.defence = 1;
		newGamePiece.movement = 3;
		break;
	// container ship
	case 4:
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
	// Oil Rig
	if (toDisplay.pieceType == 0)
		printf("Oil Rig\nHealth: %d\nDamage: %d\nDefence: %d\nRange: %d\nMovement: %d",
			toDisplay.health, toDisplay.baseDamage, toDisplay.defence, toDisplay.range,
			toDisplay.movement);

	// Tugboat
	else if (toDisplay.pieceType == 1)
		printf("Tugboat\nHealth: %d\nDamage: %d\nDefence: %d\nRange: %d\nMovement: %d",
			toDisplay.health, toDisplay.baseDamage, toDisplay.defence, toDisplay.range,
			toDisplay.movement);

	// Speedboat
	else if (toDisplay.pieceType == 2)
		printf("Speedboat\nHealth: %d\nDamage: %d\nDefence: %d\nRange: %d\nMovement: %d",
			toDisplay.health, toDisplay.baseDamage, toDisplay.defence, toDisplay.range,
			toDisplay.movement);

	// Container Ship
	else if (toDisplay.pieceType == 3)
		printf("Container Ship\nHealth: %d\nDamage: %d\nDefence: %d\nRange: %d\nMovement: %d",
			toDisplay.health, toDisplay.baseDamage, toDisplay.defence, toDisplay.range,
			toDisplay.movement);
}

// Sets all these values to a game piece
GamePiece updateGamePiece(int hp, int rg, int bd, int df, int mv, int pt) {
	GamePiece updatedPiece;

	updatedPiece.health = hp;
	updatedPiece.range = rg;
	updatedPiece.baseDamage = bd;
	updatedPiece.defence = df;
	updatedPiece.movement = mv;
	updatedPiece.pieceType = pt;

	if (pt > NUMBER_OF_PIECES || pt < 1) {
		printf("Error, invalid piece type");
		exit(EXIT_FAILURE); // for now this is all that can really be done
	}

	return updatedPiece;
}

// will take the health off of a pice that is attacked
GamePiece attack(GamePiece* attackedPiece, int damageDealt) {
	attackedPiece->health -= damageDealt;

	return *attackedPiece;
}
