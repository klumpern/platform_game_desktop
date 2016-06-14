#ifndef EVENTS_H
#define EVENTS_H

#include <SDL.h>
#include <stdio.h>

class events {

public:
	events();
	~events();
	void update();
	bool isQuit();
private:
	SDL_Event event;
	bool quit;
};


#endif //EVENTS_H
