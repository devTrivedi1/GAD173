#include "MouseInput.h"
#include <iostream>

void MouseInput::MouseClick(Tiles &map, sf::RenderWindow& window)
{
	//MouseCoordinates----------------------------------------------------------------------

	sf::Vector2i mouseCoordinates = sf::Mouse::getPosition(window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
		&& mouseCoordinates.x >= OFFSET_Y && mouseCoordinates.x <= OFFSET_X * CELL_WIDTH
		&& mouseCoordinates.y >= OFFSET_X && mouseCoordinates.y <= OFFSET_Y * CELL_HEIGHT)
	{
		int mouseX = mouseCoordinates.x / CELL_WIDTH;
		int mouseY = mouseCoordinates.y / CELL_HEIGHT;
		int i = mouseX + mouseY * 12;
		std::cout << i << std::endl;

		if (map.tileId == 0)
		{
			map.tileImage[i].setTexture(*map.landTexture);
			map.map[i] = 0;
		}

		if (map.tileId == 1)
		{
			map.tileImage[i].setTexture(*map.treeTexture);
			map.map[i] = 1;
		}

		if (map.tileId == 2)
		{
			map.tileImage[i].setTexture(*map.waterTexture);
			map.map[i] = 2;
		}

		if (map.tileId ==  3)
		{
			map.tileImage[i].setTexture(*map.fenceTexture);
			map.map[i] = 3;
		}

	}
	//MouseCoordinates----------------------------------------------------------------------
}

MouseInput::MouseInput()
{
	
}

MouseInput::~MouseInput()
{

}