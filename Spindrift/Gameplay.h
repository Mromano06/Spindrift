#pragma once
#include "ListOfPieces.h"

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Function declarations for the gameplay

// Player choses pieces
ListOfPieces* pieceSelection(ListOfPieces* playersPieces);

// Choses enemies pieces
ListOfPieces* enemyPieceSelection(ListOfPieces* enemiesPieces);

// Sets up the game
void startGame();