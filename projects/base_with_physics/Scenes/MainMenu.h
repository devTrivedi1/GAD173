#pragma once
#include "Scene.h"

class MainMenu : public Scene
{
private:
	sf::Texture *mainMenuTexture;
	sf::Sprite mainmenuSprite;

public:
	MainMenu();
	~MainMenu();

	void Init() override;
	void Load() override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;
};

