#include "Physics.h"

Physics::Physics() {}
Physics::~Physics(){}



bool Physics::CheckCollision(const SDL_Rect a, const SDL_Rect b)
{
	std::cout << "check collicions" << std::endl;
	if (
		a.x + a.w >= b.x &&
		b.x + b.w >= a.x &&
		a.y + a.h >= b.y &&
		b.y + b.h >= a.y
		)
	{
		std::cout << " collide physics" << std::endl;
		return true;

	}
	return false;


}
