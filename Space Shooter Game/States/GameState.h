#pragma once
#include "State.h"

class GameState : public State
{
private:

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    // Public functions
    void endState();

    void updateKeybinds(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};

