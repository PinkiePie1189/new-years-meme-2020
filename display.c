#include "display.h"

Display create_display(char *name, int w, int h) {
	Display disp;
	disp.wind = NULL;
	disp.rend = NULL;
	disp.name = name;

	disp.wind = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

	if (!disp.wind) {
		fprintf(stderr, "Window failed to create! SDL Error %s\n", SDL_GetError());
	} else {
		disp.rend = SDL_CreateRenderer(disp.wind, -1, SDL_RENDERER_ACCELERATED);
	}

	return disp;
}