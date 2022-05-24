#pragma once
#include<SFML/Graphics.hpp>

class Asteroid
{
private:
	sf::CircleShape asteroid;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	// Private functions
	void initShape();
	void initVariables();

public:
	Asteroid(float pos_x, float pos_y);
	virtual ~Asteroid();

	// Accessors
	const sf::FloatRect getBounds() const;

	// Public functions
	void update();
	void render(sf::RenderTarget* target);
};

