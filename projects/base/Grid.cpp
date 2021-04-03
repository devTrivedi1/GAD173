#pragma once
#include "Grid.h"
#include <SFML/Graphics.hpp>

Grid::Grid() 
{
	for (size_t i = 0; i < GRID_X_NUMBERS; i++)
	{
		xLines[i].setSize(sf::Vector2f(CELL_SIZE, 1.5f));
		xLines[i].setPosition(sf::Vector2f(HORIZONTAL_OFFSET_X, HORIZONTAL_OFFSET_Y + i * CELL_HEIGHT)); 
	}

	for (size_t i = 0; i < GRID_Y_NUMBERS; i++)
	{
		yLines[i].setSize(sf::Vector2f(1.5f, CELL_SIZE));
		yLines[i].setPosition(sf::Vector2f(VERTICAL_OFFSET_X + i * CELL_WIDTH, VERTICAL_OFFSET_Y));
	}
}

Grid::~Grid()
{

}

void Grid::gridRender(sf::RenderWindow& window)
{
	for (size_t i = 0; i < GRID_X_NUMBERS; i++)
	{
		window.draw(xLines[i]);
	}

	for (size_t i = 0; i < GRID_Y_NUMBERS; i++)
	{
		window.draw(yLines[i]);
	}
}