#pragma once
#include "app.h"
#include "Grid.h"
#include "Tiles.h"
#include "SaveLoad.h"
#include "AnimatingSprites.h"

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	sf::Sprite *m_backgroundSprite;

	bool showColourWindow = false;

	AnimatingSprites animation;
	Tiles mapTiles;
	Grid Lines;
};