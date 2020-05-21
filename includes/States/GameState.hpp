#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "AppState.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

/*! \class GameState
*  \brief  Class representing the playable
*          state of the game
*
*  Detailed description
*/
class GameState : public AppState
{
public:

	GameState(Game* game);
	~GameState();

	void handleEvents(sf::Event e) override;
	void update(sf::Time dt) override;
	void draw() override;

	void init() override;
	void shutdown() override;

private:

	bool m_debug;

};

#endif
