#include <iostream>
#include "Tiles.h"


void Tiles::MapLayout()
{


	//Textures---------------------------------------------------------

	treeTexture = kage::TextureManager::getTexture("data/Tree.png");


	waterTexture = kage::TextureManager::getTexture("data/Water.jpg");


	landTexture = kage::TextureManager::getTexture("data/Land.jpg");


	fenceTexture = kage::TextureManager::getTexture("data/Fence.png");

	//Textures----------------------------------------------------------

	//Setting Textures -------------------------------------------------
	for (size_t y = 0; y < 13; y++)
	{

		for (size_t x = 0; x < 13; x++)
		{

			int i = x + y * 12;

			if (map[i] == 0)
			{
				images[i].setTexture(*landTexture);
				
			}

			if (map[i] == 1)
			{
				images[i].setTexture(*treeTexture);
				
			}

			if (map[i] == 2)
			{
				images[i].setTexture(*waterTexture);
				
			}

			if (map[i] == 3)
			{
				images[i].setTexture(*fenceTexture);
				
			}
			images[i].setPosition(sf::Vector2f(OFFSET_X + x * CELL_SPACING_Y, OFFSET_Y + y * CELL_SPACING_X));

		}
		std::cout << "\n";
	}
	//Setting Textures-----------------------------------------------------------
}


void Tiles::ButtonImages()
{
	//ImGui TextureImages------------------------------------------------------- 
	if (ImGui::ImageButton(*landTexture, sf::Vector2f(25, 25)))
	{
		tileId = 0;
	}
	if (ImGui::ImageButton(*treeTexture, sf::Vector2f(25, 25)))
	{
		tileId = 1;
	}
	if (ImGui::ImageButton(*waterTexture, sf::Vector2f(25, 25)))
	{
		tileId = 2;
	}
	if (ImGui::ImageButton(*fenceTexture, sf::Vector2f(25, 25)))
	{
		tileId = 3;
	}
	//ImGui Texture Images----------------------------------------------------------
	
	//MouseCoordinates----------------------------------------------------------------------

	sf::Vector2i mouseCoordinates = sf::Mouse::getPosition(m_window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) 
		&& mouseCoordinates.x >= 0 && mouseCoordinates.x <= GRID_X_NUMBERS * CELL_SPACING_X 
		&& mouseCoordinates.y >= 0 && mouseCoordinates.y <= GRID_Y_NUMBERS * CELL_SPACING_Y)
	{
		int mouseX = mouseCoordinates.x / CELL_SPACING_X;
		int mouseY = mouseCoordinates.y / CELL_SPACING_Y;
		int i = mouseX + mouseY * 12;

		


		if (tileId == 0)
		{
			images[i].setTexture(*landTexture);
			map[i] = 0;
		}

		if (tileId == 1)
		{
			images[i].setTexture(*treeTexture);
			map[i] = 1;
		}

		if (tileId == 2)
		{
			images[i].setTexture(*waterTexture);
			map[i] = 2;
		}

		if (tileId == 3)
		{
			images[i].setTexture(*fenceTexture);
			map[i] = 3;
		}

	}
	//MouseCoordinates----------------------------------------------------------------------
}

void Tiles::TileRender(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 144; i++)
	{
		m_window.draw(images[i]);
	}

}



Tiles::Tiles()
{

}
Tiles::~Tiles()
{

}





