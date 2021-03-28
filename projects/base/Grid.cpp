#pragma once
#include "Grid.h"
#include <SFML/Graphics.hpp>



void Grid::gridRender(sf::RenderWindow& window)
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


Grid::Grid() 
{
	for (size_t i = 0; i < X_LINES; i++)
	{

		xLines[i].setSize(sf::Vector2f(1442, 1.5f));
		xLines[i].setPosition(sf::Vector2f(250, 250 + i * CELL_HEIGHT));

	}

	for (size_t i = 0; i < Y_LINES; i++)
	{

		yLines[i].setSize(sf::Vector2f(1.5f, 480));
		yLines[i].setPosition(sf::Vector2f(250 + i * CELL_WIDTH, 250));
	}
}


Grid::~Grid()
{

}

