#ifndef TILES_H
#define TILES_H


#include <SDL.h>
#include <vector>
#include <stdio.h>
#include "graphics.h"

class tiles {
public:
	tiles(int width, int height);
	~tiles();

	bool initialize(SDL_Renderer* m_renderer);

	std::vector<int>map_width;
	std::vector<int>map_height;

	void draw(SDL_Renderer* m_renderer);

private:

	SDL_Texture* t_tileSheet;
	//SDL_Rect t_tiles[8][8];

};

//describe a tile
struct tile {
	SDL_Rect src;
	int texture;
};


#endif //TILES_H

