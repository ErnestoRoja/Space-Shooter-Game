#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{

}

GameState::~GameState()
{

}

void GameState::endState()
{
	std::cout << "Ending game state" << std::endl;
}

void GameState::updateKeybinds(const float& dt)
{
	this->checkForQuit();
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeybinds(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << "A" << std::endl;
	}
}

void GameState::render(sf::RenderTarget* target)
{

}
