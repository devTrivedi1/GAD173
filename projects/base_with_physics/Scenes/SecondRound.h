#pragma once
#include "Scene.h"

class SecondRound: public Scene
{	

	SecondRound();
	~SecondRound();

	void Init() override;
	void Load() override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;

	SaveLoad load;
	Tiles loadTile;
	Grid grid;
	AnimatingSprites loadAnimation;

	
};

