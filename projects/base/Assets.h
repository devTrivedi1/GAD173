#pragma once
#include "app.h"
#include "Tiles.h"
#include "Grid.h"


class Assets : public App
{
public:
	void AssetImages();
	void RenderAssets(sf::RenderWindow& window);
	Assets();
	~Assets();

	Tiles placement;

	int tileId = 0;

	sf::Texture* treeTexture;	
	sf::Texture* waterTexture;
	sf::Texture* landTexture;
	sf::Texture* fenceTexture;


	sf::Sprite textureTiles[144];
	

};

