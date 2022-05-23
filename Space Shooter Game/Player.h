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

	// Accessor
	const sf::Vector2f& getPos() const;

	// Functions
	void move(const float dirX, const float dirY);
	const bool canAttacK();

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};

