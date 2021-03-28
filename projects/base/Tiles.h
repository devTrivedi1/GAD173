#pragma once
#include "app.h"
#include "Grid.h"


#define MAP_OVERVIEW 144

class Tiles : public App
{
public:
	Tiles();
	~Tiles();
	
	void MapLayout();
	void ButtonImages();
	void TileRender(sf::RenderWindow& window);
	

	int tileId = 0;
	int map[MAP_OVERVIEW] =
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


	sf::Sprite images[144];


};

