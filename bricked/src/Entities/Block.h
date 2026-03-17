#pragma once

#include "Basic2D.h"
#include "../UI/TextUI.h"

struct Block : public Basic2D {
private:
	TextUI* text;
	int health = 1;

	void Damage(int amount);

protected:
	~Block() override;

public:
	Block(SDL_Renderer* renderer, Vector2 pos, Vector2 dims, RGBA rgba);

	void Update(Game& game, float deltaTime) override;

	void SetHealth(int amount);
	int Health() const {
		return health;
	}
};