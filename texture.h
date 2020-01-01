#ifndef TEXTURE_H
#define TEXTURE_H

#include "Display.h"
#include <SDL2/SDL.h>

typedef struct {
	int x, y;
	int w, h;
	SDL_Texture *texture;
} Texture;


Texture load_texture(Display disp, char *path);
void draw_texture(Display disp, Texture text);
void set_texture_position(Texture *text, int x, int y);


#endif // TEXTURE_H
