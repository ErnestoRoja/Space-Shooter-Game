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

void Game::initGUI()
{
	// Load font
	if (!this->font.loadFromFile("Fonts/wence.otf"))
	{
		std::cout << "ERROR::GAME::INITGUI::Could not load font." << std::endl;
	}

	// Init point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::White);

	// Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.0f, 25.0f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(0.0f, 50.0f));

	this->playerHpBarBackground = this->playerHpBar;
	this->playerHpBarBackground.setFillColor(sf::Color(25, 25, 25, 200));

	// Init game over text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setPosition(this->window->getSize().x / 2.0f - this->gameOverText.getGlobalBounds().width / 2.0f, this->window->getSize().y / 2.0f - this->gameOverText.getGlobalBounds().height / 2.0f);
}

void Game::initBackground()
{
	if (!this->backgroundTexture.loadFromFile("Textures/background.png"))
	{
		std::cout << "ERROR::GAME::INITBACKGROUND::Could not load background texture." << std::endl;
	}
	this->background.setTexture(this->backgroundTexture);
}

void Game::initPoints()
{
	this->points = 0;
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initAsteroids()
{
	this->spawnTimerMax = 35.0f;
	this->spawnTimer = this->spawnTimerMax;
}

// Constructor
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initBackground();
	this->initPoints();
	this->initPlayer();
	this->initAsteroids();
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

	// Delete all asteroids
	for (auto* i : this->asteroids)
	{
		delete i;
	}
}

// Public functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvents();

		if (this->player->getHp() > 0)
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

	// Create new bullet when spacebar is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttacK())
	{
		this->bullets.push_back(new Gun(this->textures["Bullet"], (this->player->getPos().x + this->player->getBounds().width / 2.0f) - 20.0f, this->player->getPos().y, 0.0f, -5.0f, 5.0f));
	}
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Points: " << this->points;
	this->pointText.setString(ss.str());

	// Update player hp bar
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.0f * hpPercent, this->playerHpBar.getSize().y));
}

void Game::updateBackground()
{

}

void Game::updateCollision()
{
	// Left world collision
	if (this->player->getBounds().left < 0.0f)
	{
		this->player->setPosition(0.0f, this->player->getBounds().top);
	}
	// Right world collision
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}

	// Top world collision
	if (this->player->getBounds().top < 0.0f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.0f);
	}
	// Bottom world collision
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
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
		}
		++counter;
	}
}

void Game::updateAsteroids()
{
	// Spawning asteroids
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->asteroids.push_back(new Asteroid(rand() % this->window->getSize().x, -10.0f));
		this->spawnTimer = 0.0f;
	}

	unsigned counter = 0;
	for (auto* asteroid : this->asteroids)
	{
		asteroid->update();

		// Asteroid remove off-screen (bottom of screen)
		if (asteroid->getBounds().top > this->window->getSize().y)
		{
			// Decrease player hp
			this->player->loseHp(this->asteroids.at(counter)->getDamage());
			// Delete asteroid
			delete this->asteroids.at(counter);
			this->asteroids.erase(this->asteroids.begin() + counter);
			
		}
		// Remove asteroid when colliding with player
		else if (asteroid->getBounds().intersects(this->player->getBounds()))
		{
			// Decrease player hp
			this->player->loseHp(this->asteroids.at(counter)->getDamage());
			// Delete asteroid
			delete this->asteroids.at(counter);
			this->asteroids.erase(this->asteroids.begin() + counter);
			
		}
		++counter;
	}
}

void Game::updateCombat()
{
	for (unsigned int i = 0; i < this->asteroids.size(); ++i)
	{
		bool enemyRemoved = false;
		this->asteroids[i]->update();

		for (unsigned int k = 0; k < this->bullets.size() && enemyRemoved == false; k++)
		{
			if (this->asteroids[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->points += this->asteroids[i]->getPoints();

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				delete this->asteroids[i];
				this->asteroids.erase(this->asteroids.begin() + i);
				enemyRemoved = true;

			}
		}
	}
}

void Game::update()
{
	this->updateInput();
	this->player->update();
	this->updateCollision();
	this->updateBullets();
	this->updateAsteroids();
	this->updateCombat();
	this->updateGUI();
	this->updateBackground();
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBackground);
	this->window->draw(this->playerHpBar);
}

void Game::renderBackground()
{
	this->window->draw(this->background);
}

void Game::render()
{
	this->window->clear();

	// Draw background
	this->renderBackground();

	// Draw the player, bullets, and asteroids
	this->player->render(*this->window);

	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto* asteroid : this->asteroids)
	{
		asteroid->render(this->window);
	}

	// Draw GUI
	this->renderGUI();

	// Draw game over screen
	if (this->player->getHp() <= 0)
		this->window->draw(this->gameOverText);

	this->window->display();
}