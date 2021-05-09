#pragma once
#include <SFML/Graphics.hpp>
#include "Tiles/Tiles.h"
#include <iostream>
#include "Load/SaveLoad.h"
#include "Grid/Grid.h"
#include "Animation/AnimatingSprites.h"

class Scene
{
private:

	bool isRunning;
	bool isLoaded;

public:

	sf::Vector2f position;
	sf::Vector2f ballPosition;

	Scene();
	~Scene();

	virtual void Init();
	virtual void Load();
	virtual void Update();
	virtual void Render(sf::RenderWindow& window);

	inline bool IsLoaded() { return isLoaded; }
};

