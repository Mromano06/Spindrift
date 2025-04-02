#pragma once
#include "Gameboard.h"
#include "ListOfPieces.h"

// Matthew Romano - April 1st, 2025 - Project Spindrift
// Function declarations for selection

// Player piece selection
ListOfPieces* pieceSelection(ListOfPieces* playersPieces);

// Random AI piece placement
ListOfPieces* randomEnemyPieceSelection(ListOfPieces* enemiesPieces);