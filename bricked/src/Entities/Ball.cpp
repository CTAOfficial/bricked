#include "Ball.h"
#include "../RGBA.h"
#include "../Game.h"
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

	CheckBounds();
}

void Ball::Flip(Basic2D& contact)
{
	if (LastContact != nullptr && IsOverlapping(*LastContact)) {
		return;
	}
	LastContact = &contact;

	velocity = Vector2{ velocity.X, -velocity.Y };
}

void Ball::Reset()
{
	speed = originalSpeed;
	position = originalPosition;
	LastContact = nullptr;
}

void Ball::CheckBounds()
{
	if (position.X < 0 || position.X > bounds.X) {
		velocity.X = -velocity.X;
		LastContact = nullptr;
	}
	if (position.Y < 0) {
		position.Y = 0;
		velocity.Y = -velocity.Y;
		LastContact = nullptr;
	}
	else if (position.Y > bounds.Y) {
		Reset();
	}
}
void Ball::SetBounds(Vector2 bounds)
{
	this->bounds = bounds;
}
