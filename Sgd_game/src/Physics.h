#pragma once
#include "GameObject.h"

class Physics
{

	public:
		Physics();
		~Physics();

		SDL_Rect Gravity(SDL_Rect rect);
		bool Collision(SDL_Rect* rect1,SDL_Rect* rect2);
	private:


};

