#pragma once
#include "Grid.h"
#include <SFML/Graphics.hpp>



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


Grid::Grid() 
{
	for (size_t i = 0; i < GRID_X_NUMBERS; i++)
	{

		xLines[i].setSize(sf::Vector2f(CELL_SIZE, 1.5f));
		xLines[i].setPosition(sf::Vector2f(OFFSET_X, OFFSET_Y + i * CELL_SPACING_Y)); 

	}

	for (size_t i = 0; i < GRID_Y_NUMBERS; i++)
	{

		yLines[i].setSize(sf::Vector2f(1.5f, CELL_SIZE));
		yLines[i].setPosition(sf::Vector2f(OFFSET_X + i * CELL_SPACING_X, OFFSET_Y));
	}
}


Grid::~Grid()
{

}

