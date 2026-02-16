#pragma once
#include <vector>
#include <SDL3/SDL_render.h>

class Basic2D;
class Game;

class EntityManager {
private:
	static std::vector<Basic2D*> Entities;

public:
	static void Add(Basic2D* entity);
	static bool Remove(Basic2D* entity);
	static void Draw(SDL_Renderer* renderer);
	static void Update(Game& game, float deltaTime);
};