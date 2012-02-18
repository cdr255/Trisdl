#include "main.h"
using namespace std;


// Window Attributes, for screen.
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// Three Screens: One for an image (background), one
// for a message (message) and one for the visible 
// window (screen). Initialized these POINTERS to 
// NULL, just to be safe.
SDL_Surface * background = NULL;
SDL_Surface * message = NULL;
SDL_Surface * screen = NULL;

// LazyFoo's Function for loading optimized images.

SDL_Surface * lf_load_image( std::string filename ) {
	// Throwaway Surface for loaded, unoptimized image.
	SDL_Surface * unopt_image = NULL;

	// Throwaway Surface for loaded, optimized image.
	SDL_Surface * optimized_image = NULL;

	// Actually Load the Image
	unopt_image = SDL_LoadBMP( filename.c_str() );

	// Check to make sure an image was loaded
	if ( unopt_image != NULL ) 
	{
		// Optimize the Image
		optimized_image = SDL_DisplayFormat( unopt_image );

		// Free the old image
		SDL_FreeSurface( unopt_image );

		// Return the Optimized Image
		return optimized_image;
	}
	else
	{
		cout << "There was an error loading the image... Sorry.";
		return unopt_image;
	}
}

// LazyFoo's Function for blitting.

void lf_apply_surface( int x, int y, SDL_Surface * source, SDL_Surface * destination ) {

	// Throwaway Rectangle to hold any offsets
	SDL_Rect offset;

	// Collect the offsets in the rectangle
	offset.x = x;
	offset.y = y;

	// Actually Blit the Surfaces
	SDL_BlitSurface( source, NULL, destination, &offset );
}

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

