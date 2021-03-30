#pragma once
#include <SFML/Graphics.hpp>
#include "Tiles.h"

class MouseInput 
{
public:
	MouseInput();
	~MouseInput();
	void MouseClick(Tiles& map, sf::RenderWindow &window);
	

};

