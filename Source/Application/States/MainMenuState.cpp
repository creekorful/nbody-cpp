#include "MainMenuState.h"

void MainMenuState::initialize()
{
    // Load font
    if (!m_arialFont.loadFromFile("Fonts/Arial.ttf"))
    {
        std::cerr << "Unable to load font" << std::endl;
        exit(-1);
    }

    // Get window size

    // Initialize texts
    m_playText.setFont(m_arialFont);
    m_playText.setString("Play");
    m_playText.setFillColor(sf::Color::Yellow);
    m_playText.setPosition(100, 100);

    m_editorText.setFont(m_arialFont);
    m_editorText.setString("Editor");
    m_editorText.setFillColor(sf::Color::Yellow);
    m_editorText.setPosition(100, 200);

    m_quitText.setFont(m_arialFont);
    m_quitText.setString("Quit");
    m_quitText.setFillColor(sf::Color::Yellow);
    m_quitText.setPosition(100, 300);
}

std::string MainMenuState::title()
{
    return "MainMenu - [N-Body C++]";
}

void MainMenuState::update(float dt)
{
}

void MainMenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_playText, states);
    target.draw(m_editorText, states);
    target.draw(m_quitText, states);
}

void MainMenuState::pollEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        getEngine()->quit();
    }
}
