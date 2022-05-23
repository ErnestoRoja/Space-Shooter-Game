#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>


class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;


	// Private functions
	void initTexture();
	void initSprite();

public:
	Player();
	virtual ~Player();

	// Functions
	void move(const float dirX, const float dirY);

	void update();
	void render(sf::RenderTarget& target);
};

