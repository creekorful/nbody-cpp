#include "LoadSystemState.h"
#include "SimulationState.h"

std::string LoadSystemState::title()
{
    return "Load system";
}

void LoadSystemState::initialize()
{
    // todo really read bodies by regex / std::filesystem or anything
    std::vector<std::string> saves = {"solar-system.bodies", "something.bodies", "burak.bodies"};

    // Add entry to go back
    saves.emplace_back("Back");

    // Get window size
    sf::Vector2u screenSize = getEngine()->screenSize();

    // Initialize menu
    m_saveMenu.setDefaultColor(sf::Color::Yellow);
    m_saveMenu.setHighlightColor(sf::Color::Red);
    m_saveMenu.setItems(saves, getEngine()->fontManager().getFont("Arial"));
    m_saveMenu.setPosition(screenSize.x / 2, screenSize.y / 2);
    m_saveMenu.setCallback(this);
    add(&m_saveMenu);
}

void LoadSystemState::onMenuItemSelected(const std::string& itemName)
{
    if (itemName == "Back")
    {
        getEngine()->setCurrentState(&MainMenuState::instance());
    }

    // If item name is not back it's a save name
    else
    {
        System system = loadSystem(itemName);

        auto pState = new SimulationState();
        getEngine()->setCurrentState(pState);
        pState->initialize(system);
    }
}

void LoadSystemState::onMenuItemHovered(const std::string& itemName)
{
}

System LoadSystemState::loadSystem(const std::string& fileName)
{
    BodiesLoader loader("Systems/" + fileName);

    if (!loader.isOpen())
    {
        std::cerr << "Unable to open " << fileName << std::endl;
        exit(-1);
    }

    return System(loader.loadBodies());
}
