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

	std::string number = "GAME OVER MUSTAFA HAHA xD !!!!!";
	std::string str1 = number.substr(0, 4);
	std::string str2 = number.substr(5, 4);
	std::string str3 = number.substr(10, 7);
	std::string str4 = number.substr(18, 4);
	std::string str5 = number.substr(23, 2);
	std::string str6 = number.substr(25, 4);

	std::cout << number << std::endl;

}

void SaveLoad::Load(std::string mapSave)
{

}
