#include "Player.h"
#include "../Game.h"
#include <iostream>
#include "../InputManager.h"

Player::Player(int index, Vector2 pos, RGBA rgba) : Basic2D::Basic2D(pos, Vector2{ 75, 15 }, rgba)
{
	playerIndex = index;
}

void Player::Update(Game& game, float deltaTime)
{
	if (IsOverlapping(*game.ball)) {
		game.ball->Flip(*this);
	}

	if (InputManager::GetKeyDown(LeftKey)) {
		if ((position.X + rect.w) <= 0) { position.X = Bounds.X - 1; }
		position.X -= speed * deltaTime;
	}
	if (InputManager::GetKeyDown(RightKey)) {
		if ((position.X - 1) >= Bounds.X) { position.X = 0; }
		position.X += speed * deltaTime;
	}
}

void Player::AssignZone(ScoreZone* scorezone)
{
	zone = scorezone;
}

void Player::SetBounds(Vector2 bounds)
{
	Bounds = bounds;
}

void Player::SetRightKey(SDL_Keycode key)
{
	RightKey = key;
}

void Player::SetLeftKey(SDL_Keycode key)
{
	LeftKey = key;
}
