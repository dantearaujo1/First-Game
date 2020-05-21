#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include "../States/AppState.hpp"

/*! \class StateManager
*  \brief Manager for States
*
*  Used to handle, store, update and render all the
*  states that our application will have
*/
class StateManager
{
	public:

		StateManager(Game* game);
		~StateManager();

		void init();
		void shutdown();

		void pushState(AppState* state);
		void popState();

		void handleEvents(sf::Event e);
		void update(sf::Time dt);
		void draw();

		bool isRunning();


	private:


		std::stack<AppState*> m_states; /*!< Stack of States for storing all the states */
		AppState*             m_currentState; /*!< Currently used stack. Probably the stack of the top */
		Game*                 m_game;

};
#endif
