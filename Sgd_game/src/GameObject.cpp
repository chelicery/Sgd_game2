#include "GameObject.h"
#include "TextureManager.h"
int counter = 0;

GameObject::GameObject(const char* texturesheet, int x, int y) {

	objTexture = TextureManager::LoadTexture(texturesheet);
	//physics = Physics::Physics();
	xpos = x;
	ypos = y;
}

void GameObject::Update(int mod) {


	if (alive) {



		//elo = physics->CheckCollision(destRect, kol);

		auto kstate = SDL_GetKeyboardState(NULL);

			if (kstate[SDL_SCANCODE_LEFT]) {
				xpos -= (4.0);
			}
			if (kstate[SDL_SCANCODE_RIGHT] /*&& !elo*/) {
				xpos += (2.0);
			}
			if (kstate[SDL_SCANCODE_UP] /*&& !elo*/) {

				ypos -= (4.0);

			}
			if (kstate[SDL_SCANCODE_RCTRL]) {
				destRect.x = 440;
				destRect.y = 250;
				;
			}
			//speed = physics->SpeedDecrease();
			if (kstate[SDL_SCANCODE_DOWN]) {
				ypos += 2.0;

			}

		}









    ypos++;
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.y = 0;
	if (mod <= 6) {
		srcRect.x = 32;
	}
	else {
		srcRect.x = 0;
	}

	counter++;
	
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