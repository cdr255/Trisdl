// This is SURGE - the Simple Universal Realistic Game Engine. It does
// NOT attempt to me a hold-your-hand, do-everything-for-you engine
// like... every other engine I have ever used. All this does is
// compile the common methods I use in every game I make, so I can
// stop rewriting the same code over and over and over. YMMV, HTH.
#ifndef _SURGE_H_
#define _SURGE_H_
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

// VARIABLES

// This is the window in SURGE.
SDL_Surface * screen = NULL;

// All games need some kind of text. This is the MAIN font.
TTF_Font * font = NULL;

// In SURGE, the default text color is WHITE.
SDL_Color textcolor = {255, 255, 255};

// Declare the Initialization function
bool SURGE_init();

// Declare the Loading function
bool SURGE_load();


// LazyFoo's Function for loading optimized images.

SDL_Surface * lf_load_image( std::string filename ) {
	// Throwaway Surface for loaded, unoptimized image.
	SDL_Surface * unopt_image = NULL;

	// Throwaway Surface for loaded, optimized image.
	SDL_Surface * optimized_image = NULL;

	// Actually Load the Image
	unopt_image = IMG_Load( filename.c_str() );

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
		std::cout << "There was an error loading the image... Sorry.";
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



#endif
