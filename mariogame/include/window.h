
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

class window {

public:
	window();
	~window();
	
	//Getters and setters
	//get
	std::string GetWindowName();
	int GetWindowWidth();
	int GetWindowHeight();
	int GetWindowX();
	int GetWindowY();

	SDL_Renderer* GetRenderer();

	//set
	void SetWindowName(std::string pName);
	void SetWindowWidth(int pWidth);
	void SetWindowHeight(int pHeight);
	void SetWindowX(int x);
	void SetWindowY(int y);

	//Functions

	//Create a window
	void CreateWindow(int pWidth, int pHeight, int pX, int pY, std::string pTitle);

	//create renderer
	void CreateRenderer();

	void draw();

private:

	int	m_windowHeight;
	int	m_windowWidth;
	int	m_windowX;
	int	m_windowY;
	std::string m_windowName;

	SDL_Window*	m_window;
	SDL_Renderer* m_renderer;

	void WindowQuit();

};

#endif //WINDOW_H