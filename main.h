#ifndef _MAIN_H_
#define _MAIN_H_
#include <iostream>
#include "SURGE.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// Define the Initialization function
bool init() {
	
	// Initialize all SDL Subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return false;

	// This defines the window
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

	// Check to Make Sure the Window initialized
	if (screen == NULL)
		return false;

	// Initialize SDL_TTF
	if ( TTF_Init() == -1)
		return false;

	// Caption
	SDL_WM_SetCaption("TTF_Test", NULL);

	// If All Went Well
	return true;
}

#endif
