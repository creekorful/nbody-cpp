#include "MainMenuState.h"

void MainMenuState::initialize()
{
    // Load font
    getEngine()->fontManager().loadFont("Fonts/Arial.ttf");
    if (!m_arialFont.loadFromFile("Fonts/Arial.ttf"))
    {
        std::cerr << "Unable to load font" << std::endl;
        exit(-1);
    }

    // Get window size
    sf::Vector2u screenSize = getEngine()->screenSize();

    // Initialize menu
    m_menu.setDefaultColor(sf::Color::Yellow);
    m_menu.setHighlightColor(sf::Color::Red);
    m_menu.setItems({"Play", "Editor", "Quit"}, m_arialFont);
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
    if (itemName == "Play")
    {

    }

    else if (itemName == "Editor")
    {

    }

    else if (itemName == "Quit")
    {
        getEngine()->quit();
    }
}

void MainMenuState::onMenuItemHovered(const std::string& itemName)
{
}
