#include "Map.h"
#include "TextureManager.h"
int counter = 0;
int lvl1[16][50] = {
	{0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
	{0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
	{0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
	{0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
	{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
	{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
	{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
	{0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
	{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,3},
	{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
	{0,0,2,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
	{0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
	{0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
	{0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
	{0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
	{0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3},
	   
};

Map::Map() {

	mud = TextureManager::LoadTexture("assets/mud.png");
	sky = TextureManager::LoadTexture("assets/sky.png");
	top = TextureManager::LoadTexture("assets/top.png");
	finish = TextureManager::LoadTexture("assets/finish.png");

	LoadMap(lvl1);
}

void Map::LoadMap(int arr[16][50]) {

	for (int row = 0; row < 16; row++) {
		for (int column = 0; column < 50; column++) {
			map[row][column] = arr[row][column];
		}

	}
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	dest.x = dest.y = 0;
}

void Map::DrawMap(int velocity) {

	int type = 0;
	if (offset < 1280) {
		offset += velocity;
	}

	

		for (int row = 0; row < 16; row++) {

			for (int col = 0; col < 50; col++) {

			if (counter == 0 && ( type == 1 || type == 2))
				{

					collider.x = dest.x;
					collider.y = dest.y;
					collider.h = collider.w = 32;
					colliders.push_back(collider);
					//std::cout << "collider made at :" << collider.x << "  y: " << collider.y << std::endl;
				}

				type = map[row][col];
				dest.x = (col * 32) - offset;
				//std::cout << "ofset wynosi:" << offset << std::endl;
				dest.y = row * 32;
				switch (type) {
				case 0:
					TextureManager::Draw(sky, src, dest);
					break;
				case 1:
					TextureManager::Draw(mud, src, dest);
					break;
				case 2:
					TextureManager::Draw(top, src, dest);
					break;
				case 3:
					TextureManager::Draw(finish, src, dest);
					break;
				default:
					break;
				}

			}
		}
		counter = 1;
	}

std::vector<SDL_Rect> Map::getColliders()
{
			return this->colliders;
	
}
int Map::getOffset() {
	return offset;
}
