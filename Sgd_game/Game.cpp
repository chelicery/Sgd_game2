#include "Game.h"

SDL_Texture* playerTex;

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen == true) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "Subsystem initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, false);

		if (window) {
			std::cout << "window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Rendereer Created!" << std::endl;
		}
		isRunning = true;
	}

	SDL_Surface* tmpSurface = IMG_Load("player.png");

	std::cout << "tmpsurface=" << tmpSurface << " Reason: " << SDL_GetError() << std::endl;
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
		
}

void Game::handleEvents(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;

	default:
		break;
	}

};
void Game::update(){
	cnt++;
	//std::cout << "cnt: " << cnt << std::endl;;
};
void Game::render(){
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTex, NULL, NULL);
	SDL_RenderPresent(renderer);
};
void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game clened" << std::endl;

};

bool Game::running() {
	return isRunning;
}
