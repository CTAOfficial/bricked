#include "Player.h"
#include "Ball.h"
#include "Grid.h"
#include "../Game.h"
#include <iostream>
#include "../InputManager.h"


Player::Player(int index, Vector2 pos, RGBA rgba) : Basic2D(pos, Vector2{ 75, 15 }, rgba)
{
	playerIndex = index;
	tag = "Player";
}

Player::~Player()
{
	Destroy(*liveUI);
}


void Player::Update(Game& game, float deltaTime)
{
	if (game.grid->blocks.empty() || InputManager::GetKey(SDLK_LSHIFT)) {
		GameOver();
	}

	if (InputManager::GetKey(SDLK_LCTRL)) {
		game.InitializeLevel();
		return;
	}

	if (IsOverlapping(*ball)) {
		ball->Flip(*this);
	}	

	if (InputManager::GetKeyDown(LeftKey)) {
		if ((position.X + rect.w) <= 0) { position.X = Bounds.X - 1; }
		position.X -= speed * deltaTime;
	}
	if (InputManager::GetKeyDown(RightKey)) {
		if ((position.X - 1) >= Bounds.X) { position.X = 0 - rect.w; }
		position.X += speed * deltaTime;
	}
}

void Player::OnContact(Basic2D& contact)
{
	if (typeid(this) != typeid(contact)) {
		return;
	}

	Ball* ball = dynamic_cast<Ball*>(&contact);
	ball->Flip(*this);
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

void Player::SetBall(Ball& ball)
{
	this->ball = &ball;
	ball.player = this;
}


void Player::SetLives(int amount)
{
	lives = amount;

	if (lives <= 0) {
		Die();
		return;
	}

	liveUI->SetText(std::to_string(lives));
}

void Player::Die()
{
	colour = RGBA{ 0, 0, 0, 0 };
	GameOver();
}

void Player::GameOver()
{
	ball->speed = 0;
	speed = 0;

	liveUI->SetText("GAME OVER - Left control to Restart");
}
