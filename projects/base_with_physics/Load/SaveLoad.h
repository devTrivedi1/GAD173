#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Tiles/Tiles.h"
#include "Grid/Grid.h"

class SaveLoad
{
public:
	SaveLoad();
	~SaveLoad();

	Tiles load;

	static void Load(std::string mapSave, int* buffer, int mapSize);
};