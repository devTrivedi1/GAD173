#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(int sceneIndex)
{
	currentSceneIndex = sceneIndex;
	Scene* scene = scenes[currentSceneIndex];
	if (scene == nullptr)
		return;
	scene->Load();
}

void SceneManager::AddScene(Scene* scene)
{
	scenes.push_back(scene);
}

void SceneManager::RemoveScene(int sceneIndex)
{
}

void SceneManager::Load()
{
}

void SceneManager::Update()
{
	if(scenes.size() > 0)
	   scenes[currentSceneIndex]->Update();
}

void SceneManager::Render(sf::RenderWindow& window)
{
	if(scenes.size() > 0)
	   scenes[currentSceneIndex]->Render(window);
}
