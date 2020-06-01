#pragma once
#include "Game.h"
#include <vector>
class Map {
public:

	Map();
	~Map();
	void LoadMap(int arr[16][50]);
	void DrawMap(int velocity);
	std::vector<SDL_Rect> getColliders();
	int getOffset();
private:
	SDL_Rect src, dest;
	SDL_Texture* mud;
	SDL_Texture* top;
	SDL_Texture* sky;
	SDL_Texture* finish;
	SDL_Rect collider;
	std::vector<SDL_Rect> colliders;
	int map[16][50];
	int offset;
};

