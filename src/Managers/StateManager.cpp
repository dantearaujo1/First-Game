#include "../includes/Managers/StateManager.hpp"

#include "../includes/Game.hpp"

StateManager::StateManager(Game* game)
{
	m_game = game;
}

StateManager::~StateManager()
{

}

void StateManager::init()
{

}
void StateManager::shutdown()
{
	while(!m_states.empty())
	{
		AppState* temp = m_states.top();
		m_states.pop();
		temp->shutdown();
		delete temp;
		temp = nullptr;
	}

}

void StateManager::pushState(AppState* state)
{
	m_states.push(state);
	m_currentState = m_states.top();
	m_currentState->init();
}
void StateManager::popState()
{
	AppState* temp = m_states.top();
	m_states.pop();
	m_currentState = m_states.top();
	delete temp;
	temp = nullptr;
}

void StateManager::handleEvents(sf::Event e)
{
	assert(m_currentState);
	m_currentState->handleEvents(e);
}
void StateManager::update(sf::Time dt)
{
	assert(m_currentState);
	m_currentState->update(dt);
}
void StateManager::draw()
{
	assert(m_currentState);
	m_currentState->draw();
}

bool StateManager::isRunning()
{
	return m_currentState->getStatus();
}
