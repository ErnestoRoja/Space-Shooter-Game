#pragma once
#include "Gun.h"

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax;

	// Private functions
	void initVariables();
	void initTexture();
	void initSprite();

public:
	Player();
	virtual ~Player();

	// Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	// Public functions
	void move(const float dirX, const float dirY);
	const bool canAttacK();

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};

