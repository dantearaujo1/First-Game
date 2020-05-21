#include "../includes/Game.hpp"


bool Game::init()
{
	m_resourceMng.loadTextureFromFile("tileset1","..\\assets\\Tilesets\\Pipoya RPG Tileset 32x32\\test.png");
	m_resourceMng.loadTextureFromFile("tileset2","..\\assets\\Tilesets\\Pipoya RPG World Tileset 48x48 40x40 32x32\\32x32\\pipo-map001.png");

	AppState* gameState = new GameState(this);
	m_stateMng.pushState(gameState);

	m_window.create(sf::VideoMode(800,600), "SFML WORKS");
	m_window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(m_window);

	m_gameView = m_window.getDefaultView();
	m_window.setView(m_gameView);
	return true;
}
bool Game::shutdown()
{
	return true;
}
void Game::update()
{

}

void Game::draw()
{

}
void Game::handleEvents()
{

}
Game::Game() : m_stateMng(this)
{
}
Game::~Game()
{

}

void Game::run()
{
	sf::Time currentTime;
	sf::Time newTime;
	sf::Time dt;
	bool running = true;

	// Some Temporary Constants
	constexpr int WIDTH = 800;
	constexpr int HEIGHT = 608;
	constexpr int screenSizeX = WIDTH / 32;
	constexpr int screenSizeY = HEIGHT / 32;
	constexpr int tileSizeX = 32;
	constexpr int tileSizeY = 32;

	/* bool checkbox_FPS = false; */
	/* bool checkbox_TILEPOSITION = false; */
	/* bool checkbox_WORLDCOORDINATES = false; */

	int test = screenSizeX + screenSizeY;
	test += 1;

	// DEBUG INFO **************
	sf::Vector2i mousePosMonitor;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;

	sf::Font font;
	font.loadFromFile("../assets/Fonts/arial.ttf");

	sf::Text debugText;
	debugText.setFont(font);
	debugText.setFillColor(sf::Color::Red);
	debugText.setCharacterSize(20);

	sf::RectangleShape tileSelector;
	tileSelector.setFillColor(sf::Color::Green);
	tileSelector.setSize(sf::Vector2f(static_cast<float> ( tileSizeX ), static_cast<float> ( tileSizeY )));

	sf::Event e;

	while (running)
	{
		// Calculating how much time a frame has and
		// storing this value in a dt variable
		currentTime = m_clock.getElapsedTime();
		dt = currentTime- newTime ;
		newTime = currentTime;

		// Gettings Mouse relatives positions
		// To the Monitor, Screen, View and Grid;
		mousePosMonitor = sf::Mouse::getPosition();
		mousePosWindow = sf::Mouse::getPosition(m_window);
		mousePosView = m_window.mapPixelToCoords(mousePosWindow);
		if (mousePosView.x <= 0)
		{
			mousePosView.x = 0;
		}
		if (mousePosView.y <= 0)
		{
			mousePosView.y = 0;
		}
		mousePosGrid.x = static_cast<unsigned int>( mousePosView.x / tileSizeX );
		mousePosGrid.y = static_cast<unsigned int>( mousePosView.y / tileSizeY );


		while (m_window.pollEvent(e))
		{
			m_stateMng.handleEvents(e);
		}

		m_stateMng.update(dt);
		m_stateMng.draw();
	}

}
