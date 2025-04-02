#pragma once
#include "Gameboard.h"
#include "ListOfPieces.h"

// Matthew Romano - April 1st, 2025 - Project Spindrift
// Function declarations for piece placement

// Player piece placement
Gameboard* placePlayersPieces(Gameboard* gameboard, ListOfPieces* toPlace);

// Random AI piece placement
Gameboard* placeEnemiesPiecesRandomly(Gameboard* gameboard, ListOfPieces* toPlace);