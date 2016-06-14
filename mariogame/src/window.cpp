#include "window.h"

window::window()
{
	this->m_windowHeight = 500;
	this->m_windowWidth =  700;
	this->m_windowName =   "default name";
}


window::~window()
{
	WindowQuit();
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}

//Get the window name/title
std::string window::GetWindowName() {
	return m_windowName;
}

//get window width
int window::GetWindowWidth() {
	return m_windowWidth;
}

//get window height
int window::GetWindowHeight() {
	return m_windowHeight;
}

int window::GetWindowX() {
	return m_windowX;
}

int window::GetWindowY() {
	return m_windowY;
}

//set/change the window title 
void window::SetWindowName(std::string pName) {
	m_windowName = pName;
	SDL_SetWindowTitle(m_window, m_windowName.c_str());
	std::cout << "Succsessfully changed name to: " << pName << "\n";
}

//change the window width
void window::SetWindowWidth(int pWidth) {
	m_windowWidth = pWidth;
	SDL_SetWindowSize(m_window, pWidth, m_windowHeight);
	printf("changed window size to: w:%d h:%d\n", m_windowWidth, m_windowHeight);
}

//change the window height
void window::SetWindowHeight(int pHeight) {
	m_windowHeight = pHeight;
	SDL_SetWindowSize(m_window, m_windowWidth, pHeight);
	printf("changed window size to: w:%d h:%d\n", m_windowWidth, m_windowHeight);
}

void window::SetWindowX(int x) {
	m_windowX = x;
	SDL_SetWindowPosition(m_window, x, m_windowY);
	printf("changed window position to: x:%d y:%d\n", x, m_windowY);
}

void window::SetWindowY(int y) {
	m_windowY = y;
	SDL_SetWindowPosition(m_window, m_windowX, y);
	printf("changed window position to: x:%d y:%d\n", m_windowX, y);
}

void window::CreateWindow(int pWidth, int pHeight, int pX, int pY, std::string pTitle) {

	this->m_windowHeight = pHeight;
	this->m_windowWidth = pWidth;
	this->m_windowX = pX;
	this->m_windowY = pY;
	this->m_windowName = pTitle;

	m_window = NULL;
	m_window = SDL_CreateWindow(m_windowName.c_str(), m_windowX, m_windowY, m_windowWidth, m_windowHeight, SDL_WINDOW_RESIZABLE );

	if (m_window == NULL) {
		printf("Couldnt create window!\n %s\n", SDL_GetError());
		WindowQuit();
	}

}

void window::CreateRenderer() {
	m_renderer = NULL;

	//create a hardware accelerated renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	
	if (m_renderer == NULL) {
		printf("Couldnt create renderer\n %s\n", SDL_GetError());
		WindowQuit();
	}
}


void window::WindowQuit() {
	m_renderer = NULL;
	m_window = NULL;
	IMG_Quit();
	SDL_Quit();
}


void window::draw() {


}

SDL_Renderer* window::GetRenderer() {
	return m_renderer;
}