
#include "Game.h"

class Map {
public:

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();





private:
	SDL_Rect src, dest;
	SDL_Texture* mud;
	SDL_Texture* top;
	SDL_Texture* sky;


	int map[20][25];
};

