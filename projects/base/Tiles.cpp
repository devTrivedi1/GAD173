#include <iostream>
#include "Tiles.h"



Tiles::Tiles()	
{
	
}
Tiles::~Tiles()
{

}

void Tiles::MapLayout()
{

	for (size_t y = 0; y < 12; y++)
		{

			for (size_t x = 0; x < 12; x++)
			{

				int i = x + y * 12;

				if (map[i] == 0)
				{
					std::cout << "L, ";
				}

				if (map[i] == 1)
				{
					std::cout << "T, ";
				}

				if (map[i] == 2)
				{
					std::cout << "W, ";
				}

				if (map[i] == 3)
				{
					std::cout << "F, ";
				}

			}
			std::cout << "\n";
		}
}

void Tiles::TileRender(sf::RenderWindow& window)
{
	

}






