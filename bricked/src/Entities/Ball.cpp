#include "Ball.h"
#include "../RGBA.h"
#include "../Game.h"
#include "Player.h"
#include <iostream>


Ball::Ball(Vector2 pos, RGBA rgba) : Basic2D(pos, Vector2{ 10, 10 }, rgba)
{
	velocity = { 1, 1};
	originalSpeed = speed;
	originalPosition = pos;
}

void Ball::Update(Game& game, float deltaTime)
{
	float movementX = (velocity.X * speed) * deltaTime;
	float movementY = (velocity.Y * speed) * deltaTime;

	position.X += movementX;
	position.Y += movementY;

	centerPos = Vector2{ position.X + center.X, position.Y + center.Y };

	CheckBounds();
}

void Ball::Draw(SDL_Renderer* renderer)
{
	Basic2D::Draw(renderer);

	if (DebugMode) {
		// Draw a line from top-left to bottom-right
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderLine(renderer, centerPos.X, centerPos.Y, centerPos.X + (velocity.X * 100), centerPos.Y + (velocity.Y * 100));
	}
}

bool Ball::Flip(Basic2D& contact)
{
	if ((lastContact != nullptr && IsOverlapping(*lastContact))) {
		return false;
	}
	else if (&contact == lastContact) {
		return false;
	}

	lastContact = &contact;
	velocity = Vector2{ velocity.X, -velocity.Y };
	return true;
}

void Ball::Reset()
{
	speed = originalSpeed;
	position = originalPosition;
	lastContact = nullptr;

	player->SetLives(player->GetLives() - 1);
}

void Ball::CheckBounds()
{
	if (position.X < 0 || position.X + rect.w > bounds.X) {
		velocity.X = -velocity.X;
		lastContact = nullptr;
	}
	if (position.Y < 0) {
		position.Y = 0;
		velocity.Y = -velocity.Y;
		lastContact = nullptr;
	}
	else if (position.Y + rect.h > bounds.Y) {
		Reset();
	}
}
void Ball::SetBounds(Vector2 bounds)
{
	this->bounds = bounds;
}
