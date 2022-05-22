#include "Player.h"

void Player::initTexture()
{
	// Load a texture from file
}

void Player::initSprite()
{
	// Set the texture to the sprite
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
