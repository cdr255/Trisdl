#include "main.h"
using namespace std;

int main(int argc, char *argv[]) {
	cout << "Argument Count: " << argc << ".\n";

	// Two screens: One for an image (hello) and
	// one for the visible window (screen). Initialized
	// these POINTERS to NULL, to be safe.
	SDL_Surface * hello = NULL;
	SDL_Surface * screen = NULL;

	// Start ALL SDL Subsystems.
	SDL_Init( SDL_INIT_EVERYTHING );

	// Set Up the Window where the Action will take place,
	// using the pointer defined above for that purpose.
	screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

	// Use the other pointer to load an image.
	hello = SDL_LoadBMP( "hello.bmp" );

	// Since screen is the window, we need to draw hello onto
	// it (Blitting).
	SDL_BlitSurface( hello, NULL, screen, NULL );

	// Now, since the screen has changed, it needs to be flipped.
	SDL_Flip( screen );

	// Delay, for didactic purposes. (in milliseconds)
	SDL_Delay( 2000 );

	// Now is the time for cleanup. We need to free the loaded image...
	SDL_FreeSurface( hello );

	// And Quit SDL.
	SDL_Quit();


	return 0;
}

