#include <utility>

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

void SimulationState::initialize(System system)
{
    m_system = std::move(system);

    // create initial game objects in map
    for (const Body& body: m_system.bodies())
    {
        m_bodiesGameObjects[body.name()] = new BodyGameObject(body.name(), 10.f, body.color());

        // And add game objects to the state
        add(m_bodiesGameObjects[body.name()]);
    }
}

void SimulationState::update(float dt)
{
    // Perform system simulation
    m_system.simulate();

    // Update GUI according to simulation status
    m_timeDetails.setText(formatTime(m_system.elapsedTime()));

    // Update game object according to simulation results
    for (const Body& body : m_system.bodies())
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
            m_system.setTimestep(m_system.timestep() + 3600);
        if (event.key.code == sf::Keyboard::Subtract)
            m_system.setTimestep(m_system.timestep() - 3600);
        if (event.key.code == sf::Keyboard::PageUp)
            m_scale--;
        if (event.key.code == sf::Keyboard::PageDown)
            m_scale++;
    }

    GameState::pollEvent(event);
}

std::string SimulationState::formatTime(double time) const
{
    return std::to_string(time / (24*3600)) + "days"; // todo better format
}
