#include "Block.h"
#include "../Game.h"

Block::Block(SDL_Renderer* renderer, Vector2 pos, Vector2 dims, RGBA rgba) : Basic2D(pos, dims, rgba)
{ 
	tag = "Block";

	Vector2 textPos = pos;

	/*textPos.X * 0.25f;
	textPos.Y * 2;*/
	text = new TextUI{ "build/fonts/Melon Pop.ttf", renderer, textPos, RGBA { 255, 255, 255, 255 } };
	text->offset = Vector2{ rect.w * 0.5f, rect.h * 0.5f};
	text->SetText(std::to_string(health));
}

Block::~Block()
{
	Destroy(*text);
}


void Block::Update(Game& game, float deltaTime)
{
	Ball& ball = *game.ball;
	if (IsOverlapping(ball) && ball.Flip(*this)) {
		Damage(game.ball->Damage);		
	}
}

void Block::SetHealth(int amount)
{
	health = amount;
	text->SetText(std::to_string(health));
}

void Block::Damage(int amount)
{
	int projected = health - amount;

	if (projected <= 0) {
		Destroy(*this);
		return;
	}

	SetHealth(projected);
}
