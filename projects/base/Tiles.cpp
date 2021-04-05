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
	for (size_t y = 0; y < CELL_COUNT_Y; y++)
	{
		for (size_t x = 0; x < CELL_COUNT_X; x++)
		{
			int i = x + y * CELL_COUNT_X;

			if (map[i] == 0)
			{
				tileSprite[i].setTexture(*black);
			}

			if (map[i] == 1)
			{
				tileSprite[i].setTexture(*green);
			}

			if (map[i] == 2)
			{
				tileSprite[i].setTexture(*red);
			}

			if (map[i] == 3)
			{
				tileSprite[i].setTexture(*blue);
			}

			if (map[i] == 4)
			{
				tileSprite[i].setTexture(*purple);
			}
			if (map[i] == 5)
			{
				tileSprite[i].setTexture(*teal);
			}
			if (map[i] == 6)
			{
				tileSprite[i].setTexture(*orange);
			}
			if (map[i] == 7)
			{
				tileSprite[i].setTexture(*pink);
			}
			if (map[i] == 8)
			{
				tileSprite[i].setTexture(*yellow);
			}
			tileSprite[i].setPosition(sf::Vector2f
									(OFFSET_X + x * CELL_SIZE_X,
									OFFSET_Y + y * CELL_SIZE_Y));
			
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

void Tiles::TileUpdate(sf::RenderWindow& window)
{
	sf::Vector2i mouseCoordinates = sf::Mouse::getPosition(window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
		&& mouseCoordinates.x >= OFFSET_X && mouseCoordinates.x <= OFFSET_X * CELL_SIZE_X
		&& mouseCoordinates.y >= OFFSET_Y && mouseCoordinates.y <= OFFSET_Y * CELL_SIZE_Y)
	{
		int mouseX = (mouseCoordinates.x - OFFSET_X) / CELL_SIZE_X;
		int mouseY = (mouseCoordinates.y - OFFSET_Y) / CELL_SIZE_Y;
		int i = mouseX + mouseY * CELL_COUNT_X;
		std::cout << i << std::endl;

		if (tileId == 0)
		{
			tileSprite[i].setTexture(*black);
			map[i] = 0;
		}

		if (tileId == 1)
		{
			tileSprite[i].setTexture(*green);
			map[i] = 1;
		}

		if (tileId == 2)
		{
			tileSprite[i].setTexture(*red);
			map[i] = 2;
		}

		if (tileId == 3)
		{
			tileSprite[i].setTexture(*blue);
			map[i] = 3;
		}

		if (tileId == 4)
		{
			tileSprite[i].setTexture(*purple);
			map[i] = 4;
		}

		if (tileId == 5)
		{
			tileSprite[i].setTexture(*teal);
			map[i] = 5;
		}

		if (tileId == 6)
		{
			tileSprite[i].setTexture(*orange);
			map[i] = 6;
		}

		if (tileId == 7)
		{
			tileSprite[i].setTexture(*pink);
			map[i] = 7;
		}
		if (tileId == 8)
		{
			tileSprite[i].setTexture(*yellow);
			map[i] = 8;
		}
	}
	
}

void Tiles::TileRender(sf::RenderWindow& window)
{
	for (size_t i = 0; i < TOTAL_CELLS; i++)
	{
		window.draw(tileSprite[i]);
	}
}