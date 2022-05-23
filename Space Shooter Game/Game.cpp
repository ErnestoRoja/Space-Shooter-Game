#include "Game.h"

// Private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Space Shooter", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["Bullet"] = new sf::Texture();
	this->textures["Bullet"]->loadFromFile("Textures/bullet.png");
}

void Game::initPlayer()
{
	this->player = new Player();
}

// Constructor
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initPlayer();
}

// Destructor
Game::~Game()
{
	delete this->window;
	delete this->player;

	// Delete all textures
	for (auto& i : this->textures) 
	{
		delete i.second;
	}

	// Delete all bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}
}

void Game::run()
{

	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}

}

void Game::updatePollEvents()
{
	sf::Event ev;
	while (this->window->pollEvent(ev))
	{
		if (ev.Event::type == sf::Event::Closed || ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::updateInput()
{
	// Player movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.0f, -1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.0f, 1.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttacK())
	{
		this->bullets.push_back(new Gun(this->textures["Bullet"], this->player->getPos().x, this->player->getPos().y, 0.0f, -5.0f, 5.0f));
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;

	for (auto* bullet : this->bullets)
	{
		bullet->update();

		// Bullet remove off-screen (top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.0f)
		{
			// Delete bullet 
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

// Frame handling
void Game::update()
{
	this->updatePollEvents();
	this->updateInput();
	this->player->update();
	this->updateBullets();
}

void Game::render()
{
	this->window->clear();

	// Draw all the pixels
	this->player->render(*this->window);
	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	this->window->display();
}
