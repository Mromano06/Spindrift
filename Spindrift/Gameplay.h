#pragma once
#include "Gameboard.h"
#include "GamePiece.h"
#include "ListOfPieces.h"
#include "Menus.h"

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Function declarations for the gameplay

// Player choses pieces
ListOfPieces* pieceSelection(ListOfPieces* playersPieces);

// Sets up the game
void startGame();