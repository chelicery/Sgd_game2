#include "SDL.h"
#include "Game.h"

Game *game = nullptr;
int frameAnime = 0;
int main(int argc, char *arhv[]) {

	const int FPS = 45;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 512, false);
	while (game->running()) {

		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update(frameAnime);
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		frameAnime++;


		if (FPS / frameAnime == 4) {
			frameAnime = 0;
		}

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
		

	}
	game->clean();


	return 0;
}

