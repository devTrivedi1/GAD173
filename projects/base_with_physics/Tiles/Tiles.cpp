#include "Tiles.h"
#include <iostream>
#include <kage2dutil\texture_manager.h>
#include <kage2dutil\imgui-SFML.h>
#include <SFML/Window/Keyboard.hpp>

Tiles::Tiles()
{

}
Tiles::~Tiles()
{

}

void Tiles::LoadTexture()
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
	transparent = kage::TextureManager::getTexture("data/White.png");

	AnimatingSprites::LoadAnimation("data/Textures-Sprites/Breakout-SpriteSheet.png");

}
void Tiles::MapLoad()
{
	//Textures in the editor-------------------------------------------------
	for (size_t y = 0; y < CELL_COUNT_Y; y++)
	{
		for (size_t x = 0; x < CELL_COUNT_X; x++)
		{
			int i = x + y * CELL_COUNT_X;

			std::cout << i << std::endl;
			if (map[i] > 0)
			{
				animations[i].StartAnimation(sf::Vector2i(x, y), sf::Vector2i(0, map[i]), sf::Vector2i(5, map[i]), 100);
				tileSprite[i].setPosition(sf::Vector2f
				(OFFSET_X + x * CELL_SIZE_X,
					OFFSET_Y + y * CELL_SIZE_Y));
			}
		}
		std::cout << "\n";
	}
	//Textures in the editor-----------------------------------------------------------
}


void Tiles::TileRender(sf::RenderWindow& window)
{
	for (size_t i = 0; i < TOTAL_CELLS; i++)
	{
		window.draw(tileSprite[i]);
	}

	for (int i = 0; i < TOTAL_CELLS; i++) 
	{
		animations[i].RenderAnimation(window);
	}

	for (int i = 0; i < TOTAL_CELLS; i++)
	{
		animations[i].UpdateAnimation();
	}
}