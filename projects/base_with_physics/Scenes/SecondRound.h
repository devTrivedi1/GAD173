#pragma once
#include "Scene.h"

class SecondRound: public Scene
{	
public:
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

	sf::RectangleShape paddle;
	sf::CircleShape ball;
};

