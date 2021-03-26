#pragma once
#include <SFML/Graphics.hpp>

#define X_LINES 13
#define Y_LINES 13

class Grid
{
public:

	Grid();
	~Grid();
	
	
	void gridRender(sf::RenderWindow& window);
	
	sf::RectangleShape xLines[X_LINES];
	sf::RectangleShape yLines[Y_LINES];
	
};

