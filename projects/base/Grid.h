#pragma once
#include <SFML/Graphics.hpp>

#define GRID_HORIZONTAL_LINES_COUNT 13
#define GRID_VERTICAL_LINES_COUNT 13

#define CELL_COUNT_X 12
#define CELL_COUNT_Y 12

#define CELL_SIZE_X 40
#define CELL_SIZE_Y 40

#define OFFSET_X 480
#define OFFSET_Y 250

#define CELL_LENGTH_X CELL_SIZE_X * CELL_COUNT_X
#define CELL_LENGTH_Y CELL_SIZE_Y * CELL_COUNT_Y


class Grid
{
public:
	Grid();
	~Grid();
	void gridRender(sf::RenderWindow& window);
	
	sf::RectangleShape xLines[GRID_HORIZONTAL_LINES_COUNT];
	sf::RectangleShape yLines[GRID_VERTICAL_LINES_COUNT];	
};