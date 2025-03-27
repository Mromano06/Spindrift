#pragma once

// Matthew Romano - March 24th, 2025 - Project Spindrift
// Function declarations for the menus

#define MENU_OPTIONS			5
#define OPTION_NAME_LENGTH		10

// makes printing the title easier 
void titleScreen();

// starting point of the main menu
void mainMenuStart();

// used to change selected option over and over
void mainMenu(int arrowPos);