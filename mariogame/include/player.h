#ifndef PLAYER_H
#define PLAYER_H
#include <SDL.h>
#include "graphics.h"

class player {

public:

	player();
	~player();

	bool makePlayer(SDL_Renderer* m_renderer);
	SDL_Rect GetRect();

	void draw(SDL_Renderer* renderer);

private:
	int status;
	SDL_Rect m_player;
	SDL_Texture* m_playerTex[2];

};


#endif // PLAYER_H