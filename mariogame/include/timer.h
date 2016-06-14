#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

class timer {
public:
	timer();
	~timer();
	
	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 GetTicks();

	bool isStarted();
	bool isPaused();

private:

	Uint32 m_startTicks;
	Uint32 m_pausedTicks;

	bool m_paused;
	bool m_started;

};


#endif //TIMER_H
