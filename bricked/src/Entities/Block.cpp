#include "Block.h"
#include "../Game.h"

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
