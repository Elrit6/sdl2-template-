#include <cassert>
#include <iostream>
#include "sprite.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

// private

SDL_Texture* Sprite::load(const std::string& path) {
	SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
	if (!texture) {
		std::cerr << IMG_GetError();
		return nullptr;
	}
	return texture;
}

// public

Sprite::Sprite( SDL_Renderer* renderer, const std::string& imgPath, SDL_Rect rect )
: renderer(renderer), rect(rect) {
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		std::cerr << SDL_GetError();
		return;
	}
	if ( IMG_Init( IMG_INIT_PNG ) == 0 ) {
		std::cerr << IMG_GetError();
		return;
	}

	texture = load(imgPath);
};

Sprite::~Sprite() {
	if (texture) 
		SDL_DestroyTexture(texture);
}

void Sprite::display() {
	assert(texture != nullptr); 
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}