#include "MainMenuState.h"

void MainMenuState::initialize()
{
    // Load font
    getEngine()->fontManager().loadFont("Fonts/Arial.ttf");
    m_arialFont = getEngine()->fontManager().getFont("Arial");

    // Get window size
    sf::Vector2u screenSize = getEngine()->screenSize();

    // Initialize menu
    m_menu.setDefaultColor(sf::Color::Yellow);
    m_menu.setHighlightColor(sf::Color::Red);
    m_menu.setItems({PLAY_SIMULATION, SIMULATION_EDITOR, QUIT}, m_arialFont);
    m_menu.setPosition(screenSize.x / 2, screenSize.y / 2);
    m_menu.setCallback(this);
    add(&m_menu);
}

std::string MainMenuState::title()
{
    return "MainMenu - [N-Body C++]";
}

void MainMenuState::pollEvent(const sf::Event& event)
{
    GameState::pollEvent(event);

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        getEngine()->quit();
    }
}

void MainMenuState::onMenuItemSelected(const std::string& itemName)
{
    if (itemName == PLAY_SIMULATION)
    {

    }

    else if (itemName == SIMULATION_EDITOR)
    {

    }

    else if (itemName == QUIT)
    {
        getEngine()->quit();
    }
}

void MainMenuState::onMenuItemHovered(const std::string& itemName)
{
}
