#include "menus.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Matthew Romano - March 24th, 2025 - Project Spindrift
// Menus module implementation using conio.h

#define MENU_OPTIONS			5
#define OPTION_NAME_LENGTH		10

// pretty lame right now
void titleScreen() {
		printf("\n");
		printf(" SSSSS   PPPPP  III  N   N  DDDD   RRRR   IIIII  FFFFF  TTTTT\n");
		printf(" S       P   P   I   NN  N  D   D  R   R    I    F        T\n");
		printf("  SSS    PPPPP   I   N N N  D   D  RRRR     I    FFFF     T\n");
		printf("     S   P       I   N  NN  D   D  R  R     I    F        T\n");
		printf(" SSSSS   P      III  N   N  DDDD   R   R  IIIII  F        T\n");
		printf("\n\nCreated By: Matthew Romano");
		Sleep(5000);
}

// starts the main menu and works as a hub for it
void mainMenuStart() {
	int arrowPos = 1;

	// prints the title and waits for a couple secs beofre clearing
	titleScreen();

	// clears window and calls menu for the first time
	system("cls");
	mainMenu(arrowPos);

	// infinite loop for now
	while (1) {
		int keyPressed = getch(); // takes input
		switch (keyPressed) {
		case 27: // escape key
			exit(EXIT_SUCCESS);
			break;

		case 72: // up arrow
			if (arrowPos == 1) // loops back around
				arrowPos = MENU_OPTIONS + 1;
			mainMenu(--arrowPos);
			break;

		case 80: // down arrow
			if (arrowPos == 5) // loops back around also
				arrowPos = 0;
			mainMenu(++arrowPos);
			break;

		}
	}
}

// this is seperate so that the user can scroll though menu options
void mainMenu(int arrowPos) {
	system("cls");

	// saves all menu options as an array of strings
	char options[][OPTION_NAME_LENGTH] = { "New Game",
		"Load Game", "Rules", "Credits", "Exit" };

	// prints out menu options 1 by 1
	for (int i = 0; i < MENU_OPTIONS; i++) {
		if (arrowPos == i + 1)  // print arrow if at that position
			printf("--> %s\n", options[i]);

		else
			printf("    %s\n", options[i]);
	}

}