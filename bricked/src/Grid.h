#pragma once
#include <vector>
#include "Vector2.h"
#include <SDL3/SDL.h>


class Block;

//template <typename T>
class Grid {
private:

public:
	Grid(){}

	std::vector<Block*> blocks;

	void CreateBlocks(SDL_Renderer* renderer, Vector2 pos, Vector2 size, int columns, int rows, int gap);
};