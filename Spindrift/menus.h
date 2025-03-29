#pragma once
#include "RulesAndCredits.h"

// Matthew Romano - March 24th, 2025 - Project Spindrift
// Function declarations for the menus

// Budgets have to be here for the menus
#define MAIN_MENU_OPTIONS			  5
#define SELECTION_MENU_OPTIONS		  4
#define OPTION_NAME_LENGTH			 20
#define PLAYER_BUDGET				100
#define SPEEDBOAT_COST				 10
#define TUGBOAT_COST				 20
#define CONTAINER_SHIP_COST			 40

// Makes printing the title easier 
void titleScreen();

// For style
void hideCursor();

// Starting point of the main menu
int mainMenuStart();

// Used to change selected option over and over
void mainMenu(int arrowPos);

// Allows user to select pieces
void pieceSelectionMenu(int arrowPos, int currentBudget);
