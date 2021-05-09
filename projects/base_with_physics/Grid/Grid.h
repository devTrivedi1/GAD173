#pragma once
#include <SFML/Graphics.hpp>

#define CELL_COUNT_X 12
#define CELL_COUNT_Y 12

#define HORIZONTAL_LINES (CELL_COUNT_Y + 1)
#define VERTICAL_LINES (CELL_COUNT_X + 1)

#define CELL_SIZE_X 120
#define CELL_SIZE_Y 40

#define OFFSET_X 250
#define OFFSET_Y 250

#define CELL_LENGTH_X CELL_SIZE_X * (CELL_COUNT_X)
#define CELL_LENGTH_Y CELL_SIZE_Y * (CELL_COUNT_Y) 

class Grid
{
public:
	Grid();
	~Grid();
	void gridRender(sf::RenderWindow& window);
	
	sf::RectangleShape xLines[HORIZONTAL_LINES];
	sf::RectangleShape yLines[VERTICAL_LINES];	
};