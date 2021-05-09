#include "SaveLoad.h"


SaveLoad::SaveLoad()
{
	
}

SaveLoad::~SaveLoad()
{

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