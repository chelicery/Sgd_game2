#include "GameObject.h"
#include "TextureManager.h"
#include "Physics.h"
int pauseState = 0;
bool collided;
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

			ypos+=getVelocity();
	}
	

	collider.x = xpos + offset;
	//std::cout << offset << " Offset" << std::endl;
	collider.y = ypos;
	collider.w = collider.h = 32;
	//std::cout << "xpos= " << collider.x << "ypos" << collider.y << std::endl;
	collided = collideEnemy(collider);
	if (collided)
	{
		alive = false;
		velocity = 0;
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




int GameObject::getVelocity() {
	return velocity;
}

bool GameObject::collideEnemy(SDL_Rect player)
{
	//std::cout << collidingRects.size() << std::endl;;
	for (const auto &i : collidingRects)
	{
		
		if (physics->CheckCollision(player, i))
		{
			std::cout << "ipos " << i.x  << ":x  y:"<< i.y << std::endl;
			//std::cout << " collidegameobj " << std::endl;
			return true;
		}




	}
	return false;
}
void GameObject::setCollidingRects(std::vector<SDL_Rect> vector)
{
	this->collidingRects = vector;
}

void GameObject::setOffset(int o) {
	offset = o;
}

void GameObject::setVelocity(int v) {
	velocity = v;
}

void GameObject::updateStatus(playerStatus e){

		switch (e) {
		case PAUSED:
			srcRect.h = 50;
			srcRect.w = 180;
			destRect.w = 180;
			destRect.h =50;
			srcRect.x = 0;
			srcRect.y = 79;
			destRect.x = xpos;
			destRect.y = ypos;
			//destRect.h = 60;
			break;
		case GAMEOVER:
			srcRect.h = 24;
			srcRect.w = 180;
			destRect.w = 180;
			destRect.h = 24;
			srcRect.x = 0;
			srcRect.y = 60;
			destRect.x = xpos;
			destRect.y = ypos;
			destRect.h = 60;
			break;
		case WORKING:
			srcRect.h = 24;
			srcRect.w = 180;		
			srcRect.x = 0;
			srcRect.y = 0;
			destRect.w = 120;
			destRect.h = 20;
			destRect.x = 0 ; 
			destRect.y = 0;
			break;
		}
	

}