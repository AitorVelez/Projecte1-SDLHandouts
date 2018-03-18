#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "SDL\include\SDL.h"


// TODO 2: Init the library and check for possible error
// using SDL_GetError()
bool ModuleWindow::Init()
{



	SDL_Init(SDL_INIT_EVERYTHING);


	// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
	// then create the window and check for errors

	SDL_Window *window;
	window = SDL_CreateWindow("Cuadrat en fons",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_OPENGL);

	// TODO 4: Finally create a screen surface and keep it as a public variable

	SDL_Surface *screen;
	// TODO 5: Fill with code CleanUp() method :)

}



bool ModuleWindow::CleanUp() 
{



}