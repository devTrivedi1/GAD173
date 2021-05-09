#include "FirstRound.h"


FirstRound::FirstRound()
{
}

FirstRound::~FirstRound()
{
}

void FirstRound::Init()
{
}

void FirstRound::Load()
{
	Scene::Load();
	
	load.Load("data/SaveFiles/MapLayout.txt", loadTile.map, TOTAL_CELLS); //SaveLoad

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

void FirstRound::Update()
{
	if (ballPosition.y >= -700)
	{
		ballPosition.x -= 1;
		ballPosition.y -= 1;
	}
	else if(ballPosition.y >= 200)
	{
		ballPosition.x += 1;
		ballPosition.y += 1;
	}
	Scene::Update();
	paddle.setPosition(position);
	ball.setPosition(ballPosition);
}

void FirstRound::Render(sf::RenderWindow& window)
{
	//grid.gridRender(window);
	loadTile.TileRender(window);
	window.draw(paddle);
	window.draw(ball);
	Scene::Render(window);
}