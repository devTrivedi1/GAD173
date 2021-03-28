#pragma once
#include "app.h"
#include "Tiles.h"

class MouseInput : public App
{
public:
	MouseInput();
	~MouseInput();
	void MouseClick();

	Tiles map;

};

