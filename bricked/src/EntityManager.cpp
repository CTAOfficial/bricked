#include "EntityManager.h"
#include "Entities/Basic2D.h"

std::vector<Basic2D*> EntityManager::Entities;
std::stack<Basic2D*> EntityManager::DestroyQueue;

void EntityManager::Add(Basic2D* entity)
{
	Entities.push_back(entity);
}

void EntityManager::AddToRemove(Basic2D* entity) {
	DestroyQueue.push(entity);
}
bool EntityManager::Remove(Basic2D* entity)
{
	auto iterator = std::find(Entities.begin(), Entities.end(), entity);
	if (iterator != Entities.end()) {
		Entities.erase(iterator);
		return true;
	}

	return false;
}

void EntityManager::Draw(SDL_Renderer* renderer)
{
	for (auto& entity : Entities) {
		entity->Draw(renderer);
	}
}

void EntityManager::Update(Game& game, float deltaTime)
{
	for (auto& entity : Entities) {
		entity->Update(game, deltaTime);
	}
}

void EntityManager::PreUpdate()
{
	for (int i = 0; i < DestroyQueue.size(); i++) {
		Basic2D* entity = DestroyQueue.top();
		Remove(entity);
		DestroyQueue.pop();
	}
}
