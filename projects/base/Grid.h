#pragma once
#include <SFML/Graphics.hpp>

#define GRID_X_NUMBERS 13
#define GRID_Y_NUMBERS 13

#define CELL_WIDTH  40
#define CELL_HEIGHT 40

#define CELL_SIZE 480

#define OFFSET_X 480
#define OFFSET_Y 250

class Grid
{
public:

	Grid();
	~Grid();
	void gridRender(sf::RenderWindow& window);
	
	sf::RectangleShape xLines[GRID_X_NUMBERS];
	sf::RectangleShape yLines[GRID_Y_NUMBERS];
	
};

