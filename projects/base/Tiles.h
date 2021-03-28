#pragma once
#include "app.h"
#include "Grid.h"


#define TOTAL_GRID GRID_X_NUMBERS * GRID_Y_NUMBERS

class Tiles : public App
{
public:
	Tiles();
	~Tiles();
	
	void MapLayout();
	void ButtonImages();
	void TileRender(sf::RenderWindow& window);
	void Load();
	
	int tileId = 0;
	
	int map[TOTAL_GRID] =
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


	sf::Sprite images[TOTAL_GRID];


};

