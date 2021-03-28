#pragma once
#include "app.h"
#include "Grid.h"
#include "Tiles.h"
#include "MouseInput.h"


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
	Tiles map;
	MouseInput mouseClick;
	Grid xLines;
	Grid yLines;
};
