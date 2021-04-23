#pragma once
#include <SFML/graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Grid.h"
#include <kage2dutil\imgui-SFML.h>
#include <kage2dutil\texture_manager.h>
#include <imgui.h>

#define TOTAL_CELLS CELL_COUNT_X * CELL_COUNT_Y

class Tiles 
{
public:
	Tiles();
	~Tiles();
	
	void MapLoad();
	void ButtonImages(sf::RenderWindow& window);
	void LoadTexture();
	void TileRender(sf::RenderWindow& window);
	void UpdatingTexture(sf::RenderWindow& window, sf::Vector2i mouseCoordinates);
	void DeletingTexture(sf::RenderWindow& window, sf::Vector2i mouseCoordinates);

	int tileId = 0;
	int map[TOTAL_CELLS];/* =
	{
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
      6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
      8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};*/

	sf::Texture* black;
	sf::Texture* red;
	sf::Texture* blue;
	sf::Texture* green;
	sf::Texture* purple;
	sf::Texture* teal;
	sf::Texture* orange;
	sf::Texture* yellow;
	sf::Texture* pink;
	sf::Texture* transparent;

	sf::Sprite tileSprite[TOTAL_CELLS];
};