#pragma once
#include "Basic2D.h"
#include <SDL3/SDL_render.h>

enum Direction {
	Up,
	Down,
	Left,
	Right
};

class Game;
class ScoreZone;

class Player : public Basic2D {

private:
	ScoreZone* zone = nullptr;
	Vector2 Bounds;
	SDL_Keycode RightKey = NULL;
	SDL_Keycode LeftKey = NULL;

public:
	Player(int index, Vector2 pos, RGBA rgba);

	int playerIndex = 0;
	float speed = 500;

	void Update(Game& game, float deltaTime) override;
	void AssignZone(ScoreZone* scorezone);
	void SetBounds(Vector2 bounds);

	void SetRightKey(SDL_Keycode key);
	void SetLeftKey(SDL_Keycode key);
};