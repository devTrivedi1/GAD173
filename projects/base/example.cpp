#include <iostream>
#include "example.h"


Example::Example(): App()
{
}

Example::~Example()
{
	
}

Example &Example::inst()
{ 
	static Example s_instance; 
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	map.LoadTexture();
	map.MapLoad();
	animation.InitAnimation();
	animation.LoadAnimation("data/Textures-Sprites/Breakout-SpriteSheet.png");
	animation.StartAnimation(sf::Vector2i(0, 0), sf::Vector2i(2, 3), 100);
	return true;
}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	sf::Vector2i mouseCoordinates = sf::Mouse::getPosition(m_window);

	ImGui::Begin("Kage2D", 0, ImGuiWindowFlags_MenuBar);
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				m_running = false;
			}
			if (ImGui::MenuItem("Save"))
			{
				SaveLoad::Save("data/SaveFiles/MapLayout.txt", map.map, 12, 12);
			}
			if (ImGui::MenuItem("Load"))
			{
				SaveLoad::Load("data/SaveFiles/MapLayout.txt", map.map, TOTAL_CELLS);
				map.MapLoad();
				
			}
			if (ImGui::MenuItem("Select colour"))
			{
				showColourWindow = true;
			}
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	ImGui::End();
	if (showColourWindow)
	{
		ImGui::Begin("Colours");
		map.ButtonImages(m_window);
		ImGui::End();
	}

	map.DeletingTexture(m_window, mouseCoordinates);
	map.UpdatingTexture(m_window, mouseCoordinates);
	animation.UpdateAnimation();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	map.TileRender(m_window);
	Lines.gridRender(m_window);
	animation.RenderAnimation(m_window);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}