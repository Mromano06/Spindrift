#pragma once

// Matthew Romano - March 31st, 2025 - Project Spindrift
// Declaration for coordinate struct and functions

// Default for both is -1
typedef struct {
	int x;
	int y;
} Coordinates;

// Sets a pieces coordinates
Coordinates setupCoordinates(int x, int y);