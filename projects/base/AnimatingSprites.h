#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Grid.h"

class AnimatingSprites
{
	static sf::Texture* spriteSheetTexture;

private:

	sf::Sprite spriteSheet;

	sf::Clock clock;

	int xIndex = 0;
	int yIndex = 0;

	sf::Vector2i positionIndexes;

	sf::Vector2i startFrame;
	sf::Vector2i currentFrame;
	sf::Vector2i endFrame;
	int speed;

public:

	bool beginAnimation = false;

	AnimatingSprites();
	~AnimatingSprites();

	static void LoadAnimation(std::string filename);

	void InitAnimation();
	void UpdateAnimation();
	void RenderAnimation(sf::RenderWindow& window);
	void StartAnimation(sf::Vector2i positionIndexes, sf::Vector2i startFrame, sf::Vector2i endFrame, int speed);
};