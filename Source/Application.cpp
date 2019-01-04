#include "Application.h"

Application::Application(int argc, char** argv) : m_window(sf::VideoMode::getDesktopMode(), "N-Body C++",
                                                           sf::Style::Fullscreen)
{
    // set digits precision to 2 decimals
    //std::cout << std::scientific << std::setprecision(2);
    std::cout << std::fixed << std::setprecision(3);

    // build offset to allow center of screen to be {0, 0} coordinates
    m_centerOffset = sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 2);

    m_showTrace = true;
    m_scale = 150;
}

Application::~Application()
{
    delete m_pSystem;
}

int Application::execute()
{
    // Instantiate system
    m_pSystem = new System(loadBodies());

    // create initial shapes in map
    for (const Body& body: m_pSystem->bodies())
    {
        sf::CircleShape shape(10.f); // todo use body radius & scale
        shape.setFillColor(body.color());
        shape.setOrigin(shape.getRadius(), shape.getRadius());
        m_shapes[body.name()] = shape;
    }

    // Render loop
    while (m_window.isOpen())
    {
        // Poll events from window
        sf::Event event{};

        while (m_window.pollEvent(event))
        {
            pollEvent(event);
        }

        if (!m_showTrace)
        {
            m_window.clear(sf::Color::Black);
        }

        // Perform system simulation
        m_pSystem->simulate();

        // render bodies on the screen / window
        for (const Body& body : m_pSystem->bodies())
        {
            sf::CircleShape* pShape = &m_shapes[body.name()];
            sf::Vector2f screenPosition(static_cast<float>(body.position().x * (m_scale / AU)),
                                        static_cast<float>(body.position().y * (m_scale / AU)));
            pShape->setPosition(screenPosition + m_centerOffset);

            m_window.draw(*pShape);
        }

        // render everything on the screen
        m_window.display();
    }

    return 0;
}

std::vector<Body> Application::loadBodies()
{
    BodiesLoader* pLoader = new BodiesLoader("bodies.config");

    if (!pLoader->isOpen())
    {
        delete pLoader;
        std::cerr << "Unable to open bodies.config" << std::endl;
        exit(-1);
    }

    std::vector<Body> bodies = pLoader->loadBodies();
    delete pLoader;
    return bodies;
}

void Application::pollEvent(const sf::Event& event)
{
    if (event.type == sf::Event::Closed ||
        (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        m_window.close();
    }

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::T)
            m_showTrace = !m_showTrace;
        if (event.key.code == sf::Keyboard::Add)
            m_pSystem->setTimestep(m_pSystem->timestep() + 3600);
        if (event.key.code == sf::Keyboard::Subtract)
            m_pSystem->setTimestep(m_pSystem->timestep() - 3600);
        if (event.key.code == sf::Keyboard::PageUp)
            m_scale--;
        if (event.key.code == sf::Keyboard::PageDown)
            m_scale++;
    }
}
