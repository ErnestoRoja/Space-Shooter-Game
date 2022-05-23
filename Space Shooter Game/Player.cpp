#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 10.0f;
	this->attackCooldownMax = 10.0f;
	this->attackCooldown = this->attackCooldownMax;
}

void Player::initTexture()
{
	// Load a texture from file
	if (!this->texture.loadFromFile("Textures/ship.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load ship texture." << std::endl;
	}

}

void Player::initSprite()
{
	// Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	// Resize the sprite
	this->sprite.scale(0.2f, 0.2f);
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttacK()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.0f;
		return true;
	}
	return false;
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	this->attackCooldown += 0.5f;
}

void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
