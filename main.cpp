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

	// Start ALL SDL Subsystems, with error checking.
	if (SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		return -1;
	}

	// Set Up the Window where the Action will take place,
	// using the pointer defined above for that purpose.
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

	// And Check for errors with the above
	if ( screen == NULL )
	{
		return -2;
	}

	// Set The Window Caption
	SDL_WM_SetCaption( "Trisdl: An SDL *tris clone.", NULL );

	// Load the Images
	background = lf_load_image( "bg.bmp" );
	message = lf_load_image( "msg.bmp" );

	// Blit the Background 4 times, to cover the whole window.
	lf_apply_surface( 0, 0, background, screen );
	lf_apply_surface( 320, 0, background, screen );
	lf_apply_surface( 0, 240, background, screen );
	lf_apply_surface( 320, 240, background, screen );

	// Now, since the screen has changed, it needs to be flipped.
	SDL_Flip( screen );

	// Delay, for didactic purposes. (in milliseconds)
	SDL_Delay( 2000 );

	// Now, Blit the Message
	lf_apply_surface( 160, 120, message, screen );

	// Now, since the screen has changed, it needs to be flipped.
	if (SDL_Flip( screen ) == -1 )
	{
		return -3;
	}

	// Delay, for didactic purposes. (in milliseconds)
	SDL_Delay( 2000 );

	// Now is the time for cleanup. We need to free the loaded images...
	SDL_FreeSurface( background );
	SDL_FreeSurface( message );

	// And Quit SDL.
	SDL_Quit();


	return 0;
}

