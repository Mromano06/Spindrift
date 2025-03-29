#include "Gameplay.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Implementation of the gameplay

// Setups new game (void for now)
void newGameSetup() {

}

// Sets up a loaded game
void loadGameSetup() {

}

// Player will chose there pieces here
void playerPieceSelection() {

}
// Handles game setup
// TODO: Add difficulty and game length
void startGame() {
	// Returns 0 for new game and 1 for load game
	if (mainMenuStart() == 1) {
		// newGameSetup();
	}
	else {
		// loadGameSetup(); 
	}

	Gameboard gameboard = createGameboard();
	// 1 = rig, 2 = tugboat, 3 = speedboat, 4 = container ship
}