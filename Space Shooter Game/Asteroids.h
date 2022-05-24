#pragma once
#include<SFML/Graphics.hpp>

class Asteroid
{
private:
	unsigned int pointReward;
	sf::CircleShape asteroid;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	// Private functions
	void initVariables();
	void initShape();


public:
	Asteroid(float pos_x, float pos_y);
	virtual ~Asteroid();

	// Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;

	// Public functions
	void update();
	void render(sf::RenderTarget* target);
};

