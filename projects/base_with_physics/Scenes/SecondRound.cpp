#include "SecondRound.h"


SecondRound::SecondRound()
{

}

SecondRound::~SecondRound()
{

}

void SecondRound::Init()
{
}

void SecondRound::Load()
{

	Scene::Load();

	load.Load("data/SaveFiles/MapLayout2.txt", loadTile.map, TOTAL_CELLS); //SaveLoad

	loadTile.LoadTexture(); //Tiles
	loadTile.MapLoad();

	loadAnimation.LoadAnimation("data/Textures-Sprites/Breakout-SpriteSheet.png"); //Animation

	paddle.setSize(sf::Vector2f(100, 20));
	paddle.setFillColor(sf::Color::Black);
	paddle.setOutlineThickness(2);
	paddle.setOutlineColor(sf::Color::White);

	ball.setRadius(12);
	ball.setFillColor(sf::Color::Blue);
	ball.setOutlineThickness(1);
	ball.setOutlineColor(sf::Color::White);

	position.x = 750;
	position.y = 710;

	ballPosition.x = 750;
	ballPosition.y = 710;
}

void SecondRound::Update()
{
	if (ballPosition.y >= -700)
	{
		ballPosition.x -= 2;
		ballPosition.y -= 2;
	}
	else if (ballPosition.y >= 200)
	{
		ballPosition.x += 3;
		ballPosition.y += 3;
	}
	Scene::Update();
	paddle.setPosition(position);
	ball.setPosition(ballPosition);
}

void SecondRound::Render(sf::RenderWindow& window)
{
	loadTile.TileRender(window);
	window.draw(paddle);
	window.draw(ball);
	Scene::Render(window);
}
