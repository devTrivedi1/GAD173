#include "example.h"
#include "Grid.h"


using namespace sf;

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
	
	return true;

}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	xLines.Render(m_window);
	yLines.Render(m_window);

}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

