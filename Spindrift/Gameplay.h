#pragma once
#include "Gameboard.h"
#include "GamePiece.h"
#include "ListOfPieces.h"
#include "Menus.h"

// Matthew Romano - March 27th, 2025 - Project Spindrift
// Function declarations for the gameplay

#define PLAYER_BUDGET			100
#define SPEEDBOAT_COST			 10
#define TUGBOAT_COST			 20
#define CONTAINER_SHIP_COST		 40

// Player choses pieces
ListOfPieces* pieceSelection(ListOfPieces* playersPieces);

// Sets up the game
void startGame();