#include "Gameplay.h"
#include "Gameboard.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Menus.h"

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Implementation of the gameplay

// Handles game setup
// TODO: Add difficulty and game length
void startGame() {
	srand(time(0));
;	Gameboard* gameboard = createGameboard(); 
	ListOfPieces* playersPieces = (ListOfPieces*)malloc(sizeof(ListOfPieces));
	ListOfPieces* enemiesPieces = (ListOfPieces*)malloc(sizeof(ListOfPieces));

	// Returns 0 for new game and 1 for load game
	if (mainMenuStart() == 1) {
		playersPieces = pieceSelection(playersPieces);
		enemiesPieces = randomEnemyPieceSelection(enemiesPieces);
		gameboard = placePlayersPieces(gameboard, playersPieces);

	}
	else {
		// loadGameSetup(); 
	}

}