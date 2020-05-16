#include "SDL.h"
#include "Game.h"

Game *game = nullptr;

int main(int argc, char *arhv[]) {


	game = new Game();
	game->init("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->running()) {

		game->handleEvents();
		game->update();
		game->render();


	}
	game->clean();


	return 0;
}
