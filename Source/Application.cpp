#include "Application.h"

Application::Application(int argc, char** argv) : m_window(sf::VideoMode(1440, 900), "N-Body C++")
{
    // set digits precision to 2 decimals
    //std::cout << std::scientific << std::setprecision(2);
    std::cout << std::fixed << std::setprecision(3);
}

int Application::execute()
{
    // Instantiate systems
    System system({Body("Sun", 1.98892 * std::pow(10, 30), {}, {}),
                   Body("Earth", 5.9742 * std::pow(10, 24), {-1 * AU, 0}, {0, 29.783 * 1000}),
                   Body("Venus", 4.8685 * std::pow(10, 24), {0.723 * AU, 0}, {0, -35.02 * 1000})});

    // Render loop
    while (m_window.isOpen())
    {
        // Poll events from window
        sf::Event event{};

        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        // Perform system simulation
        system.simulate();

        // render everything on the screen
        m_window.display();
    }

    return 0;
}
