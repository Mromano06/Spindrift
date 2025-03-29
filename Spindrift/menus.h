#pragma once
#include "RulesAndCredits.h"

// Matthew Romano - March 24th, 2025 - Project Spindrift
// Function declarations for the menus

#define MAIN_MENU_OPTIONS			  5
#define SELECTION_MENU_OPTIONS		  3
#define OPTION_NAME_LENGTH			 15

// Makes printing the title easier 
void titleScreen();

// Starting point of the main menu
int mainMenuStart();

// Used to change selected option over and over
void mainMenu(int arrowPos);

// Allows user to select pieces
void pieceSelectionMenu(int arrowPos);
