#pragma once
#include "Basic2D.h"
#include "../RGBA.h"

class Ball : public Basic2D {
private:
	Vector2 velocity;
	Vector2 bounds;
	bool Flipping = false;
	Basic2D* LastContact = nullptr;
	float originalSpeed = 0;
	Vector2 originalPosition;

	void CheckBounds();

public:
	Ball(Vector2 pos, RGBA rgba);

	int Damage = 1;
	float speed = 200.0f;

	void Update(Game& game, float deltaTime) override;

	void Flip(Basic2D& contact);
	void Reset();
	void SetBounds(Vector2 bounds);
};