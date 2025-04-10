#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Menus.h"

// Matthew Romano - March 24th, 2025 - Project Spindrift
// Menus module implementation using conio.h

// starts the main menu and works as a hub for it
int mainMenuStart() {
	int arrowPos = 1;

	hideCursor();
	titleScreen();
	system("cls");
	mainMenu(arrowPos);

	while (1) {
		int keyPressed = getch(); // takes input
		switch (keyPressed) {

		case 13: // enter key allows for selection
			if (arrowPos == 1)
				return arrowPos; // 1 for new game
			if (arrowPos == 2)
				return arrowPos; // 2 for load game
			if (arrowPos == 3)
				rules();
			if (arrowPos == 4)
				credits();
			if (arrowPos == 5)
				exit(EXIT_SUCCESS);
			mainMenu(arrowPos);
			break;

		case 27: // escape key quits
			exit(EXIT_SUCCESS);
			break;

		case 72: // up arrow
			if (arrowPos == 1) // loops back around
				arrowPos = MAIN_MENU_OPTIONS + 1;
			mainMenu(--arrowPos);
			break;

		case 80: // down arrow
			if (arrowPos == MAIN_MENU_OPTIONS) // loops back around
				arrowPos = 0;
			mainMenu(++arrowPos);
			break;

		}
	}
}

// this is seperate so that the user can scroll though menu options
void mainMenu(int arrowPos) {
	Coordinates cursorPosition = setupCoordinates(0, 0);
	setCursorPosition(cursorPosition);
	printf("Main Menu\n\n");

	char options[][OPTION_NAME_LENGTH] = { "New Game",
		"Load Game", "Rules", "Credits", "Exit" };

	for (int i = 0; i < MAIN_MENU_OPTIONS; i++) {
		if (arrowPos == i + 1)  // print arrow if at that position
			printf("--> %s\n", options[i]);

		else
			printf("    %s\n", options[i]);
	}

	printf("\n"); // for better formatting

}

// Menu for player piece selection
void pieceSelectionMenu(int arrowPos, int currentBudget) {
	Coordinates cursorPosition = setupCoordinates(0, 0);
	setCursorPosition(cursorPosition);
	printf("Ship Selection Menu\n\n");
	printf("\33[2K\r"); // Clears the next line (required)
	printf("Remaining Budget: %d\n\n", currentBudget);

	char options[][OPTION_NAME_LENGTH] = { "Speedboat",
		"Tugboat", "Container", "Finish Seletion" };

	// prints out menu options 1 by 1
	for (int i = 0; i < SELECTION_MENU_OPTIONS; i++) {
		if (arrowPos == i + 1)  // print arrow if at that position
			printf("--> %s", options[i]);
		else
			printf("    %s", options[i]);

		// shows the cost with the ships
		if (i == 0)
			printf("     %d", SPEEDBOAT_COST);
		else if (i == 1)
			printf("       %d", TUGBOAT_COST);
		else if (i == 2) {
			printf("     %d", CONTAINER_SHIP_COST);
			printf("\n"); // For better seperation
		}

		printf("\n");

	}

	printf("\n\33[2K\r");// Clears message
}

// 75 for left, 77 for right, 72 for up, 80 for down, 27 for esc, 13 for enter
// Places the pieces on the gameboard
Coordinates piecePlacementMenu(Gameboard* gameboard, Coordinates cursorPos) {
	displayGameboardWithCursor(gameboard, cursorPos);

	while (1) {
		int keyPressed = getch(); // takes input
		switch (keyPressed) {

		case 13: // enter key
				return cursorPos;
			break;

		// These are all backwards but working
		case 80:
			if (cursorPos.x < BOARD_LENGTH - 1)
				cursorPos.x++;
			displayGameboardWithCursor(gameboard, cursorPos);
			break;

		case 72:
			if (cursorPos.x > 0)
				cursorPos.x--;
			displayGameboardWithCursor(gameboard, cursorPos);
			break;
		
		case 75:
			if (cursorPos.y > 0)
				cursorPos.y--;
			displayGameboardWithCursor(gameboard, cursorPos);
			break;

		case 77:
			if (cursorPos.y < BOARD_WIDTH - 1)
				cursorPos.y++;
			displayGameboardWithCursor(gameboard, cursorPos);
			break;
		}
	}

	return cursorPos;
}