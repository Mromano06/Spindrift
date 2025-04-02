#include "ScreensAndExtras.h"
#include <stdio.h>
#include <windows.h>

// Matthew Romano - April 2nd, 2025 - Project Spindrift
// FUnction bodys for the screens and extras

// Displays the games title and version
// pretty lame right now
void titleScreen() {
	printf("\n");
	printf(" SSSSS   PPPPP  III  N   N  DDDD   RRRR   IIIII  FFFFF  TTTTT\n");
	printf(" S       P   P   I   NN  N  D   D  R   R    I    F        T\n");
	printf("  SSS    PPPPP   I   N N N  D   D  RRRR     I    FFFF     T\n");
	printf("     S   P       I   N  NN  D   D  R  R     I    F        T\n");
	printf(" SSSSS   P      III  N   N  DDDD   R   R  IIIII  F        T\n");
	printf("\n\nCreated By: Matthew Romano");
	printf("\n\nPre-Alpha v0.1.1");
	Sleep(2500);
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