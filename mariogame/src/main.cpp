#include "game.h"
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char *argv[]) {
	
	game game;
	if (!game.initalize()) {
		IMG_Quit();
		SDL_Quit();
		return 0;
	}
	else {
		game.update();
	}
	
	IMG_Quit();
	SDL_Quit();
	return 0;
}