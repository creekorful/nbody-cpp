#include "EditorState.h"

std::string EditorState::title()
{
    return "System editor";
}

void EditorState::initialize()
{
}

void EditorState::pollEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            getEngine()->setCurrentState(&MainMenuState::instance());
        }
    }

    GameState::pollEvent(event);
}
