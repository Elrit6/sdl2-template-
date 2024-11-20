#ifndef SPRITE_H  
#define SPRITE_H 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Sprite {
private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	SDL_Texture* load(const std::string& path);

public:
    SDL_Rect rect;

	Sprite( SDL_Renderer* renderer, const std::string& path, SDL_Rect rect );

	~Sprite();

	void display();
};

#endif