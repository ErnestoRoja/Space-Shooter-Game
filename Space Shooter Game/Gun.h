#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Gun
{
private:
	sf::Sprite bullet;

	sf::Vector2f direction;
	float movementSpeed;

public:
	Gun();
	Gun(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	virtual ~Gun();

	// Accessor
	const sf::FloatRect getBounds() const;

	// Functions
	void update();
	void render(sf::RenderTarget* target);
};

