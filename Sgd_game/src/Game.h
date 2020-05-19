#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>




class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;


};
