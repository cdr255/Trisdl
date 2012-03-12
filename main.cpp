#include "main.h"
using namespace std;


// Three Screens: One for an image (background), one
// for a message (message) and one for the visible 
// window (screen). Initialized these POINTERS to 
// NULL, just to be safe.
SDL_Surface * background = NULL;
SDL_Surface * message = NULL;

int main(int argc, char *argv[]) {
	bool quit = false;
	cout << "Argument Count: " << argc << ".\n";
	SURGE_init();

	// Load the Images
	background = lf_load_image( "bg.bmp" );
	message = lf_load_image( "msg.png" );

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

	while ( quit == false ) 
	{
		SDL_Event event;
		while ( SDL_PollEvent( &event ) )
		{
			if ( event.type == SDL_QUIT )
				quit = true;
			if ( event.type == SDL_KEYDOWN )
			{
				switch( event.key.keysym.sym )
				{
					case SDLK_ESCAPE:
						quit = true;
						break;
					default:
						break;
				}
			}
		}
	}

	// Now is the time for cleanup. We need to free the loaded images...
	SDL_FreeSurface( background );
	SDL_FreeSurface( message );

	// And Quit SDL.
	SDL_Quit();


	return 0;
}

