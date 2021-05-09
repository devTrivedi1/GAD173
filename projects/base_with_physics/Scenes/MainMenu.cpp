#include "MainMenu.h"
#include "kage2dutil/texture_manager.h"

MainMenu::MainMenu()
{
	mainMenuTexture = kage::TextureManager::getTexture("data/Textures-Sprites/MainMenu.png");
}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
	
}

void MainMenu::Load()
{
	
	mainmenuSprite.setTexture(*mainMenuTexture);
	std::cout << "main menu load" << std::endl;
	Scene::Load();
}

void MainMenu::Update()
{
	std::cout << "UpdateMainMenu function" << std::endl;
	Scene::Update();
}

void MainMenu::Render(sf::RenderWindow& window)
{
	window.draw(mainmenuSprite);
	std::cout << "Mainmenu Render function" << std::endl;
}
