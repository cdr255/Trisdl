#ifndef _MAIN_H_
#define _MAIN_H_
#include <iostream>
#include "SURGE.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;


// Two Screens: One for an image (background), one
// for a message (message). Initialized these POINTERS to 
// NULL, just to be safe.
SDL_Surface * background = NULL;
SDL_Surface * msg = NULL;
SDL_Surface * message = NULL;



// Define the Initialization function
bool SURGE_init() {
	
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

// Define the Loading Function
bool SURGE_load() {

	// Load the Images
	background = lf_load_image( "bg.bmp" );
	msg = lf_load_image( "msg.png" );

	// Load the Font
	font = TTF_OpenFont( "trisdl.ttf", 28 );

	//Checks
	if (background == NULL)
		return false;

	if (message == NULL)
		return false;

	if (font == NULL)
		return false;

	// If all Went Well
	return true;
}

// Define the Cleanup Function
void SURGE_clean() {

	// Free All Surfaces
	SDL_FreeSurface( background );
	SDL_FreeSurface( msg );
	SDL_FreeSurface( message );

	// Close Font
	TTF_CloseFont( font );

	// Quit TTF and SDL
	TTF_Quit();
	SDL_Quit();
}


#endif
