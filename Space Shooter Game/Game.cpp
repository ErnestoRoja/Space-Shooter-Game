#include "Game.h"

// Private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Space Shooter", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

// Constructor
Game::Game()
{
	this->initWindow();
}

// Destructor
Game::~Game()
{
	delete this->window;
}

void Game::run()
{

	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}

}

// Frame handling
void Game::update()
{
	sf::Event ev;
	while (this->window->pollEvent(ev))
	{
		if (ev.Event::type == sf::Event::Closed || ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}

}

void Game::render()
{
	this->window->clear();

	// Draw all the pixels

	this->window->display();
}
