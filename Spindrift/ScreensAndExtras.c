#include "ScreensAndExtras.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

// Matthew Romano - April 2nd, 2025 - Project Spindrift
// FUnction bodys for the screens and extras

// Displays the games title and version
// pretty lame right now
void titleScreen() {
	printf("\n");
	printf("      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	printf("          #####  ######  ######  ####    ##  ######   ######   ######  ######  ######    \n");
	printf("         ##      ##  ##    ##    ## ##   ##  ##   ##  ##   ##    ##    ##        ##      \n");
	printf("          ####   ######    ##    ##  ##  ##  ##   ##  ######     ##    ######    ##      \n");
	printf("             ##  ##        ##    ##   ## ##  ##   ##  ##   ##    ##    ##        ##      \n");
	printf("         #####   ##      ######  ##    ####  ######   ##   ##  ######  ##        ##      \n");
	printf("      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("           ~~~~~~~~    ~~~~   ~~~~    ~~~~~~~~    ~~~~~~~~    ~~~~   ~~~~    ~~~~~~~~    \n"); 
	printf("               ~~~~~  ~~~~  ~~~~  ~~~~  ~~~~  ~~~~   ~~~~~  ~~~~  ~~~~  ~~~~  ~~~~       \n");
	printf("                   ~~~~  ~~~~  ~~~~  ~~~~  ~~~~  ~~  ~~~~  ~~~~  ~~~~  ~~~~  ~~          \n");
	printf("                       ~~ ~~  ~~~~  ~~~~  ~~~~  ~~~~  ~~ ~~ ~~~~  ~~~~  ~~~~             \n");
	printf("                           ~~~~ ~~  ~~~~ ~~~~  ~~~~ ~~  ~~~~  ~~~~ ~~                    \n");
	printf("                                  ~~  ~~~~  ~~~~  ~~~~ ~~  ~~~~                          \n");
	printf("                                      ~~~~  ~~~~  ~~  ~~                                 \n");
	printf("\n\nPress ENTER to start...");
	printf("\n\n\n\n\n\n\n\nCreated By: Matthew Romano");
	printf("\n\nPre-Alpha v0.1.1");

	while (1) {
		int enterPressed = getch();
		switch (enterPressed) {
		case 13:
			return;
			break;
		}
	}
}

// Hides the cursor for a better look
void hideCursor() {
	// Gets handle of the console
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Create a cursor info struct and hide it
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;

	// Send the settings to the system
	SetConsoleCursorInfo(handle, &cursorInfo);

}

// Sets cursors position, used for menus
void setCursorPosition(Coordinates cursorPosition) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos = { cursorPosition.x , cursorPosition.y };
	SetConsoleCursorPosition(consoleHandle, cursorPos);
}