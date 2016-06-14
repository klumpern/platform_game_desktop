#include "timer.h"

timer::timer() {
	m_started = 0;
	m_pausedTicks = 0;
	
	m_paused = false;
	m_started = false;
}

timer::~timer() {

}


void timer::start() {

	m_started = true;
	m_paused = false;

	m_startTicks = SDL_GetTicks();
	m_pausedTicks = 0;

}

void timer::stop() {

	m_started = false;
	m_paused = false;

	m_startTicks = 0;
	m_pausedTicks = 0;

}

void timer::pause() {

	if (m_started && !m_paused) {

		m_paused = true;
		m_pausedTicks = SDL_GetTicks() - m_startTicks;
		m_startTicks = 0;

	}

}

void timer::unpause() {

	if (m_started && m_paused) {

		m_paused = false;
		m_startTicks = SDL_GetTicks() - m_pausedTicks;
		m_pausedTicks = 0;

	}

}


Uint32 timer::GetTicks()
{

	Uint32 time = 0;
	if (m_started)
	{
		if (m_paused)
		{
			time = m_pausedTicks;
		}
		else
		{
			time = SDL_GetTicks() - m_startTicks;
		}
	}

	return time;

}

bool timer::isStarted()
{
	return m_started;
}

bool timer::isPaused()
{
	return m_paused && m_started;
}