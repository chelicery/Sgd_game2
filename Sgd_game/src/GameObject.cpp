#include "GameObject.h"
#include "TextureManager.h"
int counter = 0;
GameObject::GameObject(const char* texturesheet, int x, int y) {

	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void GameObject::Update() {

	xpos++;
	ypos++;
	srcRect.h = 32;
	srcRect.w = 32;

	if (counter % 4 == 1) {
		srcRect.x = 32;
		srcRect.y = 0;
	}
	else {
		srcRect.x = 0;
		srcRect.y = 0;
	}


	counter++;
	
	destRect.x = xpos;
	destRect.y = ypos;

	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

}
void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);

}


