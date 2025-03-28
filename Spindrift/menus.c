#include "Menus.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Matthew Romano - March 24th, 2025 - Project Spindrift
// Menus module implementation using conio.h

// pretty lame right now
void titleScreen() {
		printf("\n");
		printf(" SSSSS   PPPPP  III  N   N  DDDD   RRRR   IIIII  FFFFF  TTTTT\n");
		printf(" S       P   P   I   NN  N  D   D  R   R    I    F        T\n");
		printf("  SSS    PPPPP   I   N N N  D   D  RRRR     I    FFFF     T\n");
		printf("     S   P       I   N  NN  D   D  R  R     I    F        T\n");
		printf(" SSSSS   P      III  N   N  DDDD   R   R  IIIII  F        T\n");
		printf("\n\nCreated By: Matthew Romano");
		Sleep(3500);
}

// starts the main menu and works as a hub for it
int mainMenuStart() {
	int arrowPos = 1;

	// prints the title and waits for a couple secs before clearing
	titleScreen();

	// clears window and calls menu for the first time
	system("cls");
	mainMenu(arrowPos);

	// infinite loop for now
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
	system("cls");
	printf("Main Menu\n\n");

	// saves all menu options as an array of strings
	char options[][OPTION_NAME_LENGTH] = { "New Game",
		"Load Game", "Rules", "Credits", "Exit" };

	// prints out menu options 1 by 1
	for (int i = 0; i < MAIN_MENU_OPTIONS; i++) {
		if (arrowPos == i + 1)  // print arrow if at that position
			printf("--> %s\n", options[i]);

		else
			printf("    %s\n", options[i]);
	}

	printf("\n"); // for better formatting

}

// Menu for player piece selection
void pieceSelectionMenu(int arrowPos) {
	// 1 = rig, 2 = tugboat, 3 = speedboat, 4 = container ship
	system("cls");
	printf("Ship Selection Menu\n\n");

	// saves all menu options as an array of strings
	char options[][OPTION_NAME_LENGTH] = { "Speedboat",
		"Tugboat", "Container ship" };

	// prints out menu options 1 by 1
	for (int i = 0; i < SELECTION_MENU_OPTIONS; i++) {
		if (arrowPos == i + 1)  // print arrow if at that position
			printf("--> %s\n", options[i]);

		else
			printf("    %s\n", options[i]);
	}

	printf("\n"); // for better formatting
}