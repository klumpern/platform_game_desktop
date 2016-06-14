#include "events.h"


events::events() {
	quit = false;
}

events::~events() {

}

void events::update() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			quit = true;
			printf("closing!\n");
		}
	}

}


bool events::isQuit() {
	return quit;
}