#include "TextUI.h"
#include <string>
#include <iostream>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_error.h>

TextUI::TextUI(std::string fontPath, SDL_Renderer* renderer, Vector2 pos, RGBA rgba) : Basic2D(pos, rgba)
{
	this->renderer = renderer;
	color = { rgba.R, rgba.G, rgba.B, rgba.A };

	font = TTF_OpenFont(fontPath.c_str(), 12);
	if (!font) {
		std::cout << "Failed to retrive font '" + fontPath + "'\n";
		std::cout << SDL_GetError() << "\n";
	}

	SetText("Sample Text");

	SDL_GetTextureSize(texture, &rect.w, &rect.h);
	rect.x = pos.X;
	rect.y = pos.Y;
}

void TextUI::Draw(SDL_Renderer* renderer) {

	rect.x = position.X;
	rect.y = position.Y;
	SDL_SetRenderDrawColor(renderer, colour.R, colour.G, colour.B, colour.A);
	SDL_RenderTexture(renderer, texture, NULL, &rect);
}

void TextUI::SetText(std::string input)
{
	text = TTF_RenderText_Blended(font, input.c_str(), 0, color);
	if (text) {
		texture = SDL_CreateTextureFromSurface(renderer, text);
		SDL_DestroySurface(text);
	}
}
