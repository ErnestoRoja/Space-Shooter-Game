#include "Asteroids.h"

// Private functions
void Asteroid::initVariables()
{
	this->pointReward = rand() % 5 + 3; // Random from 0 - 7: Min of 3, Max of 10.
	this->type = 0;
	this->speed = static_cast<float>(this->pointReward);
	this->hpMax = static_cast<int>(this->pointReward);
	this->hp = this->hpMax;
	this->damage = (50 / this->pointReward);
	this->points = this->pointReward;
}

void Asteroid::initShape()
{
	this->asteroid.setRadius(200 / this->pointReward);
	this->asteroid.setPointCount(this->pointReward);
	this->asteroid.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, 255));
}

Asteroid::Asteroid(float pos_x, float pos_y)
{
	this->initVariables();
	this->initShape();
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

const int& Asteroid::getPoints() const
{
	return this->points;
}

const int& Asteroid::getDamage() const
{
	return this->damage;
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
