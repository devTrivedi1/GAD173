#pragma once
#include "Scene.h"


class FirstRound : public Scene
{
public:
	FirstRound();
	~FirstRound();

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