#include "game.h"
#include "texture.h"


void game_run(Display disp) {
	int quit = 0;
	SDL_Event ev;

	Texture chess = load_texture(disp, "res/chess.png");
	set_texture_position(&chess, 400, 500);

	Texture projectile = load_texture(disp, "res/projectile.png");

	

	const Uint8 *keystates = SDL_GetKeyboardState(NULL);
	while (!quit) {
		while (!SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT) {
				quit = 1;
			}
		}

		if (keystates[SDL_SCANCODE_A]) {
			set_texture_position(&chess, chess.x - 1, chess.y);
		}

		if (keystates[SDL_SCANCODE_D]) {
			set_texture_position(&chess, chess.x + 1, chess.y);
		}


		if (keystates[SDL_SCANCODE_SPACE]) {
			printf("pow-pow\n");
		}

		SDL_RenderClear(disp.rend);
		draw_texture(disp, chess);
		SDL_RenderPresent(disp.rend);
	}
}