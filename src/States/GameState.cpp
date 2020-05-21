#include "../../includes/States/GameState.hpp"

#include "../../includes/Game.hpp"

GameState::GameState(Game* game) : AppState(game)
{
	m_game = game;
	m_debug = false;
}
GameState::~GameState()
{

}

void GameState::init()
{

}
void GameState::shutdown()
{

}
void GameState::handleEvents(sf::Event e)
{
	ImGui::SFML::ProcessEvent(e);
	if (e.type <= sf::Event::Closed)
	{
		pause();
		m_game->getWindow().close();
	}
	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::Escape)
		{
			pause();
			m_game->getWindow().close();
		}
		if (e.key.code == sf::Keyboard::Q)
		{
			m_debug = !m_debug;
		}
	}

}
void GameState::update(sf::Time dt)
{
	if(m_debug)
	{
		std::stringstream debugString;
		debugString	<< "Monitor coordinates: (" << mousePosMonitor.x << "," << mousePosMonitor.y << ")"<< "\n"
					<< "Window coordinates: (" << mousePosWindow.x << "," << mousePosWindow.y << ")"<< "\n"
					<< "View coordinates: (" << mousePosView.x << "," << mousePosView.y << ")"<< "\n"
					<< "Grid coordinates: (" << mousePosGrid.x << "," << mousePosGrid.y << ")"<< "\n"
					<< "FPS: " <<  ( 1/dt.asSeconds() ) <<"\n";

		debugText.setString(debugString.str());
		tileSelector.setPosition(static_cast<sf::Vector2f>( mousePosGrid ) * static_cast<float>( tileSizeX ));
	}
	ImGui::SFML::Update(m_game->getWindow(), dt);

	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
	{
		m_game->getGameView().move(sf::Vector2f(1.0f,0.0f));
	}
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
	{
		m_game->getGameView().move(sf::Vector2f(-1.0f,0.0f));
	}
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
	{
		m_game->getGameView().move(sf::Vector2f(0.0f,-1.0f));
	}
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
	{
		m_game->getGameView().move(sf::Vector2f(0.0f,1.0f));
	}

}
void GameState::draw()
{
	sf::RenderWindow& window = m_game->getWindow();

	// Rendering things on Screen starts After next line
	// Setting A Game View to Draw into.
	// And draw game things
	window.clear(sf::Color::Black);
	window.setView(m_game->getGameView());

	/* m_game->getWindow().draw(map); */

	//Debug Information that is Printed static in the Window
	//Should be put after setting the View to the Default.
	if (m_debug)
	{
		window.setView(window.getDefaultView());

		ImGui::Begin("First GUI Window");
		ImGui::Button("Button", sf::Vector2u(100,40));
		ImGui::Checkbox("Show FPS", );
		ImGui::End();

	}

	/* window.draw(debugText); */

	ImGui::SFML::Render(window);


	window.display();

}

