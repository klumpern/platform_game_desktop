#include "player.h"

player::player() {
	m_playerTex[0]	= NULL;
	m_playerTex[1]	= NULL;
	m_player.x		= 100;
	m_player.y		= 100;
	m_player.h		= 50;
	m_player.w		= 50;


	//TEMP
	//t_tileSheet = NULL;
}


player::~player() {

	SDL_DestroyTexture(m_playerTex[0]);
	SDL_DestroyTexture(m_playerTex[1]);

	IMG_Quit();
	SDL_Quit();

}

SDL_Rect player::GetRect() {
	return m_player;
}

bool player::makePlayer(SDL_Renderer* m_renderer) {

	m_playerTex[0] = graphics::setImage("images/standing-left.png", m_renderer);
	if (m_playerTex[0] == NULL) {
		SDL_DestroyRenderer(m_renderer);
		return false;
	}
	m_playerTex[1] = graphics::setImage("images/standing-left-2.png", m_renderer);
	if (m_playerTex[1] == NULL) {
		SDL_DestroyRenderer(m_renderer);
		return false;
	}
	return true;

}

void player::draw(SDL_Renderer* renderer) {
	/*SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, m_playerTex[0], NULL, &m_player);
	SDL_RenderPresent(renderer);

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, m_playerTex[1], NULL, &m_player);
	SDL_RenderPresent(renderer);*/
}