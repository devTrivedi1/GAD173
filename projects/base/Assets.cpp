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
				placement.MapLayout();
			}

			if (placement.map[i] == 1)
			{
				textureTiles[i].setTexture(*treeTexture);
				placement.MapLayout();
			}

			if (placement.map[i] == 2)
			{
				textureTiles[i].setTexture(*waterTexture);
				placement.MapLayout();
			}

			if (placement.map[i] == 3)
			{
				textureTiles[i].setTexture(*fenceTexture);
				placement.MapLayout();
			}
			textureTiles[i].setPosition(sf::Vector2f(250 + x * 1, 250 + y * 1));
			
		}
		std::cout << "\n";
	}

	
	
}

 void Assets::AssetImages()
 {
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

	 sf::Vector2i mouseCoordinates = sf::Mouse::getPosition(m_window);
	 if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	 {
		 int mouseX = mouseCoordinates.x / 12;
		 int mouseY = mouseCoordinates.y / 12;
		 int i = mouseX + mouseY * 12;

		 std::cout << i << std::endl;


		 if (tileId == 0)
		 {
			 textureTiles[i].setTexture(*landTexture);
			 placement.map[i] = 0;
		 }

		 if (tileId == 1)
		 {
			 textureTiles[i].setTexture(*treeTexture);
			 placement.map[i] = 1;
		 }

		 if (tileId == 2)
		 {
			 textureTiles[i].setTexture(*waterTexture);
			 placement.map[i] = 2;
		 }

		 if (tileId == 3)
		 {
			 textureTiles[i].setTexture(*fenceTexture);
			 placement.map[i] = 3;
		 }

	 }


 }

 Assets::~Assets()
 {

 }
