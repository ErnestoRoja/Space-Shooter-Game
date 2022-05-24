#pragma once
#include"Player.h"
#include"Asteroids.h"

#include<map>

class Game
{
private:
	// Window
	sf::RenderWindow* window;

	// Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Gun*> bullets;

	// GUI
	sf::Font font;
	sf::Text pointText;

	// Player
	Player* player;

	// Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Asteroid*> asteroids;

	// Private functions
	void initWindow();
	void initTextures();
	void initGUI();
	void initPlayer();
	void initAsteroids();

public:
	Game();
	virtual ~Game();

	// Functions
	void run();

	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateBullets();
	void updateAsteroids();
	void update();
	void renderGUI();
	void render();
};


