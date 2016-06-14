#include "game.h"

game::game() {
	quit = false;
}


game::~game() {

	SDL_DestroyRenderer(m_tempRenderer);

}

bool game::initalize() {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL FAILED! %s", SDL_GetError());
		return false;
	}
	else if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		SDL_Quit();
		return false;
	}

	MainWindow.CreateWindow(1280, 960, 300, 60, "Platformer ");
	MainWindow.CreateRenderer();
	m_tempRenderer = MainWindow.GetRenderer();
	printf("done creating window\n");
	return true;
}

void game::update() {

	events events;
	printf("so far so good\n");

	if (!player.makePlayer(m_tempRenderer)) {
		quit = true;
		IMG_Quit();
		SDL_Quit();
	}
	else {
		printf("made player\n");
	}

	tiles tiles(32, 32);
	if (!tiles.initialize(m_tempRenderer)) {
		printf("tile class has failed!\n");
	}

	while (!quit) {
		events.update();
		MainWindow.draw();
		if (SDL_RenderClear(m_tempRenderer) == -1) {
			printf("rendering went wrong!\nError: %s\n", SDL_GetError());
		}
		tiles.draw(m_tempRenderer);
		player.draw(m_tempRenderer);
		MainWindow.draw();
		SDL_RenderPresent(m_tempRenderer);
		//printf("finished drawing!\n");
		quit = events.isQuit();
	}

}
