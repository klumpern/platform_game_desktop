#include "graphics.h"


SDL_Texture* graphics::setImage(const char* path, SDL_Renderer* pRenderer) {
	SDL_Surface *p_surface = NULL;
	SDL_Texture *p_texture = NULL;

	p_surface = IMG_Load(path);
	if (p_surface == NULL) {
		printf("failed to load image, image: %s\nError: %s\nImage error: %s\nReturning NULL\n", path, SDL_GetError(), IMG_GetError());
		return NULL;
	}
	else {
		p_texture = SDL_CreateTextureFromSurface(pRenderer, p_surface);
		if(p_texture == NULL){
			printf("failed to convert surface to texture, image: %s\nError: %s\nImage error: %s\nReturning NULL\n", path, SDL_GetError(), IMG_GetError());
			return NULL;
		}
	}
	return p_texture;
}

