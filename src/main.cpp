#include "../includes/Tilemap.hpp"
#include "../includes/ResourceManager.hpp"
#include "SFML/Graphics/Rect.hpp"
#include <sstream>

void loadTextures(ResourceManager& mng)
{
  mng.loadTextureFromFile("tileset1","..\\assets\\Tilesets\\Pipoya RPG Tileset 32x32\\test.png");
  mng.loadTextureFromFile("tileset2","..\\assets\\Tilesets\\Pipoya RPG World Tileset 48x48 40x40 32x32\\32x32\\pipo-map001.png");
}


int main()
{
	// Some Temporary Constants
	constexpr int WIDTH = 800;
	constexpr int HEIGHT = 608;
	constexpr int screenSizeX = WIDTH / 32;
	constexpr int screenSizeY = HEIGHT / 32;

	sf::RenderWindow window;
	window.create(sf::VideoMode(WIDTH, HEIGHT), "SFML WORKS");

	sf::View gameView = window.getDefaultView();
	/* gameView.zoom(0.4f); */
	/* gameView.setCenter(sf::Vector2f(0.0f,0.0f)); */
	window.setView(gameView);

	// DEBUG INFO **************
	sf::Vector2i mousePosMonitor;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;

	sf::Text debugText;
	sf::Font font;
	font.loadFromFile("../assets/Fonts/arial.ttf");
	debugText.setFont(font);
	debugText.setFillColor(sf::Color::Red);
	debugText.setCharacterSize(20);

	bool running = true;
	bool debug = false;

	sf::Clock clock;
	float currentTime = 0.0f;
	float newTime = 0.0f;
	float dt = 0.0f;

	ResourceManager mng;
	loadTextures(mng);

	Tilemap map(&mng);
	map.setTexture("tileset1");
	const int tiles[screenSizeX * screenSizeY] =
	{
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
	};

	map.loadVertexBuffer(tiles,sf::Vector2u(32,32),screenSizeX,screenSizeY);

	sf::Event e;

	while (running)
	{
		currentTime = clock.getElapsedTime().asSeconds();
		dt = newTime - currentTime;
		newTime = currentTime;

		// Gettings Mouse relatives positions
		mousePosMonitor = sf::Mouse::getPosition();
		mousePosWindow = sf::Mouse::getPosition(window);
		mousePosView = window.mapPixelToCoords(mousePosWindow);
		mousePosGrid.x = static_cast<unsigned int>( mousePosView.x / 32.0f );
		mousePosGrid.y = static_cast<unsigned int>( mousePosView.y / 32.0f );
		if (mousePosGrid.x <= 0) mousePosGrid.x = 0;
		if (mousePosGrid.y <= 0) mousePosGrid.y = 0;

		if(debug)
		{
			std::stringstream debugString;
			debugString	<< "Monitor coordinates: (" << mousePosMonitor.x << "," << mousePosMonitor.y << ")"<< "\n"
						<< "Window coordinates: (" << mousePosWindow.x << "," << mousePosWindow.y << ")"<< "\n"
						<< "View coordinates: (" << mousePosView.x << "," << mousePosView.y << ")"<< "\n"
						<< "Grid coordinates: (" << mousePosGrid.x << "," << mousePosGrid.y << ")"<< "\n";

			debugText.setString(debugString.str());
		}

		while (window.pollEvent(e))
		{
			if (e.type <= sf::Event::Closed)
			{
				running = false;
				window.close();
			}
			if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::Escape)
				{
					running = false;
					window.close();
				}
				if (e.key.code == sf::Keyboard::Q)
				{
					debug = !debug;
				}
			}
		}


		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
		{
			gameView.move(sf::Vector2f(1.0f,0.0f));
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
		{
			gameView.move(sf::Vector2f(-1.0f,0.0f));
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
		{
			gameView.move(sf::Vector2f(0.0f,-1.0f));
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
		{
			gameView.move(sf::Vector2f(0.0f,1.0f));
		}



		window.clear(sf::Color::Black);
		window.setView(gameView);
		window.draw(map);

		if (debug)
		{
			window.setView(window.getDefaultView());
			window.draw(debugText);
			window.setView(gameView);
		}
		window.display();
	}
}
