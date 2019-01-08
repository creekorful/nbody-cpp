#include "SimulationState.h"
#include "MainMenuState.h"

std::string SimulationState::title()
{
    return "Simulation";
}

void SimulationState::initialize()
{
    sf::Vector2u screenSize = getEngine()->screenSize();
    m_centerOffset = sf::Vector2f(screenSize.x / 2, screenSize.y / 2);

    // create GUI
    sf::Font& font = getEngine()->fontManager().getFont("Arial");
    m_timeDetails.setFont(font);
    m_timeDetails.setPosition(sf::Vector2f(150, 150));
    m_timeDetails.setText("Hello world :D");

    add(&m_timeDetails);

    m_scale = 150;
}

void SimulationState::initialize(System* pSystem)
{
    m_pSystem = pSystem;

    // create initial game objects in map
    for (const Body& body: m_pSystem->bodies())
    {
        m_bodiesGameObjects[body.name()] = new BodyGameObject(body.name(), 10.f, body.color());

        // And add game objects to the state
        add(m_bodiesGameObjects[body.name()]);
    }
}

void SimulationState::update(float dt)
{
    // Perform system simulation
    m_pSystem->simulate();

    // Update game object according to simulation results
    for (const Body& body : m_pSystem->bodies())
    {
        BodyGameObject* pBodyGameObject = m_bodiesGameObjects[body.name()];
        sf::Vector2f screenPosition(static_cast<float>(body.position().x * (m_scale / AU)),
                                    static_cast<float>(body.position().y * (m_scale / AU)));
        pBodyGameObject->setPosition(screenPosition + m_centerOffset);
    }

    GameState::update(dt);
}

void SimulationState::pollEvent(const sf::Event& event)
{
    // if we press escape return to main menu todo show pause menu?
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            getEngine()->setCurrentState(&MainMenuState::instance());
        }

        /*if (event.key.code == sf::Keyboard::T)
            m_showTrace = !m_showTrace;*/
        if (event.key.code == sf::Keyboard::Add)
            m_pSystem->setTimestep(m_pSystem->timestep() + 3600);
        if (event.key.code == sf::Keyboard::Subtract)
            m_pSystem->setTimestep(m_pSystem->timestep() - 3600);
        if (event.key.code == sf::Keyboard::PageUp)
            m_scale--;
        if (event.key.code == sf::Keyboard::PageDown)
            m_scale++;
    }

    GameState::pollEvent(event);
}

void SimulationState::reinitialize()
{
    GameState::reinitialize();

    // Delete game objects map
    for (auto entry : m_bodiesGameObjects)
    {
        delete entry.second;
    }
    m_bodiesGameObjects.clear();

    delete m_pSystem;
}

bool SimulationState::shouldReinitialize()
{
    return true;
}
