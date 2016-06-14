#include "tiles.h"

tiles::tiles(int width, int height) {

	map_width.resize(width);
	map_height.resize(height);

	/*map.resize(width);
	printf("resizing map to %d width\n", width);
	for (int i = 0; i < width; ++i) {
		map[i].resize(height);
	}


	for (int y = 0; y < height; y++) {
		printf("first loop\n");
		for (int x = 0; x < width; x++) {
			printf("value at position: %d\n", map[x][y]);
			printf("x:%d\ny%d\n", x, y);
		}
	}*/

}

tiles::~tiles(){ 

}

bool tiles::initialize(SDL_Renderer* m_renderer) {
	t_tileSheet = graphics::setImage("images/spritesheet.png", m_renderer);
	if (t_tileSheet == NULL) {
		return false;
	}

	//clip tile sheet
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			t_tiles[x][y].x = x * 32;
			t_tiles[x][y].y = y * 32;
			t_tiles[x][y].w = 32;
			t_tiles[x][y].h = 32;
			printf("x: %d\ny: %d\ntile_x: %d\ntile_y: %d\nw: %d\nh: %d\n\n", x, y, t_tiles[x][y].x, t_tiles[x][y].y, t_tiles[x][y].w, t_tiles[x][y].h);
		
		}
	}
	printf("x:%d\ny:%d\nh:%d\nw:%d\n", t_tiles[3][4].x, t_tiles[3][4].y, t_tiles[3][4].h, t_tiles[3][4].w);
	return true;
}

void tiles::draw(SDL_Renderer* m_renderer) {

	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			SDL_RenderCopy(m_renderer, t_tileSheet, &t_tiles[x][y], &t_tiles[x][y]);
		}
	}

}