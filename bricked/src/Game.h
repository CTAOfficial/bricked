#pragma once

#include "Windowing/Window.h"
#include "Entities/Ball.h"
#include "UI/TextUI.h"
#include <string>
#include "Vector2.h"

class Player;
class Grid;

class Game : public Window {
private:
	
	Vector2 Bounds;
	Vector2 PlayerBounds;
	TextUI* ui = nullptr;

public:
	Game(std::string& title, Vector2 size);

	Vector2 screenCenter;

	Player* player = nullptr;
	Ball* ball = nullptr;
	Grid* grid = nullptr;

	void Update() override;
};