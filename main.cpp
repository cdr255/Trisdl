#include "main.h"
using namespace std;


int main(int argc, char *argv[]) {
	bool quit = false;
	cout << "Argument Count: " << argc << ".\n";
	SURGE_init();
	SURGE_load();

	// Blit the Background 4 times, to cover the whole window.
	lf_apply_surface( 0, 0, background, screen );
	lf_apply_surface( 320, 0, background, screen );
	lf_apply_surface( 0, 240, background, screen );
	lf_apply_surface( 320, 240, background, screen );

	// Now, since the screen has changed, it needs to be flipped.
	SDL_Flip( screen );

	// Delay, for didactic purposes. (in milliseconds)
	SDL_Delay( 2000 );

	message = TTF_RenderText_Solid(font, "This is a test.", textcolor);

	// Now, Blit the Messages
	lf_apply_surface( 160, 120, msg, screen );
	lf_apply_surface( 180, 140, message, screen );

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

	SURGE_clean();

	return 0;
}

