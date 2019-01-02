#include "Application.h"

Application::Application(int argc, char** argv) : m_window(sf::VideoMode(1440, 900), "N-Body C++")
{
    // set digits precision to 2 decimals
    //std::cout << std::scientific << std::setprecision(2);
    std::cout << std::fixed << std::setprecision(3);

    // build offset to allow center of screen to be {0, 0} coordinates
    m_centerOffset = sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 2);
}

int Application::execute()
{
    // Instantiate system
    System system({Body("Sun", 1.98892 * std::pow(10, 30), {}, {}, sf::Color::Yellow),
                   Body("Earth", 5.9742 * std::pow(10, 24), {-1 * AU, 0}, {0, 29.783 * 1000}, sf::Color::Blue),
                   Body("Venus", 4.8685 * std::pow(10, 24), {0.723 * AU, 0}, {0, -35.02 * 1000}, sf::Color::Magenta)});

    // Render loop
    while (m_window.isOpen())
    {
        // Poll events from window
        sf::Event event{};

        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                m_window.close();
            }

        }

        // Perform system simulation
        system.simulate();

        // render bodies on the screen / window
        for (const Body& body : system.bodies())
        {
            sf::CircleShape shape(10.f); // todo radius based on body infos
            shape.setFillColor(body.color());
            shape.setPosition(sf::Vector2f(static_cast<float>(body.position().x * SCALE),
                                           static_cast<float>(body.position().y * SCALE)));
            // offset position to set 0,0 at middle screen pos
            shape.setPosition(shape.getPosition() + m_centerOffset);

            m_window.draw(shape);
        }

        // render everything on the screen
        m_window.display();
    }

    return 0;
}
