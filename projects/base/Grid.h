#pragma once
#include "app.h"

#define X_LINES 25
#define Y_LINES 13

class Grid
{
public:

	Grid();
	~Grid();
	
	void Render(sf::RenderWindow &window);

	sf::RectangleShape xLines[X_LINES];
	sf::RectangleShape yLines[Y_LINES];
	
};

