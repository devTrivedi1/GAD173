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
				animations[i].StartAnimation(sf::Vector2i(x, y), sf::Vector2i(0, map[i]), sf::Vector2i(5, map[i]), 50);
			}
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

void Tiles::UpdatingTexture(sf::RenderWindow& window, sf::Vector2i mouseCoordinates)
{
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
		&& mouseCoordinates.x > OFFSET_X && mouseCoordinates.x < OFFSET_X + CELL_SIZE_X * CELL_COUNT_X
		&& mouseCoordinates.y > OFFSET_Y && mouseCoordinates.y < OFFSET_Y + CELL_SIZE_Y * CELL_COUNT_Y)
	{
		int mouseX = (mouseCoordinates.x - OFFSET_X) / CELL_SIZE_X;
		int mouseY = (mouseCoordinates.y - OFFSET_Y) / CELL_SIZE_Y;
		int i = mouseX + mouseY * CELL_COUNT_X;
		std::cout << i << std::endl;

		map[i] = tileId;

		animations[i].StartAnimation(sf::Vector2i(mouseX, mouseY), sf::Vector2i(0, map[i]), sf::Vector2i(5, map[i]), 50);


		for (int i = 0; i < TOTAL_CELLS; i++)
		{
			animations[i].UpdateAnimation();
		}
	
	}

}

void Tiles::DeletingTexture(sf::RenderWindow& window, sf::Vector2i mouseCoordinates)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)
		&& mouseCoordinates.x > OFFSET_X && mouseCoordinates.x < OFFSET_X + CELL_SIZE_X * CELL_COUNT_X
		&& mouseCoordinates.y > OFFSET_Y && mouseCoordinates.y < OFFSET_Y + CELL_SIZE_Y * CELL_COUNT_Y)
	{
		int mouseX = (mouseCoordinates.x - OFFSET_X) / CELL_SIZE_X;
		int mouseY = (mouseCoordinates.y - OFFSET_Y) / CELL_SIZE_Y;
		int i = mouseX + mouseY * CELL_COUNT_X;
		std::cout << i << std::endl;

		animations[i].StartAnimation(sf::Vector2i(mouseX, mouseY), sf::Vector2i(0, map[i]), sf::Vector2i(5, map[i]), 50);

		map[i] = tileId;
		animations[i].beginAnimation = false;
		for (int i = 0; i < TOTAL_CELLS; i++)
		{
			animations[i].UpdateAnimation();
		}
	}
}

void Tiles::TileRender(sf::RenderWindow& window)
{
	for (int i = 0; i < TOTAL_CELLS; i++) 
	{
		animations[i].RenderAnimation(window);
	}

	for (int i = 0; i < TOTAL_CELLS; i++)
	{
		if (animations[i].beginAnimation == true)
		{
			animations[i].UpdateAnimation();
		}
	}
}