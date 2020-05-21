#ifndef APPSTATE_HPP
#define APPSTATE_HPP

#include <stack>
#include <assert.h>

#include "SFML/Graphics.hpp"


// Forward Declarations
class StateManager;
class Game;

/*! \class AppState
*  \brief Base Class for handling states of the application.
*
*  Our Application can have different states for drawing and updating
*  stuffs on the screen, so this will be the base class that will be inheritted
*  for all other appstates that i might have.
*/
class AppState
{
	public:

		AppState(Game* game) {m_game = game;}
		virtual ~AppState(){};

		virtual void        init() = 0;
		virtual void        shutdown() = 0;

		virtual void        handleEvents(sf::Event e) = 0;
		virtual void        update(sf::Time dt) = 0;
		virtual void        draw() = 0;

		void pause()     {m_running = false;}
		void resume()    {m_running = true;}
		bool getStatus() {return m_running;}

	protected:

		bool          m_running; /*!< A Boolean representing if the state is on or off */
		StateManager* m_mng; /*!< An pointer to the Manager of this Class */
		Game*         m_game;
};


#endif
