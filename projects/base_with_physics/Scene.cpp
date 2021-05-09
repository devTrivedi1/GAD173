#include "Scene.h"

Scene::Scene() : 
	isRunning(false), isLoaded(false)
{

}

Scene::~Scene()
{
}

void Scene::Init()
{
}

void Scene::Load()
{
	isLoaded = true;
	isRunning = true;
	std::cout << "scene was loaded" << std::endl;
}

void Scene::Update()
{
}

void Scene::Render(sf::RenderWindow& window)
{
}
