#include <iostream>
#include "window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//private

void Window::quit() {
	if ( texture ) {
		SDL_DestroyTexture(texture);
	}
	if ( renderer ) {
		SDL_DestroyRenderer(renderer);
	}
	if ( window ) { 
		SDL_DestroyWindow(window);
	}
	SDL_Quit();
	IMG_Quit();    
}

void Window::init( const std::size_t width, const std::size_t height ) {
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		std::cerr << SDL_GetError();
		return;
	}
	if ( IMG_Init( IMG_INIT_PNG ) == 0 ) {
		std::cerr << IMG_GetError();
		return;
	}
	window = SDL_CreateWindow( "taiko", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN ); 
	if ( !window ) {
		std::cerr << SDL_GetError();
		return;
	}
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if ( !renderer ) {
		std::cerr << SDL_GetError();
		return;
	}   
}

// public

Window::Window( const std::size_t width, const std::size_t height ) {
	init( width, height );
	SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
}

Window::~Window() {
	quit();
}

void Window::handleEvents() {
	SDL_Event event;
	while ( SDL_PollEvent( &event ) ) {
		if (event.type == SDL_QUIT) {
			quit();
		}
	}
}

void Window::clear() {
	SDL_RenderClear( renderer );
}

void Window::display() {
	SDL_RenderPresent( renderer );        
}