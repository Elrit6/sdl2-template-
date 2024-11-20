#ifndef WINDOW_H  
#define WINDOW_H 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Window {
private:
	SDL_Window* window;
	SDL_Texture* texture;

	void quit();
	void init( const std::size_t width, const std::size_t height );

public:
	SDL_Renderer* renderer;

	Window( const std::size_t width, const std::size_t height );
	~Window();
	void handleEvents();
	void clear();
	void display(); 
};

#endif  