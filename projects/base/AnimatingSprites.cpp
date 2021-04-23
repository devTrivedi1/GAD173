#include "AnimatingSprites.h"
#include <kage2dutil/texture_manager.h>

#define SPRITE_WIDTH 386
#define SPRITE_HEIGHT 130

AnimatingSprites::AnimatingSprites():
	spriteSheetTexture(nullptr)
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
	xIndex = 0;
	yIndex = 0;

	int x = SPRITE_WIDTH * xIndex;
	int y = SPRITE_HEIGHT * yIndex;

	spriteSheetTexture = kage::TextureManager::getTexture(filename);
	spriteSheet.setTexture(*spriteSheetTexture);
	spriteSheet.setTextureRect(sf::IntRect(x, y, SPRITE_WIDTH, SPRITE_HEIGHT));
	
}
void AnimatingSprites::UpdateAnimation()
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
void AnimatingSprites::RenderAnimation(sf::RenderWindow& window)
{
	window.draw(spriteSheet);
}

void AnimatingSprites::StartAnimation(sf::Vector2i startFrame, sf::Vector2i endFrame, int speed)
{
	this->startFrame = startFrame;
	this->endFrame = endFrame;
	this->speed = speed;

	beginAnimation = true;
	currentFrame = startFrame;
}  
