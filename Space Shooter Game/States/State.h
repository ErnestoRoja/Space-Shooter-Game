#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<map>
#include<vector>

class State
{
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::vector<sf::Texture*> textures;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;

	// Pure virtual functions
	virtual void checkForQuit();
	virtual void endState() = 0;
	virtual void updateMousePositions();

	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};