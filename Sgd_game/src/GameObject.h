#pragma once
#include "Game.h"


class GameObject
{
public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void Update(int mod);
	void Render();

private:
	int xpos;
	int ypos;
	bool alive = true;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;




};

