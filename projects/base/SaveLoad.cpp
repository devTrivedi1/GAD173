#include "SaveLoad.h"
#include <fstream>


SaveLoad::SaveLoad()
{
	
}

SaveLoad::~SaveLoad()
{

}

void SaveLoad::Save(std::string mapSave, int* buffer, int Y_COUNT, int X_COUNT)
{
	std::ofstream saveMap;
	saveMap.open(mapSave);
	for (size_t y = 0; y < Y_COUNT; y++)
	{
		for (size_t x = 0; x < X_COUNT; x++)
		{
			int i = x + y * X_COUNT;
			saveMap << buffer[i] << ", ";
		}
		saveMap << std::endl;
	}
	saveMap.close();
}

void SaveLoad::Load(std::string mapSave)
{

}
