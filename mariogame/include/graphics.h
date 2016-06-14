
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class graphics {


public:
	static SDL_Texture* setImage(const char* path, SDL_Renderer* pRenderer);

};



#endif //GRAPHICS_H
