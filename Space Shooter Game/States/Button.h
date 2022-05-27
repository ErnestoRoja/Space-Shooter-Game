#pragma once
#include <SFML/Graphics.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x_pos, float y_pos, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	virtual ~Button();

	// Accessors
	const bool isPressed() const;

	// Public functions
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

