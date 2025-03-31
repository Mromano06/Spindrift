#include "Coordinates.h"
#include <stdio.h>

// Matthew Romano - March 31st, 2025 - Project Spindrift
// Declaration for coordinate struct and functions

// Sets a pieces coordinates to the passed x and y
Coordinates setupCoordinates(int x, int y) {
	Coordinates newCoordinates;

	newCoordinates.x = x;
	newCoordinates.y = y;

	return newCoordinates;
}