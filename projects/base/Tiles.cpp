#include "Tiles.h"
#include <iostream>


Tiles::Tiles()
{

}
Tiles::~Tiles()
{

}

void Tiles::Load()
{
	//Textures---------------------------------------------------------

	purple = kage::TextureManager::getTexture("data/Purple.png");
	orange = kage::TextureManager::getTexture("data/Orange.png");
	yellow = kage::TextureManager::getTexture("data/Yellow.png");
	green = kage::TextureManager::getTexture("data/Green.png");
	blue = kage::TextureManager::getTexture("data/Blue.png");
	teal = kage::TextureManager::getTexture("data/Teal.png");
	red = kage::TextureManager::getTexture("data/Red.png");
	pink = kage::TextureManager::getTexture("data/Pink.png");
	black = kage::TextureManager::getTexture("data/Black.png");
	//Textures----------------------------------------------------------

}

void Tiles::MapLayout()
{

	//Textures in the editor-------------------------------------------------

	for (size_t y = 0; y < 12; y++)
	{
		for (size_t x = 0; x < 12; x++)
		{
			int i = x + y * 12;

			if (map[i] == 0)
			{
				tileImage[i].setTexture(*black);
			}

			if (map[i] == 1)
			{
				tileImage[i].setTexture(*green);
			}

			if (map[i] == 2)
			{
				tileImage[i].setTexture(*red);
			}

			if (map[i] == 3)
			{
				tileImage[i].setTexture(*blue);
			}

			if (map[i] == 4)
			{
				tileImage[i].setTexture(*purple);
			}
			if (map[i] == 5)
			{
				tileImage[i].setTexture(*teal);
			}
			if (map[i] == 6)
			{
				tileImage[i].setTexture(*orange);
			}
			if (map[i] == 7)
			{
				tileImage[i].setTexture(*pink);
			}
			if (map[i] == 8)
			{
				tileImage[i].setTexture(*yellow);
			}
			tileImage[i].setPosition(sf::Vector2f
									(HORIZONTAL_OFFSET_X + x * CELL_WIDTH,
									VERTICAL_OFFSET_Y + y * CELL_HEIGHT));
		}
		std::cout << "\n";
	}
	//Textures in the editor-----------------------------------------------------------
}

void Tiles::ButtonImages(sf::RenderWindow& window)
{
	//ImGui TextureImages------------------------------------------------------- 
	if (ImGui::ImageButton(*black))
	{
		tileId = 0;
	}
	if (ImGui::ImageButton(*green))
	{
		tileId = 1;
	}
	if (ImGui::ImageButton(*red))
	{
		tileId = 2;
	}
	if (ImGui::ImageButton(*blue))
	{
		tileId = 3;
	}
	if (ImGui::ImageButton(*purple))
	{
		tileId = 4;
	}
	if (ImGui::ImageButton(*teal))
	{
		tileId = 5;
	}
	if (ImGui::ImageButton(*orange))
	{
		tileId = 6;
	}
	if (ImGui::ImageButton(*pink))
	{
		tileId = 7;
	}
	if (ImGui::ImageButton(*yellow))
	{
		tileId = 8;
	}
	//ImGui Texture Images----------------------------------------------------------
}

void Tiles::TileRender(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 144; i++)
	{
		window.draw(tileImage[i]);
	}
}

void Tiles::TileUpdate(sf::RenderWindow& window)
{
	sf::Vector2i mouseCoordinates = sf::Mouse::getPosition(window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
		&& mouseCoordinates.x >= HORIZONTAL_OFFSET_X && mouseCoordinates.x <= HORIZONTAL_OFFSET_Y * CELL_WIDTH
		&& mouseCoordinates.y >= VERTICAL_OFFSET_Y && mouseCoordinates.y <= VERTICAL_OFFSET_X * CELL_HEIGHT)
	{
		int mouseX = (mouseCoordinates.x - HORIZONTAL_OFFSET_X) / CELL_WIDTH;
		int mouseY = (mouseCoordinates.y - VERTICAL_OFFSET_Y) / CELL_HEIGHT;
		int i = mouseX + mouseY * 12;
		std::cout << i << std::endl;

		if (tileId == 0)
		{
			tileImage[i].setTexture(*black);
			map[i] = 0;
		}

		if (tileId == 1)
		{
			tileImage[i].setTexture(*green);
			map[i] = 1;
		}

		if (tileId == 2)
		{
			tileImage[i].setTexture(*red);
			map[i] = 2;
		}

		if (tileId == 3)
		{
			tileImage[i].setTexture(*blue);
			map[i] = 3;
		}

		if (tileId == 4)
		{
			tileImage[i].setTexture(*purple);
			map[i] = 4;
		}

		if (tileId == 5)
		{
			tileImage[i].setTexture(*teal);
			map[i] = 5;
		}

		if (tileId == 6)
		{
			tileImage[i].setTexture(*orange);
			map[i] = 6;
		}

		if (tileId == 7)
		{
			tileImage[i].setTexture(*pink);
			map[i] = 7;
		}
		if (tileId == 8)
		{
			tileImage[i].setTexture(*yellow);
			map[i] = 8;
		}
	}
}