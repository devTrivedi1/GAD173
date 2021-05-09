#pragma once

#include "app.h"
#include "SceneManager.h"
#include "Load/SaveLoad.h"
#include "Tiles/Tiles.h"
#include "Grid/Grid.h"
#include "Animation/AnimatingSprites.h"

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

	SceneManager sceneManager;
	SaveLoad load;
	Tiles mapTiles;
	Grid grid;
	AnimatingSprites animation;

	sf::Sprite *m_backgroundSprite;

};
