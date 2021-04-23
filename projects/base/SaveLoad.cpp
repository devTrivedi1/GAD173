#include "SaveLoad.h"


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

void SaveLoad::Load(std::string mapSave, int* buffer, int mapSize)
{

	std::string line;
	std::ifstream myfile(mapSave);
	int i = 0;

	if (myfile.is_open())
	{
		int commaIndex = -1;

		while (std::getline(myfile, line))
		{
			while (true)
			{
				int cutStart = commaIndex + 1;
				commaIndex = line.find(',', commaIndex + 1);

				std::string numStr = line.substr(cutStart, commaIndex - cutStart);

				if (commaIndex < 0)
					break;

				int num = std::stoi(numStr);
				buffer[i] = num;
				i++;
				std::cout << num << " ";
			}
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "Cannot open file" << std::endl;
	}
}