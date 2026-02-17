#include "Block.h"
#include "../Game.h"

Block::Block(SDL_Renderer* renderer, Vector2 pos, Vector2 dims, RGBA rgba) : Basic2D(pos, dims, rgba)
{ 
	tag = "Block";

	Vector2 textPos = pos;

	/*textPos.X * 0.25f;
	textPos.Y * 2;*/
	text = new TextUI{ "build/fonts/Melon Pop.ttf", renderer, textPos, RGBA { 255, 255, 255, 255 } };
	text->SetText(std::to_string(Health));
	text->SetSize(4);
}

Block::~Block()
{
	Destroy(*text);
}


void Block::Update(Game& game, float deltaTime)
{
	if (IsOverlapping(*game.ball)) {
		game.ball->Flip(*this);
		Damage(game.ball->Damage);
	}
}

void Block::Damage(int amount)
{
	Health -= amount;

	if (Health <= 0) {
		Destroy(*this);
		return;
	}

	text->SetText(std::to_string(Health));
}
