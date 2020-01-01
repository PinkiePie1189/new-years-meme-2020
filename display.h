#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <stdio.h>
#define MAX_NAME 256

typedef struct {
	int w, h;
	char *name;
	SDL_Window *wind;
	SDL_Renderer *rend;
} Display;


Display create_display(char *name, int w, int h);

#endif // DISPLAY_H
