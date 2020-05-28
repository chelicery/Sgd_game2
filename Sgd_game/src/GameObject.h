#pragma once
#include "Game.h"
#include "Physics.h"
#include <vector>


class GameObject
{
public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();
	void Update(int mod);
	void Render();
	int getVelocity();
	enum playerStatus { WORKING, PAUSED, GAMEOVER};

	bool collideEnemy(SDL_Rect player);
	void setCollidingRects(std::vector<SDL_Rect> vector);
	void setOffset(int offset);
	void setVelocity(int v);
	void updateStatus(playerStatus stat = WORKING);

private:
	int offset;
	int xpos;
	int ypos;
	bool alive = true;
	int velocity = 1;
	SDL_Rect collider;
	std::vector <SDL_Rect> collidingRects;

//	Physics physics;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;




};

