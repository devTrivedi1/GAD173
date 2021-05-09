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

	loadTile.LoadTexture();
	loadTile.MapLoad();
	load.Load("data/SaveFiles/MapLayout2.txt", loadTile.map, TOTAL_CELLS);
	loadAnimation.LoadAnimation("data\Textures-Sprites\Breakout-SpriteSheet.png");
}

void SecondRound::Update()
{
}

void SecondRound::Render(sf::RenderWindow& window)
{
	grid.gridRender(window);
	loadTile.TileRender(window);

	Scene::Render(window);
}
