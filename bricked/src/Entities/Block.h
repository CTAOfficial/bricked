#pragma once

#include "Basic2D.h"
#include "../UI/TextUI.h"
#include <string>

struct Block : public Basic2D {
private:
	TextUI* text;
	int Health = 1;

	void Damage(int amount);

public:
	Block(SDL_Renderer* renderer, Vector2 pos, Vector2 dims, RGBA rgba) : Basic2D(pos, dims, rgba) {
		tag = "Block";

		Vector2 textPos = pos;

		/*textPos.X * 0.25f;
		textPos.Y * 2;*/
		text = new TextUI{ "build/fonts/Melon Pop.ttf", renderer, textPos, RGBA { 0, 0, 0, 255 } };
		text->SetText(std::to_string(Health));
		text->SetSize(4);
	}

	void Update(Game& game, float deltaTime) override;
};