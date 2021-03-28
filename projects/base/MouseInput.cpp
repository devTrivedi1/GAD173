#include "MouseInput.h"

void MouseInput::MouseClick()
{
	//MouseCoordinates----------------------------------------------------------------------

	sf::Vector2i mouseCoordinates = sf::Mouse::getPosition(m_window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
		&& mouseCoordinates.x >= 0 && mouseCoordinates.x <= GRID_X_NUMBERS * CELL_WIDTH
		&& mouseCoordinates.y >= 0 && mouseCoordinates.y <= GRID_Y_NUMBERS * CELL_HEIGHT)
	{
		int mouseX = mouseCoordinates.x / CELL_WIDTH;
		int mouseY = mouseCoordinates.y / CELL_HEIGHT;
		int i = mouseX + mouseY * 12;
		std::cout << i << std::endl;



		if (map.tileId == 0)
		{
			map.images[i].setTexture(*map.landTexture);
			map.map[i] = 0;
		}

		if (map.tileId == 1)
		{
			map.images[i].setTexture(*map.treeTexture);
			map.map[i] = 1;
		}

		if (map.tileId == 2)
		{
			map.images[i].setTexture(*map.waterTexture);
			map.map[i] = 2;
		}

		if (map.tileId ==  3)
		{
			map.images[i].setTexture(*map.fenceTexture);
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