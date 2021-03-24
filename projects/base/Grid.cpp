#pragma once
#include "Grid.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Grid::Grid() 
{
	for (size_t i = 0; i < X_LINES; i++)
	{

		xLines[i].setSize(sf::Vector2f(1442, 2.5f));
		xLines[i].setPosition(sf::Vector2f(200, 25 + i * 40));

	}

	for (size_t i = 0; i < Y_LINES; i++)
	{

		yLines[i].setSize(sf::Vector2f(2.5f, 962));
		yLines[i].setPosition(sf::Vector2f(200 + i * 120, 25));

	}
}


Grid::~Grid()
{

}

void Grid::Render(sf::RenderWindow &window)
{
	for (size_t i = 0; i < X_LINES; i++)
	{
		window.draw(xLines[i]);
	}

	for (size_t i = 0; i < Y_LINES; i++)
	{
		window.draw(yLines[i]);
	}
}