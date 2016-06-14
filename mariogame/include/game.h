#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>

#include <string>

#include "events.h"
#include "window.h"
#include "player.h"
#include "tiles.h"


class game {
	
public:
	game();
	~game();
	bool initalize();
	void update();

private:
	bool quit;
	player player;
	SDL_Renderer* m_tempRenderer;
	window MainWindow;
};


#endif //GAME_H
