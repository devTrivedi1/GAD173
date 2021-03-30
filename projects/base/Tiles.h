#pragma once
#include <SFML/graphics.hpp>
#include "Grid.h"
#include <kage2dutil\imgui-SFML.h>
#include <kage2dutil\texture_manager.h>



class Tiles 
{
public:
	Tiles();
	~Tiles();
	
	void MapLayout();
	void ButtonImages(sf::RenderWindow& window);
	void Load();
	void TileRender(sf::RenderWindow& window);
	
	int tileId = 0;
	
	int map[144] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 0, 0, 0, 2, 2, 0, 1, 1, 0,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0,
		2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};



	sf::Texture* treeTexture;
	sf::Texture* waterTexture;
	sf::Texture* landTexture;
	sf::Texture* fenceTexture;


	sf::Sprite tileImage[144];


};

