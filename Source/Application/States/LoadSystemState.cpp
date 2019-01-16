#include "LoadSystemState.h"
#include "SimulationState.h"

std::string LoadSystemState::title()
{
    return "Load system";
}

void LoadSystemState::initialize()
{
    std::vector<std::string> menuEntries;

    // Build menu entries
    ma::Filesystem::Directory systemDirectory("./Systems");
    for (const auto& systemFile : systemDirectory.fileEntries("bodies"))
    {
        menuEntries.push_back(systemFile.fileName());
        m_systemFiles[systemFile.fileName()] = systemFile;
    }

    // Add entry to go back
    menuEntries.emplace_back(BACK);

    // Get window size
    sf::Vector2u screenSize = getEngine()->screenSize();

    // Initialize menu
    m_saveMenu.setDefaultColor(sf::Color::Yellow);
    m_saveMenu.setHighlightColor(sf::Color::Red);
    m_saveMenu.setItems(menuEntries, getEngine()->fontManager().getFont("Arial"));
    m_saveMenu.setPosition(screenSize.x / 2, screenSize.y / 2);
    m_saveMenu.setCallback(this);
    add(&m_saveMenu);
}

void LoadSystemState::onMenuItemSelected(const std::string& itemName)
{
    if (itemName == BACK)
    {
        getEngine()->setCurrentState(&MainMenuState::instance());
    }

    // If item name is not back it's a save name
    else
    {
        System system = loadSystem(m_systemFiles[itemName]);

        auto pState = new SimulationState();
        getEngine()->setCurrentState(pState);
        pState->initialize(system);
    }
}

void LoadSystemState::onMenuItemHovered(const std::string& itemName)
{
}

System LoadSystemState::loadSystem(ma::Filesystem::File file)
{
    if (file.open(ma::Filesystem::ReadOnly))
    {
        return System(BodiesLoader::loadBodies(file.readString()));
    }
    else
    {
        std::cerr << "Unable to open " << file.filePath() << std::endl;
        exit(-1);
    }
}
