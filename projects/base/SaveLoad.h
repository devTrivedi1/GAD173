#pragma once
#include <iostream>


class SaveLoad
{
public:
	SaveLoad();
	~SaveLoad();

	static void Save(std::string mapSave, int* buffer, int Y_COUNT, int X_COUNT);
	static void Load(std::string mapSave);
};

