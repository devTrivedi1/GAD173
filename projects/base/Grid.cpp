#pragma once
#include "Grid.h"
#include <SFML/Graphics.hpp>

Grid::Grid() 
{
	for (size_t i = 0; i < GRID_HORIZONTAL_LINES_COUNT; i++)
	{
		xLines[i].setSize(sf::Vector2f(CELL_LENGTH_X, 1.5f));
		xLines[i].setPosition(sf::Vector2f(OFFSET_X, OFFSET_Y + i * CELL_SIZE_Y)); 
	}

	for (size_t i = 0; i < GRID_VERTICAL_LINES_COUNT; i++)
	{
		yLines[i].setSize(sf::Vector2f(1.5f, CELL_LENGTH_Y));
		yLines[i].setPosition(sf::Vector2f(OFFSET_X + i * CELL_SIZE_X, OFFSET_Y));
	}
}

Grid::~Grid()
{

}

void Grid::gridRender(sf::RenderWindow& window)
{
	for (size_t i = 0; i < GRID_HORIZONTAL_LINES_COUNT; i++)
	{
		window.draw(xLines[i]);
	}

	for (size_t i = 0; i < GRID_VERTICAL_LINES_COUNT; i++)
	{
		window.draw(yLines[i]);
	}
}