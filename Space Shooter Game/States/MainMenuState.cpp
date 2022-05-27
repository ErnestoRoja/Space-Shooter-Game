#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/wence.otf"))
	{
		std::cout << "ERROR::MAINMENUSTATE::INITFONTS::Could not load main menu font." << std::endl;
	}
}

void MainMenuState::initButtons()
{
	this->buttons["PLAY_BUTTON"] = new Button(100, 100, 150, 50, &this->font, "Play", sf::Color::Blue, sf::Color::Red, sf::Color::Green);

	this->buttons["CONTROLS_BUTTON"] = new Button(100, 300, 150, 50, &this->font, "Controls", sf::Color::Blue, sf::Color::Red, sf::Color::Green);

	this->buttons["EXIT_BUTTON"] = new Button(100, 500, 150, 50, &this->font, "Exit", sf::Color::Blue, sf::Color::Red, sf::Color::Green);
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	this->initFonts();
	this->initButtons();
	

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::endState()
{
	std::cout << "Ending main menu state" << std::endl;
}

void MainMenuState::updateKeybinds(const float& dt)
{

}

void MainMenuState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	// New game
	if (this->buttons["PLAY_BUTTON"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->states));
	}

	// Quit the game
	if (this->buttons["EXIT_BUTTON"]->isPressed())
	{
		this->quit = true;
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateButtons();

}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

