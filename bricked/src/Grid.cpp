#include "Grid.h"
#include "Entities/Block.h"


void Grid::CreateBlocks(SDL_Renderer* renderer, Vector2 pos, Vector2 size, int columns, int rows, int gap)
{
	int x = 0;
	int y = 0;
	RGBA rgba{ 255, 0, 0, 255 };

	int r = 255 / rows;
	int g = 255 / rows;
	int b = 255 / columns;//255 / rows;

	for (int i = 0; i < columns; i++) {

		if (rgba.R <= 0) {
			rgba.R = 255;
		}
		if (rgba.G >= 255) {
			rgba.G = 0;
		}
		if (rgba.B >= 255) {
			rgba.B = 0;
		}
		
		for (int j = 0; j < rows; j++) {

			Block* block = new Block{ renderer, Vector2{ pos.X + size.X + x, pos.Y + size.Y + y }, size, rgba };
			blocks.push_back(block);
			x += gap;
			rgba.G += g;
		}

		x = 0;
		y += gap;

		rgba.B += b;
		rgba.R -= r;
	}
}
