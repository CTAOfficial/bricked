#pragma once
#include "Basic2D.h"
#include "UI/TextUI.h"
#include <SDL3/SDL_render.h>

enum Direction {
	Up,
	Down,
	Left,
	Right
};

class Game;
class Ball;

class Player : public Basic2D {

private:
	Vector2 Bounds;
	SDL_Keycode RightKey = NULL;
	SDL_Keycode LeftKey = NULL;

	int lives = 0;
	void Die();
	void GameOver();

protected:
	~Player() override;

public:
	Player(int index, Vector2 pos, RGBA rgba);

	Ball* ball = nullptr;
	TextUI* liveUI = nullptr;

	int playerIndex = 0;
	float speed = 500;

	void Update(Game& game, float deltaTime) override;

	void OnContact(Basic2D& contact) override;

	Vector2 GetBounds() const {
		return Bounds;
	}
	void SetBounds(Vector2 bounds);

	void SetRightKey(SDL_Keycode key);
	void SetLeftKey(SDL_Keycode key);
	void SetBall(Ball& ball);

	int GetLives() const {
		return lives;
	}
	void SetLives(int amount);
};