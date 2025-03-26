#include "RulesAndCredits.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Matthew Romano - March 25th, 2025 - Project Spindrift
// Functions to display the credits and rules for the game

void credits() {
	system("cls");
	printf("Credits\n\n");
	printf("Developed, produced and maintained by: Matthew Romano\n\n");
	printf("To report a bug or if you have a question about the development contact me at: matbat2205@gmail.com\n\n");
	printf("Press esc to return to the main menu");

	int keyPressed = 0;
	// waits for the user to press the esc key
	while (1) {
		int keyPressed = getch();
		switch (keyPressed) {
		case 27:
			return;
			break;
		}
	}

}

void rules() {
	system("cls");
	printf("Rules of Spindrift\n\n");
	printf("Note, for more detailed rules refer to the RULES.md file within the repository\n\n");
	printf("Players take turn attacking with and moving thier pieces. Each piece can attack or move once during a turn.\n");
	printf("Destroy all of the opponents boats or capture 5/6 of the total oil rigs to win. For a more detailed\n");
	printf("overview of each piece, please refer to the game piece section of the RULES.md file.\n\n");
	printf("To report a bug or if you have a question about the development contact me at: matbat2205@gmail.com\n\n");
	printf("Press esc to return to the main menu");

	int keyPressed = 0;
	// waits for the user to press the esc key
	while (1) {
		int keyPressed = getch();
		switch (keyPressed) {
		case 27:
			return;
			break;
		}
	}

}