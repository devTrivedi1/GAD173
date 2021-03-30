#include "Tiles.h"
#include <iostream>





void Tiles::Load()
{

	//Textures---------------------------------------------------------
	
	treeTexture = kage::TextureManager::getTexture("data/Tree.png");


	waterTexture = kage::TextureManager::getTexture("data/Water.jpg");


	landTexture = kage::TextureManager::getTexture("data/Land.jpg");


	fenceTexture = kage::TextureManager::getTexture("data/Fence.png");

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
				tileImage[i].setTexture(*landTexture);
			}

			if (map[i] == 1)
			{
				tileImage[i].setTexture(*treeTexture);
			}

			if (map[i] == 2)
			{
				tileImage[i].setTexture(*waterTexture);
			}

			if (map[i] == 3)
			{
				tileImage[i].setTexture(*fenceTexture);
			}
			tileImage[i].setPosition(sf::Vector2f
									(OFFSET_X + x * CELL_WIDTH,
									OFFSET_Y + y * CELL_HEIGHT));
		}
		std::cout << "\n";
	}

	//Textures in the editor-----------------------------------------------------------
}


void Tiles::ButtonImages(sf::RenderWindow& window)
{
	//ImGui TextureImages------------------------------------------------------- 
	if (ImGui::ImageButton(*landTexture, sf::Vector2f(40, 40)))
	{
		tileId = 0;
	}
	if (ImGui::ImageButton(*treeTexture, sf::Vector2f(40, 40)))
	{
		tileId = 1;
	}
	if (ImGui::ImageButton(*waterTexture, sf::Vector2f(40, 40)))
	{
		tileId = 2;
	}
	if (ImGui::ImageButton(*fenceTexture, sf::Vector2f(40, 40)))
	{
		tileId = 3;
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

Tiles::Tiles()
{

}
Tiles::~Tiles()
{

}





