#ifndef GAME_H
#define GAME_H

// System Headers
#include <sstream>

// Project Headers
#include "Managers/ResourceManager.hpp"
#include "Managers/StateManager.hpp"
#include "Tiles/Tilemap.hpp"
#include "States/GameState.hpp"

// 3rd-Party libraries
#include "SFML/Graphics/Rect.hpp"
#include "imgui.h"
#include "imgui-SFML.h"


class Game
{
private:

	void update();
	void draw();
	void handleEvents();

public:

	Game();
	virtual ~Game();

	bool    init();
	bool    shutdown();

	sf::RenderWindow& getWindow() {return m_window;}
	sf::View& getGameView() {return m_gameView;}

	void    run();

private:

	ResourceManager  m_resourceMng;
	StateManager	 m_stateMng;
	sf::RenderWindow m_window;
	sf::View         m_gameView;
	sf::Clock        m_clock;
};

#endif /* GAME_H */
