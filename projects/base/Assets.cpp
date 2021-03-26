#include "Assets.h"
#include <iostream>
#include "Tiles.h"


void Assets::RenderAssets(sf::RenderWindow &window)
{

	for (size_t i = 0; i < 144; i++)
	{
		window.draw(textureTiles[i]);
	}

}

 Assets::Assets()
{
	
	//Textures---------------------------------------------------------

	treeTexture = kage::TextureManager::getTexture("data/Tree.png");
	

	waterTexture = kage::TextureManager::getTexture("data/Water.jpg");
	

	landTexture = kage::TextureManager::getTexture("data/Land.jpg");
	

	fenceTexture = kage::TextureManager::getTexture("data/Fence.png");
	
    //Textures----------------------------------------------------------

	for (size_t y = 0; y < 12; y++)
	{

		for (size_t x = 0; x < 12; x++)
		{

			int i = x + y * 12;

			if (placement.map[i] == 0)
			{
				textureTiles[i].setTexture(*landTexture);
				textureTiles[i].setPosition(sf::Vector2f(x * 40, y * 50));
			}

			if (placement.map[i] == 1)
			{
				textureTiles[i].setTexture(*treeTexture);

			}

			if (placement.map[i] == 2)
			{
				textureTiles[i].setTexture(*waterTexture);
			}

			if (placement.map[i] == 3)
			{
				textureTiles[i].setTexture(*fenceTexture);
			}

		}
		std::cout << "\n";
	}

	
}

 Assets::~Assets()
 {

 }
