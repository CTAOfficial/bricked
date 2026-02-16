#include "Grid.h"
#include "Entities/Block.h"


void Grid::CreateBlocks(SDL_Renderer* renderer, Vector2 pos, Vector2 size, int columns, int rows, int amount, int gap)
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < columns; i++) {
		x = 0;

		for (int j = 0; j < rows; j++) {
			x = 0;

			for (int s = 0; s < amount; s++) {

				Block* block = new Block{ renderer, Vector2{pos.X + size.X + x, pos.Y + size.Y + y}, size, RGBA {255, 255, 255, 255}};
				blocks.push_back(block);
				x += gap;
			}
		}

		y += gap;
	}
}
