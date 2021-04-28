#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Grid.h"


class AnimatingSprites
{

private:
	
	sf::Texture* spriteSheetTexture;
	sf::Sprite spriteSheet;
	
	int spriteId = 0;
	sf::Sprite spriteTest[100];
	
	sf::Clock clock;

	int xIndex = 0;
	int yIndex = 0;

	sf::Vector2i startFrame;
	sf::Vector2i currentFrame;
	sf::Vector2i endFrame;
	int speed;
	bool beginAnimation = false;

public:
	AnimatingSprites();
	~AnimatingSprites();

	void InitAnimation();
	void LoadAnimation(std::string filename);
	void UpdateAnimation();
	void RenderAnimation(sf::RenderWindow& window);

	void StartAnimation(sf::Vector2i startFrame, sf::Vector2i endFrame, int speed);
};