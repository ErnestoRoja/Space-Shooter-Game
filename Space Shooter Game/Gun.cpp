#include "Gun.h"

Gun::Gun()
{

}

Gun::Gun(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	// Set the texture and assign variables
	this->bullet.setTexture(*texture);
	this->bullet.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;

	// Scale the bullets
	this->bullet.scale(0.1f, 0.1f);
}

Gun::~Gun()
{
	
}

// Accessor
const sf::FloatRect Gun::getBounds() const
{
	return this->bullet.getGlobalBounds();
}

// Public functions
void Gun::update()
{
	this->bullet.move(this->movementSpeed * this->direction);
}

void Gun::render(sf::RenderTarget* target)
{
	target->draw(this->bullet);
}