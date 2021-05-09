#include "example.h"
#include "Scenes/MainMenu.h"
#include "Scenes/FirstRound.h"
#include "Scenes/SecondRound.h"

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

	sceneManager.AddScene(new MainMenu());
	sceneManager.AddScene(new FirstRound());
	sceneManager.AddScene(new SecondRound());

	sceneManager.LoadScene(0);

	return true;
}

void Example::update(float deltaT)
{
	// You need to update the physics system every game update

	if (sceneManager.GetActiveSceneIndex() == 1)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			sceneManager.getActiveScene()->position.x -= 15;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			sceneManager.getActiveScene()->position.x += 15;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && sceneManager.GetActiveSceneIndex() == 0 && m_window.hasFocus())
	{
		sceneManager.LoadScene(1);
	}
	if (sceneManager.GetActiveSceneIndex() == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
	{
		sceneManager.LoadScene(2);
	}
	

	sceneManager.Update();

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
	mapTiles.TileRender(m_window);
	sceneManager.Render(m_window);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

