#include "Asteroids.h"

// Private functions
void Asteroid::initShape()
{
	this->asteroid.setRadius(rand() % 20 + 20);
	this->asteroid.setPointCount(rand() % 20 + 3);
	this->asteroid.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, 255));
}

void Asteroid::initVariables()
{
	this->type = 0;
	this->speed = 5.0f;
	this->hpMax = 10;
	this->hp = 0;
	this->damage = 1;
	this->points = 5;
}

Asteroid::Asteroid(float pos_x, float pos_y)
{
	this->initShape();
	this->initVariables();
	this->asteroid.setPosition(pos_x, pos_y);
}

Asteroid::~Asteroid()
{

}

// Accessors
const sf::FloatRect Asteroid::getBounds() const
{
	return this->asteroid.getGlobalBounds();
}

// Public functions
void Asteroid::update()
{
	this->asteroid.move(0.0f, this->speed);
}

void Asteroid::render(sf::RenderTarget* target)
{
	target->draw(this->asteroid);
}
