#include "GameObject.h"
#include "TextureManager.h"
#include "Physics.h"
int pauseState = 1;
bool elo;
Physics *physics;
GameObject::GameObject(const char* texturesheet, int x, int y) {

	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	physics = new Physics;
}

void GameObject::Update(int mod) {


	if (alive) {


		auto kstate = SDL_GetKeyboardState(NULL);

		if (kstate[SDL_SCANCODE_LEFT]) {
			xpos -= (2.0) * velocity;
		}
		if (kstate[SDL_SCANCODE_RIGHT] /*&& !elo*/) {
			xpos += (2.0)* velocity;
		}
		if (kstate[SDL_SCANCODE_UP] /*&& !elo*/) {

			ypos -= (6.0)* velocity;

		}

		if (kstate[SDL_SCANCODE_DOWN]) {
			ypos += 2.0* velocity;

		}
		if (kstate[SDL_SCANCODE_P]){
			pauseState++;
		velocity = 1 * (pauseState%2);
		std::cout << pauseState << " pause State" << std::endl;
		}

			ypos+=getVelocity();

	}


	collider.x = xpos;
	collider.y = ypos;
	collider.w = collider.h = 32;
	elo = collideEnemy(collider);
	//std::cout << "Elo " << elo << std::endl;
	if (elo)
	{
		alive = false;
		std::cout << "dead" << std::endl;
		
	}

  	srcRect.h = 22;
	srcRect.w = 32;
	srcRect.y = 0;

	if (mod <= 6) {
		srcRect.x = 32;
	}
	else {
		srcRect.x = 0;
	}

	
	
	destRect.x = xpos;
	destRect.y = ypos;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

}
void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);

}


void GameObject::set_camera() {


}

int GameObject::getVelocity() {
	return velocity;
}

bool GameObject::collideEnemy(SDL_Rect player)
{
	std::cout << collidingRects.size() << std::endl;;
	for (const auto &i : collidingRects)
	{
		
		if (physics->CheckCollision(player, i))
		{
			std::cout << " collidegameobj " << std::endl;
			return true;
		}




	}
	return false;
}
void GameObject::setCollidingRects(std::vector<SDL_Rect> vector)
{
	this->collidingRects = vector;
}
