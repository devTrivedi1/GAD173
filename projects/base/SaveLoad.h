#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Tiles.h"
#include "Grid.h"

class SaveLoad
{
public:
	SaveLoad();
	~SaveLoad();

	Tiles load;

	static void Save(std::string mapSave, int* buffer, int Y_COUNT, int X_COUNT);
	static void Load(std::string mapSave, int* buffer, int mapSize);
};