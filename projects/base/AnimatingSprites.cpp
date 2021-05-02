#include "AnimatingSprites.h"
#include <kage2dutil/texture_manager.h>
#include <iostream>

#define SPRITE_WIDTH 120
#define SPRITE_HEIGHT 40


 sf::Texture* AnimatingSprites::spriteSheetTexture = nullptr;

AnimatingSprites::AnimatingSprites()
{

}
AnimatingSprites::~AnimatingSprites()
{

}

void AnimatingSprites::InitAnimation()
{

}

void AnimatingSprites::LoadAnimation(std::string filename)
{
	//xIndex = 0;
	//yIndex = 0;

	//int x = SPRITE_WIDTH * xIndex;
	//int y = SPRITE_HEIGHT * yIndex;

	spriteSheetTexture = kage::TextureManager::getTexture(filename);
	//spriteSheet.setTexture(*spriteSheetTexture);
	//spriteSheet.setTextureRect(sf::IntRect(x, y, SPRITE_WIDTH, SPRITE_HEIGHT));

	//std::cout << "X: " << x << " - " << y << std::endl;
	///spriteSheet.setPosition(sf::Vector2f(OFFSET_X + mapIndex * CELL_SIZE_X, OFFSET_Y + y * CELL_SIZE_Y));
	//spriteSheet.setPosition(sf::Vector2f(OFFSET_X + x * CELL_SIZE_X, OFFSET_Y + y * CELL_SIZE_Y));
}

void AnimatingSprites::UpdateAnimation()
{
	if (beginAnimation)
	{
		sf::Time time = clock.getElapsedTime();

		if (time.asMilliseconds() > speed)
		{
			int x = SPRITE_WIDTH * currentFrame.x;
			int y = SPRITE_HEIGHT * currentFrame.y;

			spriteSheet.setTextureRect(sf::IntRect(x, y, SPRITE_WIDTH, SPRITE_HEIGHT));
			currentFrame.x++;

			if (currentFrame.x > endFrame.x)
			{
				currentFrame.x = 0;
			}
			clock.restart();
		}
	}
}

void AnimatingSprites::RenderAnimation(sf::RenderWindow& window)
{
	window.draw(spriteSheet);
}

void AnimatingSprites::StartAnimation(sf::Vector2i positionIndexes,  sf::Vector2i startFrame, sf::Vector2i endFrame, int speed)
{
	
	this->positionIndexes = positionIndexes;
	this->startFrame = startFrame;
	this->endFrame = endFrame;
	this->speed = speed;

	beginAnimation = true;
	currentFrame = startFrame;
	
	spriteSheet.setTexture(*spriteSheetTexture);
	spriteSheet.setPosition(sf::Vector2f(OFFSET_X + positionIndexes.x * CELL_SIZE_X, OFFSET_Y + positionIndexes.y * CELL_SIZE_Y));
}  