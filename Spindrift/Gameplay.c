#include "Gameboard.h"
#include "GamePiece.h"
#include <stdio.h>

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Implementation of the gameplay

// Handles game setup
// TODO: Add difficulty and game length
// TODO: Either decide the amount of each piece, make a linked list to store them
void startGame() {
	Gameboard gameboard = createGameboard();

	// 1 = rig, 2 = tugboat, 3 = speedboat, 4 = container ship
	GamePiece pRig = createGamePiece(1), pTugboat = createGamePiece(2),
		pSpeedboat = createGamePiece(3), pConShip = createGamePiece(4),
			  eRig = createGamePiece(1), eTugboat = createGamePiece(2),
		eSpeedboat = createGamePiece(3), eConShip = createGamePiece(4);

}

