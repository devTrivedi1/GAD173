#pragma once
#include <SFML/Graphics.hpp>


class Scene
{
public:
	Scene();
	~Scene();

	void Init();
	void Load();
	void Update();
	void Render(sf::RenderWindow& window);
};

