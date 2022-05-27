#pragma once
#include "GameState.h"
#include "Button.h"

class MainMenuState : public State
{
private:
    // Variables
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*> buttons;

    // Private functions
    void initFonts();
    void initButtons();

public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenuState();

    // Public functions
    void endState();

    void updateKeybinds(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
    void renderButtons(sf::RenderTarget* target = nullptr);
};

