#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "display.h"
#include "game.h"

int init_sdl();

int main(int argc, char * argv[]) {
	if (!init_sdl()) {
		return -1;
	}

	Display disp = create_display("test", 800, 600);
	game_run(disp);

	return 0;
}

int init_sdl() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "SDL failed to init! SDL Error: %s\n", SDL_GetError());
		return 0;
	}

	if(!IMG_Init(IMG_INIT_PNG)) {
		fprintf(stderr, "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return 0;
    }

	return 1;
}