#include "Game.h"
#include "InputManager.h"
#include "Entities/Player.h"
#include "EntityManager.h"


Game::Game(std::string& title, Vector2 size) : Window(title, (int)size.X, (int)size.Y)
{
	screenCenter = Vector2{ size.X * 0.5f, size.Y * 0.5f };
	Bounds = size;

	player = new Player(0, Vector2{ screenCenter.X * 0.5f, Bounds.Y * 0.9f }, RGBA{ 255, 255, 255, 255 });
	player->SetLeftKey(SDLK_A);
	player->SetRightKey(SDLK_D);
	player->SetBounds(Bounds);

	ball = new Ball(screenCenter, RGBA{ 0, 213, 145, 0 });
	ball->SetBounds(Bounds);

}

void Game::Update() {

	if (InputManager::GetKey(SDLK_ESCAPE)) { Close(); }

	EntityManager::Update(*this, deltaTime);
	EntityManager::Draw(renderer);
	
}
