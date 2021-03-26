#pragma once
#include "app.h"
#include "Tiles.h"


class Assets
{
public:
	void RenderAssets(sf::RenderWindow& window);
	Assets();
	~Assets();
	

	Tiles placement;

	sf::Texture* treeTexture;	
	sf::Texture* waterTexture;
	sf::Texture* landTexture;
	sf::Texture* fenceTexture;


	sf::Sprite textureTiles[144];
	

};

