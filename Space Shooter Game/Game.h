#pragma once
#include<string>
#include<sstream>
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
	sf::Text gameOverText;

	// Background
	sf::Texture backgroundTexture;
	sf::Sprite background;

	// Point system
	unsigned int points;

	// Player
	Player* player;

	// Player GUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBackground;

	// Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Asteroid*> asteroids;

	// Private functions
	void initWindow();
	void initTextures();
	void initGUI();
	void initBackground();
	void initPoints();
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
	void updateBackground();
	void updateCollision();
	void updateBullets();
	void updateAsteroids();
	void updateCombat();
	void update();
	void renderGUI();
	void renderBackground();
	void render();
};


