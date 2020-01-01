#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.h"


Texture load_texture(Display disp, char *path) {
	Texture text;
	text.texture = NULL;
	text.x = 0;
	text.y = 0;

	SDL_Surface *temp_surface = IMG_Load(path);

	if (!temp_surface) {
		fprintf(stderr, "Surface failed to load! SDL_image error: %s\n", IMG_GetError());
	} else {
		text.texture = SDL_CreateTextureFromSurface(disp.rend, temp_surface);
		if (!text.texture) {
			fprintf(stderr, "Couldn't convert surface to texture! SDL Error: %s\n", SDL_GetError());
		}
		text.w = temp_surface->w;
		text.h = temp_surface->h;
		SDL_FreeSurface(temp_surface);
	}

	return text;
}

void draw_texture(Display disp, Texture text) {\
	SDL_Rect dstrect = {text.x, text.y, text.w, text.h};
	SDL_RenderCopy(disp.rend, text.texture, NULL, &dstrect);
}

void set_texture_position(Texture *text, int x, int y) {
	text->x = x;
	text->y = y;
}