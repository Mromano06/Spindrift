#pragma once
#include "Gameboard.h"
#include "ListOfPieces.h"

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Function declarations for the gameplay

// Player choses pieces
ListOfPieces* pieceSelection(ListOfPieces* playersPieces);

// Choses enemies pieces
ListOfPieces* enemyPieceSelection(ListOfPieces* enemiesPieces);

// Player piece placement
Gameboard placePlayersPieces(Gameboard gameboard, ListOfPieces* toPlace);

// AI piece placement
Gameboard placeEnemiesPieces(Gameboard gameboard, ListOfPieces* toPlace);

// Sets up the game
void startGame();